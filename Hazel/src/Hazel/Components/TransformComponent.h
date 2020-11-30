#pragma once

#include "Hazel/Geometry/Transform.h"

namespace Hazel
{
	struct TransformComponent
	{
		Transform Transform;

		operator const Hazel::Transform &() const
		{
			return Transform;
		}
	};
}