#pragma once

#include "Hazel/Camera/Camera.h"

namespace Hazel
{
	struct CameraComponent
	{
		Camera Camera;

		const glm::mat4 &GetProjection() const
		{
			return Camera.GetProjection();
		}

		void SetWindowSize(const glm::vec2 &windowSize)
		{
			Camera.SetWindowSize(windowSize);
		}
		
		void SetOrthographicSize(float size)
		{
			Camera.SetOrthographicSize(size);
		}

		operator Hazel::Camera &()
		{
			return Camera;
		}

		operator const Hazel::Camera &() const
		{
			return Camera;
		}
	};
}