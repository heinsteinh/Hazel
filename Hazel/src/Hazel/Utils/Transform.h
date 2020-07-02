#pragma once

namespace Hazel
{
	struct Transform
	{
		glm::vec3 Translation{0.0f};
		glm::quat Rotation{1.0f, 0.0f, 0.0f, 0.0f};
		glm::vec3 Scale{1.0f};

		inline glm::vec3 Apply(const glm::vec3 &position) const
		{
			return Scale * Rotation * (position + Translation);
		}

		inline glm::mat4 Apply(const glm::mat4 &matrix) const
		{
			return glm::scale(
				glm::rotate(
					glm::translate(
						matrix,
						Translation),
					glm::angle(Rotation),
					glm::axis(Rotation)),
				Scale);
		}

		inline glm::mat4 ToMatrix() const
		{
			return Apply(glm::mat4(1.0f));
		}
	};
}