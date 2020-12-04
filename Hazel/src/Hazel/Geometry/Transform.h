#pragma once

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
	};
}