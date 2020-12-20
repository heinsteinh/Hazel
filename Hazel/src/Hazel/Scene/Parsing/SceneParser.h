#pragma once

#include "yaml-cpp/yaml.h"

#include "Hazel/Scene/Scene.h"
#include "Hazel/Core/FileSystem/OpenFileException.h"
#include "SceneParsingException.h"

namespace Hazel
{
	class SceneParser
	{
	public:
		static std::shared_ptr<Scene> Load(const std::string &filename);
		static std::shared_ptr<Scene> Parse(const std::string &content);
		static std::shared_ptr<Scene> Parse(const YAML::Node &node);
	};
}