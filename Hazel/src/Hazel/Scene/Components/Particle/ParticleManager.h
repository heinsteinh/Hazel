#pragma once

#include "Hazel/Scene/ComponentManager/BaseComponentManager.h"
#include "ParticleComponent.h"
#include "ParticleSerializer.h"
#include "ParticleWidget.h"

namespace Hazel
{
	class ParticleManager : public BaseComponentManager<ParticleComponent>
	{
	public:
		ParticleManager()
			: BaseComponentManager("Particle")
		{
		}

		virtual void DrawComponent(Entity entity) override
		{
			auto &component = entity.GetComponent<ParticleComponent>();
			ParticleWidget::Draw(component.Source);
		}

		virtual void SerializeComponent(Entity entity, YamlDocument &yaml) override
		{
			auto &component = entity.GetComponent<ParticleComponent>();
			ParticleSerializer::Serialize(yaml, component.Source);
		}

		virtual void DeserializeComponent(Entity entity, const YamlValue &yaml) override
		{
			auto &component = entity.AddComponent<ParticleComponent>();
			ParticleSerializer::Deserialize(yaml, component.Source);
		}
	};
}