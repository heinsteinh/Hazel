#pragma once

#include "Hazel/Scene/Scene.h"
#include "Hazel/Core/Yaml/YamlValue.h"
#include "Hazel/Core/FileSystem/OpenFileException.h"
#include "SceneParsingException.h"

namespace Hazel
{
	class SceneParser
	{
	public:
		static std::shared_ptr<Scene> Load(const std::string &filename);
		static std::shared_ptr<Scene> Parse(const std::string &source);
		static std::shared_ptr<Scene> Parse(const YamlValue &source);
	};
}