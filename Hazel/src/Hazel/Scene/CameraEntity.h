#pragma once

#include "Entity.h"
#include "Hazel/Components/CameraComponent.h"
#include "Hazel/Components/TransformComponent.h"

namespace Hazel
{
	class CameraEntity
	{
	public:
		static glm::mat4 GetViewProjection(Entity entity)
		{
			auto camera = entity.TryGetComponent<CameraComponent>();
			if (!camera)
			{
				return glm::mat4(1.0f);
			}
			auto transform = entity.TryGetComponent<TransformComponent>();
			if (!transform)
			{
				return camera->GetProjection();
			}
			return MvpMatrix::GetViewProjection(transform->GetView(), camera->GetProjection());
		}
	};
}