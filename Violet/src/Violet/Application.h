#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"
#include "Events/ApplicationEvent.h" // need vtpch.h (Window.h)
#include "LayerStack.h"

 namespace Violet {
	class VIOLET_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e); // This is what will happen with a certain event

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

	private:
		std::unique_ptr<Window> window_;
		bool running_ = true;

		bool OnWindowClose(WindowCloseEvent& e);

		LayerStack layerStack_;
	};

	// TO BE DEFINE IN CLIENT
	Application* CreateApplication();
}

