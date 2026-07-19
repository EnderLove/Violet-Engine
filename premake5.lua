workspace "Violet"

	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"]  = "Violet/vendor/GLFW/include"
IncludeDir["GLAD"]  = "Violet/vendor/GLAD/include"
IncludeDir["ImGui"] = "Violet/vendor/imgui/include"

include "Violet/vendor/GLFW"
include "Violet/vendor/GLAD"
include "Violet/vendor/imgui"

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
		"%{IncludeDir.ImGui}"
	}

	links {
		"GLFW",
		"GLAD",
		"ImGui",
		"opengl32.lib" 
	}

-- ======================================== WINDOWS SYSTEM ========================================
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On" 
		systemversion "latest"

		buildoptions { "/utf-8" }

		defines {
			"VIOLET_PLATFORM_WINDOWS",
			"VIOLET_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputDir .. "/Sandbox")
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
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "VT_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "VT_DIST"
		buildoptions "/MD"
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
		"Violet/src"
	}

	links {
		"Violet"
	}

-- ======================================== WINDOWS SYSTEM ========================================
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On" 
		systemversion "latest"

		buildoptions { "/utf-8" }

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
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "VT_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "VT_DIST"
		buildoptions "/MD"
		optimize "On"