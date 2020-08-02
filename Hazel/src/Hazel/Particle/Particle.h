#pragma once

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

		constexpr float GetLife() const
		{
			return RemainingLifeRime / LifeTime;
		}

		inline glm::vec4 GetColor() const
		{
			auto life = GetLife();
			auto color = glm::lerp(ColorEnd, ColorBegin, life);
			color.a *= life;
			return color;
		}

		inline float GetSize() const
		{
			return glm::lerp(SizeEnd, SizeBegin, GetLife());
		}

		inline glm::mat4 GetTransform() const
		{
			auto size = GetSize();
			return glm::translate(glm::mat4(1.0f), {Position.x, Position.y, 0.0f})
				* glm::rotate(glm::mat4(1.0f), Rotation, {0.0f, 0.0f, 1.0f})
				* glm::scale(glm::mat4(1.0f), {size, size, 1.0f});
		}
	};
}