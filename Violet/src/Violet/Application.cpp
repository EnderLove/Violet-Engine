#include "vtpch.h"

#include "Application.h"
//#include "Events/ApplicationEvent.h"
#include "Events/MouseEvent.h"
#include "Log.h"

#include "Input.h"

//#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Violet {
	Application* Application::Instance_ = nullptr;

	Application::Application() {
		VT_CORE_ASSERT(!Instance_, "Application already exists!");
		Instance_ = this;
		window_ = std::unique_ptr<Window>(Window::Create()); // Why the cast?
		window_->SetEventCallback(VT_BIND_EVENT_FN(Application::OnEvent)); // Working with labmda version

		ImGuiLayer_ = new ImGuiLayer();
		PushOverlay(ImGuiLayer_);
		
		glGenVertexArrays(1, &VAO_);
		glBindVertexArray(VAO_);
		glEnableVertexAttribArray(0);
		
		glGenBuffers(1, &VBO_);
		glBindBuffer(GL_ARRAY_BUFFER, VBO_);
		
		glGenBuffers(1, &IBO_);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO_);

		float vertices[9] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.0f,  0.5f, 0.0f
		};

		unsigned int indices[3] = { 0, 1, 2 };
		
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		
		
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		std::string vertexSource = R"(
			#version 330 core

			layout(location = 0) in vec3 aPos;

			out vec3 vColor;

			void main(){
				gl_Position = vec4(aPos, 1.0);
				vColor = aPos + vec3(0.5);
			}	
		)";

		std::string fragmentSource = R"(
			#version 330 core

			layout(location = 0) out vec4 aColor;

			in vec3 vColor;			

			void main(){
				aColor = vec4(vColor, 1.0);
			}	
		)";

		shader_ = new Shader(vertexSource, fragmentSource);
	}

	Application::~Application() {}

	void Application::PushLayer(Layer* layer)   { 
		layerStack_.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* overlay) { 
		layerStack_.PushOverlay(overlay);
		overlay->OnAttach();
	}

	void Application::OnEvent(Event& e) { // This will be called by the window data_ 
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(VT_BIND_EVENT_FN(Application::OnWindowCloseEvent));

		for (auto it = layerStack_.end(); it != layerStack_.begin(); ) {
			(*--it)->OnEvent(e);
			if (e.handled_) break;
		}
	}

	void Application::Run() {
		while (running_) {
			glClearColor(0.2f, 0.2f, 0.2f, 1.0f); // VIOLET
			glClear(GL_COLOR_BUFFER_BIT);

			shader_->Bind();
			glBindVertexArray(VAO_);
			glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);

			ImGuiLayer_->Begin();
			for (Layer* layer : layerStack_) layer->OnImGuiRender(); // Iteration across all layers from the application stack for update
			ImGuiLayer_->End();

			window_->OnUpdate();
		}
	}

	bool Application::OnWindowCloseEvent(WindowCloseEvent& e) {
		running_ = false;
		return true;
	}
}