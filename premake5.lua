workspace "Violet"

	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

	startproject "Sandbox"

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"]  = "Violet/vendor/GLFW/include"
IncludeDir["GLAD"]  = "Violet/vendor/GLAD/include"
IncludeDir["ImGui"] = "Violet/vendor/imgui"
IncludeDir["glm"]   = "Violet/vendor/glm"

include "Violet/vendor/GLFW"
include "Violet/vendor/GLAD"
include "Violet/vendor/imgui"
--include "Violet/vendor/glm"

-- //////////////////////////////////////////////   VIOLET   ///////////////////////////////////////////////
project "Violet"
	location "Violet"
	kind     "SharedLib" -- DLL
	language "C++"

	targetdir ("bin/"     .. outputDir .. "/%{prj.name}")
	objdir    ("bin-int/" .. outputDir .. "/%{prj.name}")

	pchheader "vtpch.h"
	pchsource "Violet/src/vtpch.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.GLAD}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links {
		"GLFW",
		"GLAD",
		"ImGui",
		"opengl32",
		"gdi32"
	}

-- ======================================== WINDOWS SYSTEM ========================================
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On" 
		systemversion "latest"

		filter { "system:windows", "action:vs*" }
			buildoptions { "/utf-8" }

		filter "system:windows"
		defines {
			"VIOLET_PLATFORM_WINDOWS",
			"VIOLET_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputDir .. "/Sandbox/\"")
		}

-- ======================================== LINUX SYSTEM ========================================
	filter "system:linux"
        pic "On"
        cppdialect "C++17"
        staticruntime "On"

        defines {
            "VIOLET_PLATFORM_LINUX",
            "VIOLET_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
        }

        links { "pthread" } -- pthread lib to handle multi-threading (spdlog)

        postbuildcommands {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputDir .. "/Sandbox")
		}

-- ======================================== CONFIGURATIONS COMPILE ========================================
	filter "configurations:Debug"
		defines "VT_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "VT_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "VT_DIST"
		runtime "Release"
		optimize "On"

-- //////////////////////////////////////////////   SANDBOX   ///////////////////////////////////////////////
project "Sandbox"
	location "Sandbox"
	kind     "ConsoleApp" -- EXE
	language "C++"

	targetdir ("bin/"     .. outputDir .. "/%{prj.name}")
	objdir    ("bin-int/" .. outputDir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"Violet/vendor/spdlog/include",
		"Violet/vendor",
		"Violet/src",
		"%{IncludeDir.glm}"
	}

	links {
		"Violet"
	}

-- ======================================== WINDOWS SYSTEM ========================================
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On" 
		systemversion "latest"

		filter { "system:windows", "action:vs*" }
			buildoptions { "/utf-8" }

		filter "system:windows"
		defines {
			"VIOLET_PLATFORM_WINDOWS",
		}
		
-- ======================================== LINUX SYSTEM ========================================
	filter "system:linux"
        cppdialect "C++17"
        staticruntime "On" 

        defines {
            "VIOLET_PLATFORM_LINUX"
        }

-- ======================================== CONFIGURATIONS COMPILE ========================================
	filter "configurations:Debug"
		defines "VT_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "VT_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "VT_DIST"
		runtime "Release"
		optimize "On"