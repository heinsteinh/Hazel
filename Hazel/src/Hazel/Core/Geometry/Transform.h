#pragma once

#include "glm/glm.hpp"
#include "glm/gtc/quaternion.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace Hazel
{
	struct Transform
	{
		glm::vec3 Translation{0.0f};
		glm::quat Rotation{1.0f, 0.0f, 0.0f, 0.0f};
		glm::vec3 Scale{1.0f};

		glm::vec3 Apply(const glm::vec3 &position) const
		{
			return Rotation * (Scale * position) + Translation;
		}

		glm::vec4 Apply(const glm::vec4 &position) const
		{
			return Rotation * (glm::vec4(Scale, 1.0f) * position) + glm::vec4(Translation, 0.0f);
		}

		glm::mat4 ToMatrix() const
		{
			return glm::translate(glm::mat4(1.0f), Translation)
				* static_cast<glm::mat4>(Rotation)
				* glm::scale(glm::mat4(1.0f), Scale);
		}
	};
}