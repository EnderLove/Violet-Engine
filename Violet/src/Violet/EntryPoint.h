#pragma once

#ifdef VIOLET_PLATFORM_WINDOWS

extern Violet::Application* Violet::CreateApplication();

int main(int argc, char** argv) {
	Violet::Log::Init();
	VT_CORE_WARN("Initialize Log!");

	int a = 10;
	VT_INFO("HELLO LOG GAAAAAAAAAAA! Var={0}", a);

	auto app = Violet::CreateApplication();
	app->Run();
	delete app;
}

#endif
