#pragma once

#include "Hazel/Core/Yaml/Vector2Serializer.h"
#include "Hazel/Core/Yaml/Vector3Serializer.h"
#include "Hazel/Core/Yaml/Vector4Serializer.h"
#include "Hazel/Rendering/Particles/ParticleSource.h"

namespace Hazel
{
	template<>
	struct YamlSerializer<ParticleSource>
	{
		static void Serialize(YamlDocument &yaml, const ParticleSource &source)
		{
			auto &info = source.GetParticleInfo();
			yaml.BeginMap()
				.Write("Enabled", source.IsEnabled())
				.Write("MaxParticleCount", source.GetMaxParticleCount())
				.Write("EmissionRate", source.GetEmissionRate())
				.Write("LinearVelocity", info.LinearVelocity)
				.Write("LinearVelocityVariation", info.LinearVelocityVariation)
				.Write("AngularVelocity", info.AngularVelocity)
				.Write("AngularVelocityVariation", info.AngularVelocityVariation)
				.Write("ColorBegin", info.ColorBegin)
				.Write("ColorEnd", info.ColorEnd)
				.Write("SizeBegin", info.SizeBegin)
				.Write("SizeEnd", info.SizeEnd)
				.Write("SizeVariation", info.SizeVariation)
				.Write("LifeTime", info.LifeTime)
				.EndMap();
		}

		static void Deserialize(const YamlValue &yaml, ParticleSource &source)
		{
			auto &info = source.GetParticleInfo();
			source.SetEnabled(yaml["Enabled"].GetValueOr(source.IsEnabled()));
			source.SetMaxParticleCount(yaml["MaxParticleCount"].GetValueOr(source.GetMaxParticleCount()));
			source.SetEmissionRate(yaml["EmissionRate"].GetValueOr(source.GetEmissionRate()));
			yaml["LinearVelocity"].Extract(info.LinearVelocity);
			yaml["LinearVelocityVariation"].Extract(info.LinearVelocityVariation);
			yaml["AngularVelocity"].Extract(info.AngularVelocity);
			yaml["AngularVelocityVariation"].Extract(info.AngularVelocityVariation);
			yaml["ColorBegin"].Extract(info.ColorBegin);
			yaml["ColorEnd"].Extract(info.ColorEnd);
			yaml["SizeBegin"].Extract(info.SizeBegin);
			yaml["SizeEnd"].Extract(info.SizeEnd);
			yaml["SizeVariation"].Extract(info.SizeVariation);
			yaml["LifeTime"].Extract(info.LifeTime);
		}
	};

	using ParticleSerializer = YamlSerializer<ParticleSource>;
}