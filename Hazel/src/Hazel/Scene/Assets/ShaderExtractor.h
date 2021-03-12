#pragma once

#include "Hazel/Scene/SceneManager/SceneManagerView.h"
#include "Hazel/Scene/Components/Sprite/SpriteSerializer.h"

namespace Hazel
{
	class ShaderExtractor
	{
	private:
		AssetManager *assetManager;

	public:
		ShaderExtractor(SceneManagerView manager)
			: assetManager(&manager.GetAssetManager())
		{
		}

		std::shared_ptr<Shader> ExtractShader(const YamlValue &source)
		{
			return nullptr;
		}
	};
}