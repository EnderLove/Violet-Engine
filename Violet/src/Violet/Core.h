#pragma once

#ifdef VIOLET_PLATFORM_WINDOWS
	#ifdef VIOLET_BUILD_DLL
		#define VIOLET_API __declspec(dllexport)
	#else 
		#define VIOLET_API __declspec(dllimport)
	#endif
#elif defined(VIOLET_PLATFORM_LINUX) // TODO: NOT CURRENTLY AVALIABLE (FIX!)
	#define VIOLET_API __attribute__((visibility("default")))
#else
	#error Violet only support Windows and Linux!
#endif

#ifdef VT_ENABLE_ASSERTS
	#define VT_ASSERT(x, ...)      { if(!(x)) { VT_ERROR     ("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define VT_CORE_ASSERT(x, ...) { if(!(x)) { VT_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else 
	#define VT_ASSERT(x, ...)
	#define VT_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

// This BIND macro solves the problem with the ghost paramenter 'this' that lives inside class methods
// OnEvent(Application::this*, Event& e)
//#define VT_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1) // std::bind version
#define VT_BIND_EVENT_FN(fn) [this](auto&& e) { return fn(e); }				 // lambda version (optimal?)