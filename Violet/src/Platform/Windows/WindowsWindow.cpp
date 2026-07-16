#include "vtpch.h"
#include "WindowsWindow.h"

namespace Violet {
	static bool GLFWInitialized = false;

	Window* Window::Create(const WindowProps& props) { return new WindowsWindow(props); }

	WindowsWindow::WindowsWindow(const WindowProps& props) { Init(props); }

	WindowsWindow::~WindowsWindow() { Shutdown(); }

	void WindowsWindow::Init(const WindowProps& props) {
		data_.Title  = props.Title;
		data_.Width  = props.Width;
		data_.Height = props.Height;

		VT_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		if (!GLFWInitialized) {
			int success = glfwInit();
			VT_CORE_ASSERT(success, "Could not initialized GLFW!");
			GLFWInitialized = true;
		}

		window_ = glfwCreateWindow((int)props.Width, (int)props.Height, data_.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(window_);
		glfwSetWindowUserPointer(window_, &data_);
		SetVSync(true);
	}

	void WindowsWindow::Shutdown() { glfwDestroyWindow(window_); }

	void WindowsWindow::OnUpdate() {
		glfwPollEvents();
		glfwSwapBuffers(window_);
	}

	void WindowsWindow::SetVSync(bool enable) {
		if (enable) glfwSwapInterval(1);
		else glfwSwapInterval(0);

		data_.VSync = enable;
	}

	bool WindowsWindow::IsVSync() const { return data_.VSync; }
}