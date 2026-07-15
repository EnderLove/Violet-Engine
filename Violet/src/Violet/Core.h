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

#define BIT(x) (1 << x)