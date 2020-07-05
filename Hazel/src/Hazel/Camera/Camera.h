#pragma once

#include "Hazel/Utils/Rectangle.h"

namespace Hazel
{
	struct Camera
	{
		glm::vec3 Position = {0.0f, 0.0f, 1.0f};
		glm::vec3 Target = {0.0f, 0.0f, 0.0f};
		glm::vec3 UpAxis = {0.0f, 0.0f, 1.0f};
		float FieldOfView = glm::radians(45.0f);
		Rectangle Viewport = {-1.0f, 1.0f, -1.0f, 1.0f};
		float NearClippingPlane = 0.1f;
		float FarClippingPlane = 100.0f;

		inline glm::mat4 GetViewMatrix() const
		{
			return glm::lookAt(Position, Target, UpAxis);
		}

		inline glm::mat4 GetProjectionMatrix() const
		{
			return glm::perspective(
				FieldOfView,
				Viewport.GetAspectRatio(),
				NearClippingPlane,
				FarClippingPlane);
		}

		inline glm::mat4 GetViewProjectionMatrix() const
		{
			return GetProjectionMatrix() * GetViewMatrix();
		}
	};
}