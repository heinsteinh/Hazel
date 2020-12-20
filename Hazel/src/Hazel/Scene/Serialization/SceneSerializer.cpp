#include "SceneSerializer.h"

#include "Hazel/Core/FileSystem/FileWriter.h"
#include "EntitySerializer.h"

namespace Hazel
{
	void SceneSerializer::Serialize(Scene &scene, YAML::Emitter &emitter)
	{
		emitter << YAML::BeginMap;
		emitter << YAML::Key << "Scene" << YAML::Value << scene.GetName();
		emitter << YAML::Key << "Entities" << YAML::Value << YAML::BeginSeq;
		scene.ForEach([&](auto entity)
		{
			emitter << entity;
		});
		emitter << YAML::EndSeq;
		emitter << YAML::EndMap;
	}

	std::string SceneSerializer::Serialize(Scene &scene)
	{
		YAML::Emitter emitter;
		Serialize(scene, emitter);
		return emitter.c_str();
	}

	void SceneSerializer::Serialize(Scene &scene, const std::string &filename)
	{
		FileWriter::Write(filename, Serialize(scene));
	}
}