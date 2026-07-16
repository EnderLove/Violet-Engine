#pragma once

#ifdef VIOLET_PLATFORM_WINDOWS
	#ifdef VIOLET_BUILD_DLL
		#define VIOLET_API __declspec(dllexport)
	#else 
		#define VIOLET_API __declspec(dllimport)
	#endif
#elif defined(VIOLET_PLATFORM_LINUX)
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