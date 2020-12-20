#pragma once

#include "yaml-cpp/yaml.h"

#include "Hazel/Scene/Components/ParticleComponent.h"
#include "GeometrySerializer.h"

namespace Hazel
{
	YAML::Emitter &operator<<(YAML::Emitter &emitter, const ParticleInfo &particleInfo);
	YAML::Emitter &operator<<(YAML::Emitter &emitter, const ParticleSource &particleSource);

	class ParticleSerializer
	{
	public:
		static void Serialize(const ParticleComponent &component, YAML::Emitter &emitter)
		{
			emitter << YAML::BeginMap;
			emitter << YAML::Key << "ParticleInfo" << YAML::Value << component.ParticleInfo;
			emitter << YAML::Key << "ParticleSource" << YAML::Value << component.ParticleSource;
			emitter << YAML::EndMap;
		}

		static void Serialize(const ParticleInfo &particleInfo, YAML::Emitter &emitter)
		{
			emitter << YAML::BeginMap;
			emitter << YAML::Key << "Position" << YAML::Value << particleInfo.Position;
			emitter << YAML::Key << "LinearVelocity" << YAML::Value << particleInfo.LinearVelocity;
			emitter << YAML::Key << "LinearVelocityVariation" << YAML::Value << particleInfo.LinearVelocityVariation;
			emitter << YAML::Key << "AngularVelocity" << YAML::Value << particleInfo.AngularVelocity;
			emitter << YAML::Key << "AngularVelocityVariation" << YAML::Value << particleInfo.AngularVelocityVariation;
			emitter << YAML::Key << "ColorBegin" << YAML::Value << particleInfo.ColorBegin;
			emitter << YAML::Key << "ColorEnd" << YAML::Value << particleInfo.ColorEnd;
			emitter << YAML::Key << "SizeBegin" << YAML::Value << particleInfo.SizeBegin;
			emitter << YAML::Key << "SizeEnd" << YAML::Value << particleInfo.SizeEnd;
			emitter << YAML::Key << "SizeVariation" << YAML::Value << particleInfo.SizeVariation;
			emitter << YAML::Key << "LifeTime" << YAML::Value << particleInfo.LifeTime;
			emitter << YAML::EndMap;
		}

		static void Serialize(const ParticleSource &particleSource, YAML::Emitter &emitter)
		{
			emitter << YAML::BeginMap;
			emitter << YAML::Key << "MaxParticleCount" << YAML::Value << particleSource.GetMaxParticleCount();
			emitter << YAML::EndMap;
		}
	};

	inline YAML::Emitter &operator<<(YAML::Emitter &emitter, const ParticleComponent &component)
	{
		ParticleSerializer::Serialize(component, emitter);
		return emitter;
	}

	inline YAML::Emitter &operator<<(YAML::Emitter &emitter, const ParticleInfo &particleInfo)
	{
		ParticleSerializer::Serialize(particleInfo, emitter);
		return emitter;
	}

	inline YAML::Emitter &operator<<(YAML::Emitter &emitter, const ParticleSource &particleSource)
	{
		ParticleSerializer::Serialize(particleSource, emitter);
		return emitter;
	}
}