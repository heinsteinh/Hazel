#pragma once

#include "Hazel/Geometry/MvpMatrix.h"

namespace Hazel
{
	struct TransformComponent
	{
		Transform Transform;

		glm::mat4 GetModel()
		{
			return MvpMatrix::GetModel(Transform);
		}

		glm::mat4 GetView()
		{
			return MvpMatrix::GetView(Transform);
		}
	};
}