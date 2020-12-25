#pragma once

#include "Hazel/Scene/Components/ParticleComponent.h"
#include "Hazel/Core/Yaml/YamlParser.h"

namespace Hazel
{
	class ParticleParser
	{
	public:
		static void Parse(const YamlValue &source, ParticleComponent &component)
		{
			Parse(source["ParticleInfo"], component.ParticleInfo);
			Parse(source["ParticleSource"], component.ParticleSource);
		}

		static void Parse(const YamlValue &source, ParticleInfo &particleInfo)
		{
			source["LinearVelocity"].Extract(particleInfo.LinearVelocity);
			source["LinearVelocityVariation"].Extract(particleInfo.LinearVelocityVariation);
			source["AngularVelocity"].Extract(particleInfo.AngularVelocity);
			source["AngularVelocityVariation"].Extract(particleInfo.AngularVelocityVariation);
			source["ColorBegin"].Extract(particleInfo.ColorBegin);
			source["ColorEnd"].Extract(particleInfo.ColorEnd);
			source["SizeBegin"].Extract(particleInfo.SizeBegin);
			source["SizeEnd"].Extract(particleInfo.SizeEnd);
			source["SizeVariation"].Extract(particleInfo.SizeVariation);
			source["LifeTime"].Extract(particleInfo.LifeTime);
		}

		static void Parse(const YamlValue &source, ParticleSource &particleSource)
		{
			auto maxParticleCount = particleSource.GetMaxParticleCount();
			source["MaxParticleCount"].Extract(maxParticleCount);
			particleSource.SetMaxParticleCount(maxParticleCount);
			auto emissionRate = particleSource.GetEmissionRate();
			source["EmissionRate"].Extract(emissionRate);
			particleSource.SetEmissionRate(emissionRate);
		}
	};

	template<>
	void YamlParser::Parse(const YamlValue &source, ParticleComponent &value)
	{
		return ParticleParser::Parse(source, value);
	}

	template<>
	void YamlParser::Parse(const YamlValue &source, ParticleInfo &value)
	{
		return ParticleParser::Parse(source, value);
	}

	template<>
	void YamlParser::Parse(const YamlValue &source, ParticleSource &value)
	{
		return ParticleParser::Parse(source, value);
	}
}