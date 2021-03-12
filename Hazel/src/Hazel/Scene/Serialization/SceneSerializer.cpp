#include "SceneSerializer.h"

#include "Hazel/Core/FileSystem/FileWriter.h"
#include "Hazel/Core/FileSystem/FileReader.h"
#include "EntitySerializer.h"

namespace Hazel
{
	SceneSerializer::SceneSerializer(SceneManager &manager)
		: manager(&manager)
	{
	}

	void SceneSerializer::Serialize(Scene &scene, const std::string &filename)
	{
		YamlDocument yaml;
		yaml.BeginMap();
		yaml.Write("Scene", scene.GetName());
		yaml.Key().Write("Entities").Value().BeginSequence();
		EntitySerializer serializer(*manager);
		scene.ForEach([&](auto entity)
		{
			serializer.Serialize(yaml, entity);
		});
		yaml.EndSequence().EndMap();
		FileWriter::Write(filename, yaml.GetData());
	}

	void SceneSerializer::Deserialize(Scene &scene, const std::string &filename)
	{
		auto yaml = YamlValue::FromYaml(FileReader::ReadAll(filename));
		auto name = yaml["Scene"].GetValueOr(std::string());
		if (name.empty())
		{
			throw SceneParsingException("Missing scene name");
		}
		scene.SetName(name);
		scene.Clear();
		EntitySerializer serializer(*manager);
		yaml["Entities"].ForEachSequence([&](auto entity)
		{
			serializer.Deserialize(entity, scene.CreateEntity());
		});
	}
}