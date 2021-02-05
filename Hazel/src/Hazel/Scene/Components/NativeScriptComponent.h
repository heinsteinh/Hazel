#pragma once

#include <memory>

#include "Hazel/Scene/Scripting/NativeScript.h"

namespace Hazel
{
	struct NativeScriptComponent
	{
		std::unique_ptr<NativeScript> Script;
	};
}