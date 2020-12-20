#pragma once

#include "entt/entt.hpp"

#include "Hazel/Core/Camera/CameraInfo.h"

namespace Hazel
{
	class SceneCamera
	{
	private:
		entt::entity entity = entt::null;
		CameraInfo info;

	public:
		SceneCamera() = default;

		void Update(entt::registry &registry);
		glm::vec3 GetWorldPosition(const glm::vec2 &screenPosition) const;
		glm::vec2 GetScreenPosition(const glm::vec3 &worldPosition) const;

		bool IsValid() const
		{
			return entity != entt::null;
		}

		entt::entity GetEntity() const
		{
			return entity;
		}

		void SetEntity(entt::entity entity, entt::registry &registry)
		{
			this->entity = entity;
			Update(registry);
		}

		const Rectangle &GetViewport() const
		{
			return info.Viewport;
		}

		void SetViewport(const Rectangle &viewport)
		{
			info.Viewport = viewport;
		}

		const glm::mat4 &GetView() const
		{
			return info.View;
		}

		const glm::mat4 &GetProjection() const
		{
			return info.Projection;
		}

		const glm::mat4 &GetViewProjection() const
		{
			return info.ViewProjection;
		}
	};
}