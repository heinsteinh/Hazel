project "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "On"

    targetdir(bindir)
    objdir(objectdir)

    files {
        "src/**.h",
        "src/**.cpp"
    }

    includedirs {
        "src",
        "%{wks.location}/Hazel/src",
        "%{wks.location}/Hazel/src/vendor/spdlog/include",
        "%{wks.location}/Hazel/src/vendor/imgui",
        "%{wks.location}/Hazel/src/vendor/glm",
        "%{wks.location}/Hazel/src/vendor/entt/src"
    }

    links {
        "Hazel"
    }

    filter "system:windows"
        systemversion "latest"

    filter "configurations:Debug"
        defines "HZ_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "HZ_RELEASE"
        runtime "Release"
        optimize "On"