#pragma once

namespace Hazel
{
	struct ParticleInfo
	{
		glm::vec2 Position{0.0f};
		glm::vec2 LinearVelocity{0.0f};
		glm::vec2 LinearVelocityVariation{0.0f};
		float AngularVelocity = 0.0f;
		glm::vec4 ColorBegin{0.0f};
		glm::vec4 ColorEnd{0.0f};
		float SizeBegin = 0.0f;
		float SizeEnd = 0.0f;
		float SizeVariation = 0.0f;
		float LifeTime = 1.0f;
	};
}