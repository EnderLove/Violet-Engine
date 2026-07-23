#include "vtpch.h"

#include "Application.h"
//#include "Events/ApplicationEvent.h"
#include "Events/MouseEvent.h"
#include "Log.h"

#include "Input.h"

//#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Violet {
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::Instance_ = nullptr;

	Application::Application() {
		VT_CORE_ASSERT(!Instance_, "Application already exists!");
		Instance_ = this;
		window_ = std::unique_ptr<Window>(Window::Create()); // Why the cast?
		window_->SetEventCallback(BIND_EVENT_FN(OnEvent)); // Loads the fn into the window data_ EventCallback
	}

	Application::~Application() {}

	void Application::PushLayer  (Layer* layer)   { 
		layerStack_.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* overlay) { 
		layerStack_.PushOverlay(overlay);
		overlay->OnAttach();
	}

	// OnEvent(Application::this*, Event& e) compiler pov (BIND_EVENT_FN manage the this*)
	void Application::OnEvent(Event& e) { // This will be called by the window data_ 
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
		//VT_CORE_INFO("{0}", e);

		for (auto it = layerStack_.end(); it != layerStack_.begin(); ) {
			(*--it)->OnEvent(e);
			if (e.handled_) break;
		}
	}

	void Application::Run() {
		while (running_) {
			glClearColor(0.5f, 0.0f, 1.0f, 1.0f); 
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : layerStack_) layer->OnUpdate();

			auto [x, y] = Input::GetMousePosition();
			VT_CORE_TRACE("{0}, {1}", x, y);

			window_->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e) {
		running_ = false;
		return true;
	}
}