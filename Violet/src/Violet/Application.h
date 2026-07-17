#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"
#include "Events/ApplicationEvent.h" // need vtpch.h (Window.h)

 namespace Violet {
	class VIOLET_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e); // This is what will happen with a certain event

	private:
		std::unique_ptr<Window> window_;
		bool running_ = true;

		bool OnWindowClose(WindowCloseEvent& e);
	};

	// TO BE DEFINE IN CLIENT
	Application* CreateApplication();
}

