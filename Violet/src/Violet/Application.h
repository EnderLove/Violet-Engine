#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"
#include "Events/ApplicationEvent.h" // need vtpch.h (Window.h)
#include "LayerStack.h"

#include "Renderer/Shader.h"
#include "Renderer/RenderBuffer.h"

#include "ImGui/ImGuiLayer.h"

 namespace Violet {
	class VIOLET_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e); // This is what will happen with a certain event

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline static Application& Get() { return *Instance_; } // Just to get the instance
		inline Window& GetWindow() { return *window_; } // This is not the native window, just return the ptr of the instanced window class

	private:
		std::unique_ptr<Window> window_;
		ImGuiLayer* ImGuiLayer_; // The layer stays raw... The stack will manage this :D

		bool running_ = true;

		bool OnWindowCloseEvent(WindowCloseEvent& e);

		LayerStack layerStack_;

		//Shader* shader_; // Unique looks better for ownership tbh
		std::unique_ptr<Shader>       shader_;
		std::unique_ptr<VertexBuffer> vertexBuffer_;
		std::unique_ptr<IndexBuffer>  indexBuffer_;

	private:
		static Application* Instance_; // SINGLETON

		unsigned int VAO_, IBO_, VBO_;
	};

	Application* CreateApplication(); // Defined in client (for entry point will be "extern")
}