#pragma once

#include "Hazel/Geometry/Transform.h"

namespace Hazel
{
	struct Particle
	{
		bool Active = false;
		Transform Transform;
		glm::vec2 LinearVelocity{0.0f};
		float AngularVelocity = 0.0f;
		glm::vec4 ColorBegin{0.0f};
		glm::vec4 ColorEnd{0.0f};
		float SizeBegin = 0.0f;
		float SizeEnd = 0.0f;
		float LifeTime = 1.0f;
		float RemainingLifeTime = 0.0f;

		inline float GetSize() const
		{
			return glm::mix(SizeEnd, SizeBegin, GetLife());
		}

		constexpr float GetLife() const
		{
			return RemainingLifeTime / LifeTime;
		}

		inline glm::vec4 GetColor() const
		{
			auto life = GetLife();
			auto color = glm::mix(ColorEnd, ColorBegin, life);
			color.a *= life;
			return color;
		}
	};
}