#pragma once

#include "glm/glm.hpp"

namespace Hazel
{
	struct ParticleInfo
	{
		glm::vec2 LinearVelocity = {0.0f, 0.0f};
		glm::vec2 LinearVelocityVariation = {0.2f, 0.2f};
		float AngularVelocity = glm::radians(180.0f);
		float AngularVelocityVariation = glm::radians(180.0f);
		glm::vec4 ColorBegin = {1.0f, 0.30f, 0.0f, 1.0f};
		glm::vec4 ColorEnd = {1.0f, 0.6f, 0.0f, 1.0f};
		float SizeBegin = 0.1f;
		float SizeEnd = 0.0f;
		float SizeVariation = 0.1f;
		float LifeTime = 2.0f;
	};
}