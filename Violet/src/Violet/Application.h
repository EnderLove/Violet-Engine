#pragma once

#include "Core.h"

 namespace Violet {
	class VIOLET_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// TO BE DEFINE IN CLIENT
	Application* CreateApplication();
}

