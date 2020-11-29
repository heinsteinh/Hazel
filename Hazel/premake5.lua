project "Hazel"
    kind "StaticLib"
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
        "src/**.cpp",
        "vendor/stb_image/**.h",
        "vendor/stb_image/**.cpp",
        "vendor/glm/**.hpp",
        "vendor/glm/**.inl"
    }

    includedirs {
        "src",
        "vendor/spdlog/include",
        "vendor/GLFW/include",
        "vendor/glad/include",
        "vendor/imgui",
        "vendor/stb_image",
        "vendor/glm",
        "vendor/entt/single_include"
    }

    links {
        "GLFW",
        "glad",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        systemversion "latest"
        defines "GLFW_INCLUDE_NONE"

    filter "configurations:Debug"
        defines "HZ_DEBUG"
        runtime "Debug"
        ignoredefaultlibraries { "libcmt.lib", "libcmtd.lib", "msvcrt.lib" }
        symbols "On"

    filter "configurations:Release"
        defines "HZ_RELEASE"
        runtime "Release"
        ignoredefaultlibraries { "libcmt.lib", "libcmtd.lib", "msvcrtd.lib" }
        optimize "On"