#include "vtpch.h"

#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Events/MouseEvent.h"
#include "Log.h"


namespace Violet {
	Application::Application() {}
	Application::~Application() {}

	void Application::Run() {
		WindowResizeEvent e(1980, 720);
		MouseMovedEvent a(10, 20);
		VT_TRACE(e);
		VT_TRACE(a);
		while (true);
	}
}