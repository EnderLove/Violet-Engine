#pragma once
#include "vtpch.h"
#include "Violet/Layer.h"

#include "Violet/Events/ApplicationEvent.h"
#include "Violet/Events/MouseEvent.h"
#include "Violet/Events/KeyEvent.h"

namespace Violet {
	class VIOLET_API ImGuiLayer : public Layer {
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& event);

	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseScrolledEvent(MouseScrollEvent& e);
		bool OnKeyPressedEvent(KeyPressEvent& e);
		bool OnKeyReleasedEvent(KeyReleaseEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);
		bool OnWindowResizedEvent(WindowResizeEvent& e);

		int VioletKeyToImGuiKey(int keyCode); // TEMPORAL TRANSLATION FUNCTION

	private:
		float time_ = 0.0f;
	};
}