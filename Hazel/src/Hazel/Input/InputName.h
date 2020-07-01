#pragma once

#include "Key.h"
#include "MouseButton.h"

namespace Hazel
{
	class InputName
	{
	private:
		static const std::string defaultName;

	public:
		static const std::string &Get(Key key);
		static const std::string &Get(MouseButton button);

		InputName() = delete;

	private:
		static std::unordered_map<Key, std::string> LoadKeyNames();
		static std::unordered_map<MouseButton, std::string> LoadButtonNames();
	};
}