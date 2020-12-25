#pragma once

#include "ControllerSettings.h"
#include "Hazel/Core/Geometry/Transform.h"
#include "Hazel/Core/Input/Input.h"

namespace Hazel
{
	class Controller
	{
	private:
		ControllerSettings settings;

	public:
		ControllerSettings &GetSettings()
		{
			return settings;
		}

		void Update(Transform &transform, const Input &input, float deltaTime)
		{
			UpdatePosition(transform, input, deltaTime);
			UpdateRotation(transform, input, deltaTime);
		}

		void UpdatePosition(Transform &transform, const Input &input, float deltaTime)
		{
			auto deltaPosition = settings.TranslationSpeed * deltaTime;
			if (input.IsKeyPressed(settings.Up))
			{
				transform.Translation.y += deltaPosition;
			}
			if (input.IsKeyPressed(settings.Down))
			{
				transform.Translation.y -= deltaPosition;
			}
			if (input.IsKeyPressed(settings.Right))
			{
				transform.Translation.x += deltaPosition;
			}
			if (input.IsKeyPressed(settings.Left))
			{
				transform.Translation.x -= deltaPosition;
			}
			transform.Translation = settings.Bounds.Clamp(transform.Translation);
		}

		void UpdateRotation(Transform &transform, const Input &input, float deltaTime)
		{
			auto rotation = glm::eulerAngles(transform.Rotation);
			auto deltaRotation = settings.RotationSpeed * deltaTime;
			if (input.IsKeyPressed(settings.ClockwiseRotation))
			{
				rotation.z -= deltaRotation;
			}
			if (input.IsKeyPressed(settings.CounterClockwiseRotation))
			{
				rotation.z += deltaRotation;
			}
			rotation.z = glm::mod(rotation.z, 2.0f * glm::pi<float>());
			transform.Rotation = glm::quat(rotation);
		}
	};
}