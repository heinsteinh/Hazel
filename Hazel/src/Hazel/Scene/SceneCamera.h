#pragma once

#include "entt/entt.hpp"

#include "Hazel/Camera/CameraInfo.h"

namespace Hazel
{
	class SceneCamera
	{
	private:
		entt::entity entity = entt::null;
		entt::registry *registry = nullptr;
		CameraInfo info;

	public:
		SceneCamera(entt::registry &registry);

		void Update();
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

		void SetEntity(entt::entity entity)
		{
			this->entity = entity;
			Update();
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