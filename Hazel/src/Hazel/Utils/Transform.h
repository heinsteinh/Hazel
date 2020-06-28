#pragma once

#include "glm/glm.hpp"
#include "glm/gtc/quaternion.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace Hazel
{
	struct Transform
	{
		glm::vec3 Translation{0.0f};
		glm::quat Rotation{1.0f, 0.0f, 0.0f, 1.0f};
		glm::vec3 Scale{1.0f};

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