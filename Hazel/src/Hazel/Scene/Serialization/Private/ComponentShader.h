#pragma once

#include "Hazel/Core/Yaml/YamlSerializer.h"
#include "Hazel/Rendering/Shaders/ShaderFactory.h"
#include "Hazel/Scene/Entity/Entity.h"
#include "Hazel/Scene/Serialization/SpriteSerializer.h"

namespace Hazel
{
	class ComponentShader
	{
	public:
		static std::shared_ptr<Shader> ExtractShader(const YamlValue &source, Entity entity)
		{
			auto name = SpriteSerializer::GetShaderName(source);
			if (name.empty())
			{
				return nullptr;
			}
			auto &assetManager = entity.GetAssetManager();
			auto shader = assetManager.GetShader(name);
			if (shader)
			{
				return shader;
			}
			shader = CreateShader(source, entity);
			return shader ? assetManager.AddShader(shader) : nullptr;
		}

	private:
		static std::shared_ptr<Shader> CreateShader(const YamlValue &source, Entity entity)
		{
			return ShaderFactory::CreateShaderFromFile(
				entity.GetLayer().GetGraphicsContext(),
				SpriteSerializer::GetShaderFilename(source));
		}
	};
}