#pragma once

#include <memory>

#include "Hazel/Scene/Assets/Script.h"

namespace Hazel
{
	struct ScriptComponent
	{
		std::unique_ptr<Script> Script;
	};
}