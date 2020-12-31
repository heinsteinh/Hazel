#pragma once

#include "Hazel/Scene/Components/ParticleComponent.h"
#include "Hazel/Core/Yaml/Vector2Serializer.h"
#include "Hazel/Core/Yaml/Vector3Serializer.h"
#include "Hazel/Core/Yaml/Vector4Serializer.h"

namespace Hazel
{
	template<>
	struct YamlSerializer<ParticleComponent>
	{
		static void Serialize(YamlDocument &document, const ParticleComponent &value)
		{
			document.BeginMap()
				.Write("Enabled", value.Source.IsEnabled())
				.Write("MaxParticleCount", value.Source.GetMaxParticleCount())
				.Write("EmissionRate", value.Source.GetEmissionRate())
				.Write("LinearVelocity", value.Info.LinearVelocity)
				.Write("LinearVelocityVariation", value.Info.LinearVelocityVariation)
				.Write("AngularVelocity", value.Info.AngularVelocity)
				.Write("AngularVelocityVariation", value.Info.AngularVelocityVariation)
				.Write("ColorBegin", value.Info.ColorBegin)
				.Write("ColorEnd", value.Info.ColorEnd)
				.Write("SizeBegin", value.Info.SizeBegin)
				.Write("SizeEnd", value.Info.SizeEnd)
				.Write("SizeVariation", value.Info.SizeVariation)
				.Write("LifeTime", value.Info.LifeTime)
				.EndMap();
		}

		static void Deserialize(const YamlValue &source, ParticleComponent &value)
		{
			value.Source.SetEnabled(source["Enabled"].ValueOr(value.Source.IsEnabled()));
			value.Source.SetMaxParticleCount(source["MaxParticleCount"].ValueOr(value.Source.GetMaxParticleCount()));
			value.Source.SetEmissionRate(source["EmissionRate"].ValueOr(value.Source.GetEmissionRate()));
			source["LinearVelocity"].Extract(value.Info.LinearVelocity);
			source["LinearVelocityVariation"].Extract(value.Info.LinearVelocityVariation);
			source["AngularVelocity"].Extract(value.Info.AngularVelocity);
			source["AngularVelocityVariation"].Extract(value.Info.AngularVelocityVariation);
			source["ColorBegin"].Extract(value.Info.ColorBegin);
			source["ColorEnd"].Extract(value.Info.ColorEnd);
			source["SizeBegin"].Extract(value.Info.SizeBegin);
			source["SizeEnd"].Extract(value.Info.SizeEnd);
			source["SizeVariation"].Extract(value.Info.SizeVariation);
			source["LifeTime"].Extract(value.Info.LifeTime);
		}
	};

	using ParticleSerializer = YamlSerializer<ParticleComponent>;
}