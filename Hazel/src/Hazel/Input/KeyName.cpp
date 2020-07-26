#include "KeyName.h"

#include "GLFW/glfw3.h"

#include "Helpers/GlfwKeyMap.h"

namespace Hazel
{
	const std::string &Hazel::KeyName::GetKeyName(Key key)
	{
		auto i = keyNames.find(key);
		if (i != keyNames.end())
		{
			return i->second;
		}
		std::lock_guard<std::mutex> lock(mutex);
		auto name = glfwGetKeyName(GlfwKeyMap::GetNativeKey(key), 0);
		return keyNames.emplace(
			key,
			name ? name : std::to_string(static_cast<int>(key))
		).first->second;
	}

	const std::string &Hazel::KeyName::GetScancodeName(int scancode)
	{
		auto i = scancodeNames.find(scancode);
		if (i != scancodeNames.end())
		{
			return i->second;
		}
		std::lock_guard<std::mutex> lock(mutex);
		auto name = glfwGetKeyName(GLFW_KEY_UNKNOWN, scancode);
		return scancodeNames.emplace(
			scancode,
			name && *name ? name : std::to_string(scancode)
		).first->second;
	}
}