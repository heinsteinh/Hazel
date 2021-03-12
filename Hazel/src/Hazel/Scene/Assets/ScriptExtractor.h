#pragma once

#include "Hazel/Scene/SceneManager/SceneManagerView.h"
#include "Hazel/Scene/Components/Script/ScriptComponent.h"
#include "Hazel/Scene/Components/Script/ScriptSerializer.h"

namespace Hazel
{
	class ScriptExtractor
	{
	private:
		AssetManager *assetManager;

	public:
		ScriptExtractor(SceneManagerView manager)
			: assetManager(&manager.GetAssetManager())
		{
		}

		std::unique_ptr<Script> ExtractScript(const YamlValue &source)
		{
			return assetManager->CreateScript(ScriptSerializer::GetScriptName(source));
		}
	};
}