project "HazelEditor"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "On"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("obj/" .. outputdir .. "/%{prj.name}")

    pchheader "StdAfx.h"
    pchsource "src/StdAfx.cpp"
    forceincludes "StdAfx.h"

    files {
        "src/**.h",
        "src/**.cpp"
    }

    includedirs {
        "src",
        "../Hazel/src",
        "../Hazel/vendor/spdlog/include",
        "../Hazel/vendor/imgui",
        "../Hazel/vendor/glm"
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