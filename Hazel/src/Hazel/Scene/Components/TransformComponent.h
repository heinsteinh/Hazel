#pragma once

#include "Hazel/Core/Geometry/MvpMatrix.h"

namespace Hazel
{
	struct TransformComponent
	{
		Transform Transform;
		glm::vec3 EulerHint{0.0f};

		void RecomputeRotation()
		{
			Transform.Rotation = glm::quat(glm::radians(EulerHint));
		}

		void RecomputeEulerHint()
		{
			EulerHint = glm::degrees(glm::eulerAngles(Transform.Rotation));
		}

		glm::mat4 GetModel() const
		{
			return Transform.ToMatrix();
		}

		glm::mat4 GetView() const
		{
			return MvpMatrix::GetView(Transform);
		}
	};
}