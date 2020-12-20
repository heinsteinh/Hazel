project "yaml-cpp"
    kind "StaticLib"
    language "C++"

    targetdir(bindir)
    objdir(objectdir)

    files {
        "src/vendor/yaml-cpp/src/**.h",
        "src/vendor/yaml-cpp/src/**.cpp",
        "src/vendor/yaml-cpp/include/**.h"
    }

    includedirs {
        "src/vendor/yaml-cpp/include"
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
        symbols "on"

    filter "configurations:Release"
        runtime "Release"
        optimize "on"