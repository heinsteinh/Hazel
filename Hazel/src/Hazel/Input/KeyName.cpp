#include "KeyName.h"

#include "GLFW/glfw3.h"

namespace Hazel
{
	const char *KeyName::GetKeyName(Key key)
	{
		auto name = glfwGetKeyName(static_cast<int>(key), 0);
		return name ? name : "";
	}

	const char *KeyName::GetScancodeName(int scancode)
	{
		auto name = glfwGetKeyName(GLFW_KEY_UNKNOWN, scancode);
		return name ? name : "";
	}
}