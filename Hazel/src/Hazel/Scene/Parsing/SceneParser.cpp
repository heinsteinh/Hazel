#include "SceneParser.h"

#include "Hazel/Core/FileSystem/FileReader.h"

namespace Hazel
{
	std::shared_ptr<Scene> SceneParser::Load(const std::string &filename)
	{
		return Parse(FileReader::ReadAll(filename));
	}

	std::shared_ptr<Scene> SceneParser::Parse(const std::string &content)
	{
		return Parse(YAML::Load(content));
	}

	std::shared_ptr<Scene> SceneParser::Parse(const YAML::Node &node)
	{
		auto name = node["Scene"];
		if (!name)
		{
			throw SceneParsingException("Missing scene name");
		}
		SceneInfo info;
		info.Name = name.as<std::string>();
		auto scene = std::make_shared<Scene>(info);
		return scene;
	}
}