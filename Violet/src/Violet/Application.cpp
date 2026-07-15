#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Violet {
	Application::Application() {}
	Application::~Application() {}

	void Application::Run() {
		WindowResizeEvent e(1980, 720);
		VT_TRACE(e);
		while (true);
	}
}