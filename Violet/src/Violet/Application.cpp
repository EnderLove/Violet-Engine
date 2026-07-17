#include "vtpch.h"

#include "Application.h"
//#include "Events/ApplicationEvent.h"
#include "Events/MouseEvent.h"
#include "Log.h"

#include <GLFW/glfw3.h>

namespace Violet {
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application() {
		window_ = std::unique_ptr<Window>(Window::Create()); // Why the cast?
		window_->SetEventCallback(BIND_EVENT_FN(OnEvent)); // Loads the fn into the window data_ EventCallback
	}

	Application::~Application() {}

	// OnEvent(Application::this*, Event& e) compiler pov (BIND_EVENT_FN manage the this*)
	void Application::OnEvent(Event& e) { // This will be called by the window data_ 
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
		VT_CORE_INFO("{0}", e);
	}

	void Application::Run() {
		while (running_) {
			glClearColor(0.5f, 0.0f, 1.0f, 1.0f); 
			glClear(GL_COLOR_BUFFER_BIT);
			window_->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e) {
		running_ = false;
		return true;
	}
}