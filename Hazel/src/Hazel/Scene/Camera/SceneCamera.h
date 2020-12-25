#pragma once

#include "entt/entt.hpp"

#include "Hazel/Scene/Components/CameraComponent.h"
#include "Hazel/Scene/Components/TransformComponent.h"

namespace Hazel
{
	class SceneCamera
	{
	public:
		static entt::entity GetCameraEntity(entt::registry &registry, entt::entity cameraEntity)
		{
			if (IsValidCamera(registry, cameraEntity))
			{
				return cameraEntity;
			}
			return GetFirstCamera(registry);
		}

		static bool IsValidCamera(entt::registry &registry, entt::entity cameraEntity)
		{
			return registry.valid(cameraEntity) && registry.has<CameraComponent>(cameraEntity);
		}

		static entt::entity GetFirstCamera(entt::registry &registry)
		{
			auto view = registry.view<CameraComponent>();
			if (view.empty())
			{
				return entt::null;
			}
			return view.front();
		}

		static glm::mat4 GetViewMatrix(entt::registry &registry, entt::entity cameraEntity)
		{
			if (cameraEntity == entt::null)
			{
				return glm::mat4(1.0f);
			}
			auto component = registry.try_get<TransformComponent>(cameraEntity);
			return component ? CameraView::GetViewMatrix(component->Transform) : glm::mat4(1.0f);
		}

		static glm::mat4 GetProjectionMatrix(entt::registry &registry, entt::entity cameraEntity)
		{
			if (cameraEntity == entt::null)
			{
				return glm::mat4(1.0f);
			}
			auto component = registry.try_get<CameraComponent>(cameraEntity);
			return component ? component->Projection.ToMatrix() : glm::mat4(1.0f);
		}
	};
}