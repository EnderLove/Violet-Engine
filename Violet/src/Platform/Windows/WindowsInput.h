#pragma once

#include "Violet/Input.h"

namespace Violet {
	// THIS WILL NOT GO TO THE CLIENT (FOR NOW...)
	class WindowsInput : public Input {   
	protected:
		virtual bool IsKeyPressedImpl(int keyCode) override;
		virtual bool IsMouseButtonPressedImpl(int button) override;
		virtual std::pair<double, double> GetMousePositionImpl() override;
		virtual float GetMouseXImpl() override;
		virtual float GetMouseYImpl() override;
	};

}