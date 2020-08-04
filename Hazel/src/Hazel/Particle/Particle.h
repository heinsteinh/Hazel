#pragma once

#include "Hazel/Geometry/Transform.h"

namespace Hazel
{
	struct Particle
	{
		bool Active = false;
		glm::vec2 Position{0.0f};
		glm::vec2 LinearVelocity{0.0f};
		float Rotation = 0.0f;
		float AngularVelocity = 0.0f;
		glm::vec4 ColorBegin{0.0f};
		glm::vec4 ColorEnd{0.0f};
		float SizeBegin = 0.0f;
		float SizeEnd = 0.0f;
		float LifeTime = 1.0f;
		float RemainingLifeRime = 0.0f;

		inline float GetSize() const
		{
			return glm::mix(SizeEnd, SizeBegin, GetLife());
		}

		constexpr float GetLife() const
		{
			return RemainingLifeRime / LifeTime;
		}

		inline glm::vec4 GetColor() const
		{
			auto life = GetLife();
			auto color = glm::mix(ColorEnd, ColorBegin, life);
			color.a *= life;
			return color;
		}

		inline Transform GetTransform() const
		{
			Transform result;
			result.SetTranslation(Position);
			result.Angle = Rotation;
			auto size = GetSize();
			result.SetScale({size, size});
			return result;
		}
	};
}