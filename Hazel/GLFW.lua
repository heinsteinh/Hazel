project "GLFW"
	kind "StaticLib"
	language "C"

	targetdir(bindir)
	objdir(objectdir)

	files {
		"src/vendor/glfw/include/GLFW/glfw3.h",
		"src/vendor/glfw/include/GLFW/glfw3native.h",
		"src/vendor/glfw/src/glfw_config.h",
		"src/vendor/glfw/src/context.c",
		"src/vendor/glfw/src/init.c",
		"src/vendor/glfw/src/input.c",
		"src/vendor/glfw/src/monitor.c",
		"src/vendor/glfw/src/vulkan.c",
		"src/vendor/glfw/src/window.c"
	}

	filter "system:linux"
		pic "On"
		systemversion "latest"
		staticruntime "On"

		files {
			"src/vendor/glfw/src/x11_init.c",
			"src/vendor/glfw/src/x11_monitor.c",
			"src/vendor/glfw/src/x11_window.c",
			"src/vendor/glfw/src/xkb_unicode.c",
			"src/vendor/glfw/src/posix_time.c",
			"src/vendor/glfw/src/posix_thread.c",
			"src/vendor/glfw/src/glx_context.c",
			"src/vendor/glfw/src/egl_context.c",
			"src/vendor/glfw/src/osmesa_context.c",
			"src/vendor/glfw/src/linux_joystick.c"
		}

		defines {
			"_GLFW_X11"
		}

	filter "system:windows"
		systemversion "latest"
		staticruntime "On"

		files {
			"src/vendor/glfw/src/win32_init.c",
			"src/vendor/glfw/src/win32_joystick.c",
			"src/vendor/glfw/src/win32_monitor.c",
			"src/vendor/glfw/src/win32_time.c",
			"src/vendor/glfw/src/win32_thread.c",
			"src/vendor/glfw/src/win32_window.c",
			"src/vendor/glfw/src/wgl_context.c",
			"src/vendor/glfw/src/egl_context.c",
			"src/vendor/glfw/src/osmesa_context.c"
		}

		defines { 
			"_GLFW_WIN32",
			"_CRT_SECURE_NO_WARNINGS"
		}

	filter "configurations:Debug"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		runtime "Release"
		optimize "On"