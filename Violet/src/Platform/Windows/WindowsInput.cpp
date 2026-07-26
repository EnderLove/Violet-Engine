#include "vtpch.h" // (VIOLET PRE COMPILED HEADER)

#include <GLFW/glfw3.h>

#include "Violet/Application.h"
#include "WindowsInput.h"

namespace Violet {
	Input* Input::instance_ = new(WindowsInput);

	bool WindowsInput::IsKeyPressedImpl(int keyCode) {
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		int state = glfwGetKey(window, keyCode);

		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool WindowsInput::IsMouseButtonPressedImpl(int button) {
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		int state = glfwGetMouseButton(window, button);

		return state == GLFW_PRESS;
	}

	std::pair<double, double> WindowsInput::GetMousePositionImpl() {
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		return { xpos, ypos };
	}

	float WindowsInput::GetMouseXImpl() {
		auto [x, y] = GetMousePositionImpl(); // C++ 17 feature
		return x;
	}

	float WindowsInput::GetMouseYImpl() {
		auto [x, y] = GetMousePositionImpl(); // C++ 17 feature
		return y;
	}
}