#pragma once

#include "yaml-cpp/yaml.h"

#include "Hazel/Scene/Components/ParticleSourceComponent.h"
#include "GeometrySerializer.h"

namespace Hazel
{
	class ParticleSourceSerializer
	{
	public:
		static void Serialize(const ParticleSourceComponent &particleSource, YAML::Emitter &emitter)
		{
			Serialize(particleSource.ParticleSource, emitter);
		}

		static void Serialize(const ParticleSource &particleSource, YAML::Emitter &emitter)
		{
			emitter << YAML::BeginMap;
			emitter << YAML::Key << "MaxParticleCount" << YAML::Value << particleSource.GetMaxParticleCount();
			emitter << YAML::EndMap;
		}
	};

	inline YAML::Emitter &operator<<(YAML::Emitter &emitter, const ParticleSourceComponent &particleSource)
	{
		ParticleSourceSerializer::Serialize(particleSource, emitter);
		return emitter;
	}

	inline YAML::Emitter &operator<<(YAML::Emitter &emitter, const ParticleSource &particleSource)
	{
		ParticleSourceSerializer::Serialize(particleSource, emitter);
		return emitter;
	}
}