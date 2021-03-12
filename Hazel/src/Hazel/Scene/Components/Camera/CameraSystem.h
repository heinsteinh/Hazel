#pragma once

#include "Hazel/Scene/ComponentSystem/ComponentSystem.h"
#include "CameraComponent.h"
#include "Private/SceneCamera.h"

namespace Hazel
{
	class CameraSystem : public ComponentSystem
	{
	public:
		virtual void OnUpdate(Scene &scene) override
		{
			SceneCamera::UpdateCamera(scene);
		}

		virtual void OnViewportResize(Scene &scene, const Box2D &viewport) override
		{
			SceneCamera::UpdateCameraViewport(scene, viewport);
		}
	};
}