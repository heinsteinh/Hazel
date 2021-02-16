#pragma once

#include "Hazel/Scene/Entity/Entity.h"
#include "Hazel/Scene/Components/TransformComponent.h"

namespace Hazel
{
	class EntityComparator
	{
	public:
		static bool CompareZCoordinates(Entity left, Entity right)
		{
			return GetZCoordinate(left) < GetZCoordinate(right);
		}

	private:
		static float GetZCoordinate(Entity entity)
		{
			auto transform = entity.TryGetComponent<TransformComponent>();
			return transform ? transform->Transform.Translation.z : 0.0f;
		}
	};
}