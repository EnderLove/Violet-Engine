#pragma once

#ifdef VIOLET_PLATFORM_WINDOWS

extern Violet::Application* Violet::CreateApplication();

int main(int argc, char** argv) {
	Violet::Log::Init();
	auto app = Violet::CreateApplication(); // Violet::Application*
	app->Run();
	delete app;
}

#endif
