#pragma once

#include "yaml-cpp/yaml.h"

#include "Hazel/Scene/Scene.h"

namespace Hazel
{
	class SceneSerializer
	{
	public:
		static void Serialize(Scene &scene, const std::string &filename);
		static std::string Serialize(Scene &scene);
		static void Serialize(Scene &scene, YAML::Emitter &emitter);
	};
}