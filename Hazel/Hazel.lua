project "Hazel"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "On"

    targetdir(bindir)
    objdir(objectdir)

    pchheader "StdAfx.h"
    pchsource("src/Hazel/StdAfx.cpp")
    forceincludes "StdAfx.h"

    files {
        "src/Hazel/**.h",
        "src/Hazel/**.cpp",
        "src/vendor/stb_image/**.h",
        "src/vendor/stb_image/**.cpp",
        "src/vendor/glm/**.hpp",
        "src/vendor/glm/**.inl"
    }

    includedirs {
        "src",
        "src/vendor/spdlog/include",
        "src/vendor/glfw/include",
        "src/vendor/glad/include",
        "src/vendor/imgui",
        "src/vendor/stb_image",
        "src/vendor/glm",
        "src/vendor/entt/src"
    }

    links {
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        systemversion "latest"
        defines "GLFW_INCLUDE_NONE"

    filter "configurations:Debug"
        defines "HZ_DEBUG"
        runtime "Debug"
        ignoredefaultlibraries {"libcmt.lib", "libcmtd.lib", "msvcrt.lib"}
        symbols "On"

    filter "configurations:Release"
        defines "HZ_RELEASE"
        runtime "Release"
        ignoredefaultlibraries {"libcmt.lib", "libcmtd.lib", "msvcrtd.lib"}
        optimize "On"