#include "KeyName.h"

#include "GLFW/glfw3.h"

namespace Hazel
{
	const char *KeyName::GetKeyName(Key key)
	{
		return glfwGetKeyName(static_cast<int>(key), 0);
	}

	const char *KeyName::GetScancodeName(int scancode)
	{
		return glfwGetKeyName(GLFW_KEY_UNKNOWN, scancode);
	}
}