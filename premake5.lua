workspace "Violet"

	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Violet"
	location "Violet"
	kind     "SharedLib" -- DLL
	language "C++"

	buildoptions { "/utf-8" }

	targetdir ("bin/"     .. outputDir .. "/%{prj.name}")
	objdir    ("bin-int/" .. outputDir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On" 
		systemversion "latest"

		defines {
			"VIOLET_PLATFORM_WINDOWS",
			"VIOLET_BUILD_DLL"
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputDir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "VT_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "VT_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "VT_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind     "ConsoleApp" -- EXE
	language "C++"

	buildoptions { "/utf-8" }

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

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On" 
		systemversion "latest"

		defines {
			"VIOLET_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "VT_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "VT_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "VT_DIST"
		optimize "On"