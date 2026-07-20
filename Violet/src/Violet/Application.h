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

		inline static Application& Get() { return *Instance_; }
		inline Window& GetWindow() { return *window_; }

	private:
		std::unique_ptr<Window> window_;
		bool running_ = true;

		bool OnWindowClose(WindowCloseEvent& e);

		LayerStack layerStack_;

	private:
		static Application* Instance_; // SINGLETON
	};

	// TO BE DEFINE IN CLIENT
	Application* CreateApplication();
}

