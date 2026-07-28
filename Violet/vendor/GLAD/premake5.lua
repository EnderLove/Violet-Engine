project "GLAD"
	kind "StaticLib"
	language "C"
	staticruntime "On"
	location "%{wks.location}/Violet/vendor/GLAD"

	targetdir ("bin/"     .. outputDir .. "/%{prj.name}")
	objdir    ("bin-int/" .. outputDir .. "/%{prj.name}")

	files {
		"include/glad/glad.h",
		"include/KHR/khrplatform.h",
		"src/glad.c"
	}	

	includedirs {
		"include"
	}

	filter "system:windows"
		systemversion "latest"

	filter { "system:windows", "configurations:Debug" }
		runtime "Debug"
		symbols "on"

	filter { "system:windows", "configurations:Release" }
		runtime "Release"
		optimize "on"