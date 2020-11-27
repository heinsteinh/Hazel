workspace "Hazel"
    architecture "x64"
    startproject "HazelEditor"

    configurations {
        "Debug",
        "Release"
    }

    flags {
        "MultiProcessorCompile"
    }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    group "Dependencies"
        include "Hazel/vendor"

    group ""
        include "Hazel"
        include "HazelEditor"
        include "Sandbox"