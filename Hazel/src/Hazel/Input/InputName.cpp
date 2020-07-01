#include "InputName.h"

#include "GLFW/glfw3.h"

#include "GlfwKeyMap.h"

namespace Hazel
{
	const std::string InputName::defaultName;

	const std::string &InputName::Get(Key key)
	{
		static const std::unordered_map<Key, std::string> keyNames = LoadKeyNames();
		auto i = keyNames.find(key);
		return i == keyNames.end() ? defaultName : i->second;
	}

	const std::string &InputName::Get(MouseButton button)
	{
		static const std::unordered_map<MouseButton, std::string> buttonNames = LoadButtonNames();
		auto i = buttonNames.find(button);
		return i == buttonNames.end() ? defaultName : i->second;
	}

	std::unordered_map<Key, std::string> InputName::LoadKeyNames()
	{
		std::unordered_map<Key, std::string> result;
		for (auto [native, hazel] : GlfwKeyMap::GetKeyMap())
		{
			result[hazel] = glfwGetKeyName(native, 0);
		}
		return result;
	}

	std::unordered_map<MouseButton, std::string> InputName::LoadButtonNames()
	{
		return {
			{MouseButton::B1, "MouseButtton1"},
			{MouseButton::B2, "MouseButtton2"},
			{MouseButton::B3, "MouseButtton3"},
			{MouseButton::B4, "MouseButtton4"},
			{MouseButton::B5, "MouseButtton5"},
			{MouseButton::B6, "MouseButtton6"},
			{MouseButton::B7, "MouseButtton7"},
			{MouseButton::B8, "MouseButtton8"},
			{MouseButton::Invalid, "InvalidMouseButton"}
		};
	}
}