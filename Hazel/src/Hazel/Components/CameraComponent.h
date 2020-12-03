#pragma once

#include "Hazel/Geometry/MvpMatrix.h"
#include "Hazel/Geometry/Size.h"
#include "Hazel/Scene/Entity.h"

namespace Hazel
{
	struct CameraComponent
	{
		ProjectionInfo ProjectionInfo;

		glm::mat4 GetProjection()
		{
			return MvpMatrix::GetOrthographicProjection(ProjectionInfo);
		}

		void OnViewportResize(const glm::vec2 &viewport)
		{
			ProjectionInfo.AspectRatio = Size::GetAspectRatio(viewport);
		}
	};

	template<>
	inline void OnAddComponent<CameraComponent>(SceneContext &context, Entity entity)
	{
		entity.GetComponent<CameraComponent>().OnViewportResize(context.Viewport);
	};
}