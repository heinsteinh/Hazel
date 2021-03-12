#pragma once

#include "Hazel/Scene/ComponentManager/BaseComponentManager.h"
#include "CameraComponent.h"
#include "CameraSerializer.h"
#include "CameraWidget.h"

namespace Hazel
{
	class CameraManager : public BaseComponentManager<CameraComponent>
	{
	public:
		CameraManager()
			: BaseComponentManager("Camera")
		{
		}

		virtual void DrawComponent(Entity entity) override
		{
			auto &component = entity.GetComponent<CameraComponent>();
			CameraWidget::Draw(component.Projection);
		}

		virtual void SerializeComponent(Entity entity, YamlDocument &yaml) override
		{
			auto &component = entity.GetComponent<CameraComponent>();
			CameraSerializer::Serialize(yaml, component.Projection);
		}

		virtual void DeserializeComponent(Entity entity, const YamlValue &yaml) override
		{
			auto &component = entity.AddComponent<CameraComponent>();
			CameraSerializer::Deserialize(yaml, component.Projection);
		}
	};
}