#include "SceneParser.h"

#include "Hazel/Core/FileSystem/FileReader.h"
#include "EntityParser.h"

namespace Hazel
{
	void SceneParser::ParseFile(const std::string &filename, Scene &scene)
	{
		Parse(FileReader::ReadAll(filename), scene);
	}

	void SceneParser::Parse(const std::string &source, Scene &scene)
	{
		Parse(YamlValue::FromYaml(source), scene);
	}

	void SceneParser::Parse(const YamlValue &source, Scene &scene)
	{
		std::string name;
		source["Scene"].Extract(name);
		if (name.empty())
		{
			throw SceneParsingException("Missing scene name");
		}
		scene.Clear();
		scene.SetName(name);
		for (const auto &entity : source["Entities"])
		{
			EntityParser::Parse(entity, scene);
		}
	}
}