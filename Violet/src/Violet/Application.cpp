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
			glClearColor(0.5f, 0.0f, 0.7f, 1.0f); // VIOLET
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : layerStack_) layer->OnUpdate(); // Iteration across all layers from the application stack for update

			window_->OnUpdate();
		}
	}

	bool Application::OnWindowCloseEvent(WindowCloseEvent& e) {
		running_ = false;
		return true;
	}
}