#pragma once

#include "Hazel/Scene/Assets/ScriptExtractor.h"
#include "Hazel/Scene/ComponentManager/BaseComponentManager.h"
#include "ScriptComponent.h"
#include "ScriptSerializer.h"
#include "ScriptWidget.h"

namespace Hazel
{
	class ScriptManager : public BaseComponentManager<ScriptComponent>
	{
	public:
		ScriptManager()
			: BaseComponentManager("Script")
		{
		}

		virtual void DrawComponent(Entity entity) override
		{
			auto &component = entity.GetComponent<ScriptComponent>();
			ScriptWidget::Draw(*component.Script);
		}

		virtual void SerializeComponent(Entity entity, YamlDocument &yaml) override
		{
			auto &component = entity.GetComponent<ScriptComponent>();
			ScriptSerializer::Serialize(yaml, *component.Script);
		}

		virtual void DeserializeComponent(Entity entity, const YamlValue &yaml) override
		{
			auto &component = entity.AddComponent<ScriptComponent>();
			ScriptExtractor extractor(GetSceneManager());
			component.Script = extractor.ExtractScript(yaml);
		}
	};
}