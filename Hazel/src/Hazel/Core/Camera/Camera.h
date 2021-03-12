#pragma once

#include "glm/gtc/matrix_transform.hpp"

#include "Hazel/Core/Geometry/Box2D.h"
#include "CameraView.h"

namespace Hazel
{
	class Camera
	{
	private:
		Box2D viewport;
		glm::vec3 position{0.0f};
		glm::mat4 view{1.0f};
		glm::mat4 projection{1.0f};
		glm::mat4 viewProjection{1.0f};

	public:
		const Box2D &GetViewport() const
		{
			return viewport;
		}

		float GetAspectRatio() const
		{
			return viewport.GetAspectRatio();
		}

		void SetViewport(const Box2D &viewport)
		{
			this->viewport = viewport;
		}

		const glm::vec3 &GetPosition() const
		{
			return position;
		}

		void SetPosition(const glm::vec3 &position)
		{
			this->position = position;
		}

		const glm::mat4 &GetViewProjection() const
		{
			return viewProjection;
		}

		void SetViewProjection(const glm::mat4 &view, const glm::mat4 &projection)
		{
			this->view = view;
			this->projection = projection;
			viewProjection = projection * view;
		}

		glm::vec3 GetWorldPosition(const glm::vec2 &screenPosition) const
		{
			return glm::unProject(
				glm::vec3(screenPosition, 0.0f),
				view,
				projection,
				CameraView::GetProjectionViewport(viewport));
		}

		glm::vec2 GetScreenPosition(const glm::vec3 &worldPosition) const
		{
			return glm::project(
				worldPosition,
				view,
				projection,
				CameraView::GetProjectionViewport(viewport));
		}
	};
}