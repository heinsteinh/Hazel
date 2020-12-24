#pragma once

#include "Hazel/Scene/Scene.h"
#include "Hazel/Core/Yaml/YamlSerializer.h"

namespace Hazel
{
	class SceneSerializer
	{
	public:
		static void Serialize(Scene &scene, const std::string &filename);
		static std::string Serialize(Scene &scene);
		static void Serialize(YamlDocument &document, Scene &scene);
	};
}