#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Violet {
	class VIOLET_API Log{
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger()   { return s_CoreLogger;   }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	};
}

// CORE LOG MACROS 
#define VT_CORE_TRACE(...)  ::Violet::Log::GetCoreLogger()->trace (__VA_ARGS__)
#define VT_CORE_INFO(...)   ::Violet::Log::GetCoreLogger()->info  (__VA_ARGS__)
#define VT_CORE_WARN(...)   ::Violet::Log::GetCoreLogger()->warn  (__VA_ARGS__)
#define VT_CORE_ERROR(...)  ::Violet::Log::GetCoreLogger()->error (__VA_ARGS__) 
//#define VT_CORE_FATAL(...)  ::Violet::Log::GetCoreLogger()->fatal (__VA_ARGS__) 
							
// CLIENT LOG MACROS		
#define VT_TRACE(...)       ::Violet::Log::GetClientLogger()->trace (__VA_ARGS__)
#define VT_INFO(...)        ::Violet::Log::GetClientLogger()->info  (__VA_ARGS__)
#define VT_WARN(...)        ::Violet::Log::GetClientLogger()->warn  (__VA_ARGS__)
#define VT_ERROR(...)       ::Violet::Log::GetClientLogger()->error (__VA_ARGS__) 
//#define VT_FATAL(...)       ::Violet::Log::GetCoreLogger()->fatal (__VA_ARGS__) 