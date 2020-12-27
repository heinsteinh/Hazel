#pragma once

#include "Hazel/Scene/Components/ParticleComponent.h"
#include "Hazel/Core/Yaml/YamlSerializer.h"

namespace Hazel
{
	class ParticleSerializer
	{
	public:
		static void Serialize(YamlDocument &document, const ParticleComponent &component)
		{
			document.BeginMap();
			document.Key().Write("ParticleSource").Value();
			Serialize(document, component.ParticleSource);
			document.Key().Write("ParticleInfo").Value();
			Serialize(document, component.ParticleInfo);
			document.EndMap();
		}

		static void Serialize(YamlDocument &document, const ParticleSource &particleSource)
		{
			document.BeginMap()
				.Key().Write("Enabled").Value().Write(particleSource.IsEnabled())
				.Key().Write("MaxParticleCount").Value().Write(particleSource.GetMaxParticleCount())
				.Key().Write("EmissionRate").Value().Write(particleSource.GetEmissionRate())
				.EndMap();
		}

		static void Serialize(YamlDocument &document, const ParticleInfo &particleInfo)
		{
			document.BeginMap()
				.Key().Write("LinearVelocity").Value().Write(particleInfo.LinearVelocity)
				.Key().Write("LinearVelocityVariation").Value().Write(particleInfo.LinearVelocityVariation)
				.Key().Write("AngularVelocity").Value().Write(particleInfo.AngularVelocity)
				.Key().Write("AngularVelocityVariation").Value().Write(particleInfo.AngularVelocityVariation)
				.Key().Write("ColorBegin").Value().Write(particleInfo.ColorBegin)
				.Key().Write("ColorEnd").Value().Write(particleInfo.ColorEnd)
				.Key().Write("SizeBegin").Value().Write(particleInfo.SizeBegin)
				.Key().Write("SizeEnd").Value().Write(particleInfo.SizeEnd)
				.Key().Write("SizeVariation").Value().Write(particleInfo.SizeVariation)
				.Key().Write("LifeTime").Value().Write(particleInfo.LifeTime)
				.EndMap();
		}
	};

	template<>
	void YamlSerializer::Serialize(YamlDocument &document, const ParticleComponent &value)
	{
		return ParticleSerializer::Serialize(document, value);
	}

	template<>
	void YamlSerializer::Serialize(YamlDocument &document, const ParticleInfo &value)
	{
		return ParticleSerializer::Serialize(document, value);
	}

	template<>
	void YamlSerializer::Serialize(YamlDocument &document, const ParticleSource &value)
	{
		return ParticleSerializer::Serialize(document, value);
	}
}