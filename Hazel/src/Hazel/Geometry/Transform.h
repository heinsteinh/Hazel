#pragma once

namespace Hazel
{
	struct Transform
	{
		glm::vec3 Translation{0.0f};
		float Angle = 0.0f;
		glm::vec3 Axis = {0.0f, 0.0f, 1.0f};
		glm::vec3 Scale{1.0f};

		constexpr void SetTranslation(const glm::vec2 &translation)
		{
			Translation = {translation.x, translation.y, 0.0f};
		}

		constexpr void SetScale(const glm::vec2 &scale)
		{
			Scale = {scale.x, scale.y, 1.0f};
		}

		inline glm::mat4 ToMatrix() const
		{
			return glm::scale(
				glm::rotate(
					glm::translate(
						glm::mat4(1.0f),
						Translation),
					Angle,
					Axis),
				Scale);
		}

		inline glm::mat4 ToInverseMatrix() const
		{
			return glm::translate(
				glm::rotate(
					glm::scale(
						glm::mat4(1.0f),
						1.0f / Scale),
					-Angle,
					Axis),
				-Translation);
		}
	};
}