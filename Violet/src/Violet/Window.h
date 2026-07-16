#pragma once

#include "vtpch.h"

#include "Violet/Core.h"
#include "Violet/Events/Event.h"

namespace Violet {
	struct WindowProps {
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string Title = "Violet Engine", unsigned int Width = 1920, unsigned int Height = 1080) :
			Title(Title), Width(Width), Height(Height){ }
	};

	class VIOLET_API Window {
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth()  = 0;
		virtual unsigned int GetHeight() = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enable) = 0;
		virtual bool IsVSync() = 0;
		
		static Window* Create(const WindowProps & = WindowProps());
	};
}