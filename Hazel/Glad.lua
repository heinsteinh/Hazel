project "Glad"
    kind "StaticLib"
    language "C"
    staticruntime "On"

    targetdir(bindir)
    objdir(objectdir)

    files {
        "src/vendor/glad/include/glad/glad.h",
        "src/vendor/glad/include/KHR/khrplatform.h",
        "src/vendor/glad/src/glad.c"
    }

    includedirs {
        "src/vendor/glad/include"
    }

    filter "system:windows"
        systemversion "latest"

    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        runtime "Release"
        optimize "On"