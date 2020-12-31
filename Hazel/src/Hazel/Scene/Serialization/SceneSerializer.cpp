#include "SceneSerializer.h"

#include "Hazel/Core/FileSystem/FileWriter.h"
#include "Hazel/Core/FileSystem/FileReader.h"
#include "EntitySerializer.h"

namespace Hazel
{
	void SceneSerializer::Serialize(Scene &scene, const std::string &filename)
	{
		YamlDocument document;
		document.BeginMap();
		document.Write("Scene", scene.GetName());
		document.Key().Write("Entities").Value().BeginSequence();
		scene.ForEach([&](auto entity)
		{
			document.Write(entity);
		});
		document.EndSequence().EndMap();
		FileWriter::Write(filename, document.GetData());
	}

	void SceneSerializer::Deserialize(Scene &scene, const std::string &filename)
	{
		auto source = YamlValue::FromYaml(FileReader::ReadAll(filename));
		std::string name;
		source["Scene"].Extract(name);
		if (name.empty())
		{
			throw SceneParsingException("Missing scene name");
		}
		scene.SetName(name);
		scene.Clear();
		for (const auto &entity : source["Entities"])
		{
			entity.Extract(scene.CreateEntity());
		}
	}
}