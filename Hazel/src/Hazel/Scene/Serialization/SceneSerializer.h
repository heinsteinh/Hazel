#pragma once

#include "Hazel/Scene/Scene/Scene.h"
#include "SceneParsingException.h"

namespace Hazel
{
	class SceneSerializer
	{
	public:
		static void Serialize(Scene &scene, const std::string &filename);
		static void Deserialize(Scene &scene, const std::string &filename);
	};
}