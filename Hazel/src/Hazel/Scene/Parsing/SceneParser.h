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
		static void ParseFile(const std::string &filename, Scene &scene);
		static void Parse(const std::string &source, Scene &scene);
		static void Parse(const YamlValue &source, Scene &scene);
	};
}