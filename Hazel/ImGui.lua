project "ImGui"
	kind "StaticLib"
	language "C++"

	targetdir(bindir)
	objdir(objectdir)

	files {
		"src/vendor/imgui/*.h",
		"src/vendor/imgui/*.cpp"
	}

	filter "system:windows"
		systemversion "latest"
		cppdialect "C++17"
		staticruntime "On"

	filter "system:linux"
		pic "On"
		systemversion "latest"
		cppdialect "C++17"
		staticruntime "On"

	filter "configurations:Debug"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		runtime "Release"
		optimize "On"