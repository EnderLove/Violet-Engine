#pragma once

#ifdef VIOLET_PLATFORM_WINDOWS

extern Violet::Application* Violet::CreateApplication();

int main(int argc, char** argv) {
	auto app = Violet::CreateApplication();
	app->Run();
	delete app;
}

#endif
