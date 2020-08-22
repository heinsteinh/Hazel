#pragma once

namespace Hazel
{
	struct Transform
	{
		glm::vec3 Position{0.0f};
		float Angle = 0.0f;
		glm::vec3 Axis = {0.0f, 0.0f, 1.0f};
		glm::vec3 Scale{1.0f};

		constexpr void SetPosition(const glm::vec2 &position)
		{
			Position = {position.x, position.y, 0.0f};
		}

		constexpr void Translate(const glm::vec2 &translation)
		{
			Position += glm::vec3(translation.x, translation.y, 0.0f);
		}

		inline glm::quat GetRotation() const
		{
			return glm::angleAxis(Angle, Axis);
		}

		constexpr void SetScale(const glm::vec2 &scale)
		{
			Scale = {scale.x, scale.y, 1.0f};
		}

		constexpr void SetScale(float scale)
		{
			Scale = {scale, scale, scale};
		}

		constexpr void Rescale(const glm::vec2 &scale)
		{
			Scale.x *= scale.x;
			Scale.y *= scale.y;
		}

		inline glm::mat4 ToMatrix() const
		{
			return glm::scale(
				glm::rotate(
					glm::translate(
						glm::mat4(1.0f),
						Position),
					Angle,
					Axis),
				Scale);
		}
	};
}