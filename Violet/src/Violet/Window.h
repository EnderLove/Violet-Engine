#pragma once

#include "vtpch.h"

#include "Violet/Core.h"
#include "Violet/Events/Event.h"

namespace Violet {
	struct WindowProps {
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string Title = "Violet Engine", unsigned int Width = 1080, unsigned int Height = 720) :
			Title(Title), Width(Width), Height(Height){ }
	};

	class VIOLET_API Window {
	public:
		using EventCallbackFn = std::function<void(Event&)>; // void function that recieves a Event&

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth()  const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enable) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		static Window* Create(const WindowProps & = WindowProps());
	};
}