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

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();

		int VioletKeyToImGuiKey(int keyCode); // TEMPORAL TRANSLATION FUNCTION

	private:
		float time_ = 0.0f;
	};
}