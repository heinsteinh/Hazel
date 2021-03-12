#pragma once

#include "Hazel/Scene/Assets/ShaderExtractor.h"
#include "Hazel/Scene/Assets/TextureDialog.h"
#include "Hazel/Scene/ComponentManager/BaseComponentManager.h"
#include "SpriteComponent.h"
#include "SpriteSerializer.h"
#include "SpriteWidget.h"
#include "Private/TextureExtractor.h"

namespace Hazel
{
	class SpriteManager : public BaseComponentManager<SpriteComponent>
	{
	public:
		SpriteManager()
			: BaseComponentManager("Sprite")
		{
		}

		virtual void DrawComponent(Entity entity) override
		{
			auto &component = entity.GetComponent<SpriteComponent>();
			auto status = SpriteWidget::Draw(component);
			if (status.RemoveTexture)
			{
				component.Material.Texture.SetSource(nullptr);
			}
			if (status.BrowseTexture)
			{
				TextureDialog dialog(GetSceneManager());
				component.Material.Texture = dialog.GetTextureFromUser();
			}
		}

		virtual void SerializeComponent(Entity entity, YamlDocument &yaml) override
		{
			auto &component = entity.GetComponent<SpriteComponent>();
			SpriteSerializer::Serialize(yaml, component);
		}

		virtual void DeserializeComponent(Entity entity, const YamlValue &yaml) override
		{
			auto &component = entity.AddComponent<SpriteComponent>();
			SpriteSerializer::Deserialize(yaml, component);
			component.Material.Texture = ExtractTexture(yaml);
			component.Material.Shader = ExtractShader(yaml);
		}

	private:
		std::shared_ptr<Texture> ExtractTexture(const YamlValue &yaml)
		{
			TextureExtractor textureExtractor(GetSceneManager());
			return textureExtractor.ExtractTexture(yaml);
		}

		std::shared_ptr<Shader> ExtractShader(const YamlValue &yaml)
		{
			ShaderExtractor shaderExtractor(GetSceneManager());
			return shaderExtractor.ExtractShader(yaml);
		}
	};
}