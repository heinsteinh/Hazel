workspace "Hazel"
    architecture "x64"
    startproject "Editor"

    configurations {
        "Debug",
        "Release"
    }

    flags {
        "MultiProcessorCompile"
    }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
    bindir = "bin/" .. outputdir .. "/%{prj.name}"
    objectdir = "obj/" .. outputdir .. "/%{prj.name}"

    include "Hazel"
    include "Editor"
    include "Sandbox"