#include "DefaultParticleSettings.h"

namespace Hazel
{
	const ParticleInfo DefaultParticleSettings::particleInfo = CreateParticleInfo();

	ParticleInfo DefaultParticleSettings::CreateParticleInfo()
	{
		ParticleInfo result;
		result.Position = glm::vec3(0.0f);
		result.LinearVelocity = {0.0f, 0.0f};
		result.LinearVelocityVariation = {0.2f, 0.2f};
		result.AngularVelocity = glm::radians(180.0f);
		result.AngularVelocityVariation = glm::radians(180.0f);
		result.ColorBegin = {1.0f, 0.30f, 0.0f, 1.0f};
		result.ColorEnd = {1.0f, 0.6f, 0.0f, 1.0f};
		result.SizeBegin = 0.1f;
		result.SizeEnd = 0.0f;
		result.SizeVariation = 0.1f;
		result.LifeTime = 2.0f;
		return result;
	}
}