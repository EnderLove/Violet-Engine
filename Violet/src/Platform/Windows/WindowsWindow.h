#pragma once

#include <GLFW/glfw3.h>
#include "Violet/Window.h"

namespace Violet {
	class WindowsWindow : public Window {
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth()  const override { return data_.Width;  }
		inline unsigned int GetHeight() const override { return data_.Height; }

		inline virtual void* GetNativeWindow() const override { return window_; }

		// Window attribs
		inline void SetEventCallback(const EventCallbackFn& callback) override { data_.EventCallback = callback; }
		void SetVSync(bool enable) override;
		bool IsVSync() const override;

	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

	private:
		GLFWwindow* window_;

		struct WindowData {
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};
		WindowData data_;
	};
}