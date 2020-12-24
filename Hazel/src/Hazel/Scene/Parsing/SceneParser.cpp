#include "SceneParser.h"

#include "Hazel/Core/FileSystem/FileReader.h"
#include "EntityParser.h"

namespace Hazel
{
	std::shared_ptr<Scene> SceneParser::Load(const std::string &filename)
	{
		return Parse(FileReader::ReadAll(filename));
	}

	std::shared_ptr<Scene> SceneParser::Parse(const std::string &source)
	{
		return Parse(YamlValue::FromYaml(source));
	}

	std::shared_ptr<Scene> SceneParser::Parse(const YamlValue &source)
	{
		std::string name;
		source["Scene"].Extract(name);
		if (name.empty())
		{
			throw SceneParsingException("Missing scene name");
		}
		auto scene = std::make_shared<Scene>(name);
		for (const auto &entity : source["Entities"])
		{
			EntityParser::LoadEntity(entity, *scene);
		}
		return scene;
	}
}