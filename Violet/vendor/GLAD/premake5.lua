project "GLAD"
	kind "StaticLib"
	language "C"
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
		staticruntime "On"

	filter { "system:windows", "configurations:Release" }
		runtime "Release"