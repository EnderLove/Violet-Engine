#pragma once

#include "Core.h"

namespace Violet {
	class VIOLET_API Input {
	public:
		inline static bool IsKeyPressed(int keyCode) { return instance_->IsKeyPressedImpl(keyCode); }
		inline static bool IsMouseButtonPressed(int button) { return instance_->IsMouseButtonPressedImpl(button); }
		inline static std::pair<double, double> GetMousePosition() { return instance_->GetMousePositionImpl(); }
		inline static float GetMouseX() { return instance_->GetMouseXImpl(); }
		inline static float GetMouseY() { return instance_->GetMouseYImpl(); }

	protected:
		virtual bool IsKeyPressedImpl(int keyCode) = 0;
		virtual bool IsMouseButtonPressedImpl(int button) = 0;
		virtual std::pair<double, double> GetMousePositionImpl() = 0;
		virtual float GetMouseXImpl() = 0;
		virtual float GetMouseYImpl() = 0;

	private:
		static Input* instance_;
	};
}