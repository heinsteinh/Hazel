#include "SceneSerializer.h"

#include "Hazel/Core/FileSystem/FileWriter.h"
#include "EntitySerializer.h"

namespace Hazel
{
	void SceneSerializer::Serialize(const std::string &filename, Scene &scene)
	{
		FileWriter::Write(filename, Serialize(scene));
	}

	std::string SceneSerializer::Serialize(Scene &scene)
	{
		YamlDocument document;
		Serialize(document, scene);
		return document.GetData();
	}

	void SceneSerializer::Serialize(YamlDocument &document, Scene &scene)
	{
		document.BeginMap();
		document.Key().Write("Scene").Value().Write(scene.GetName());
		document.Key().Write("Entities").BeginSequence();
		scene.ForEach([&](auto entity)
		{
			EntitySerializer::Serialize(document, entity);
		});
		document.EndSequence().EndMap();
	}
}