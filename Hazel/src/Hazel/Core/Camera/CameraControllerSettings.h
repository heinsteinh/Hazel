#pragma once

#include "Hazel/Core/Input/Key.h"
#include "Hazel/Core/Geometry/Bounds.h"

namespace Hazel
{
	struct CameraControllerSettings
	{
		Key Up = Key::W;
		Key Down = Key::S;
		Key Right = Key::D;
		Key Left = Key::A;
		Key ClockwiseRotation = Key::Q;
		Key CounterClockwiseRotation = Key::E;
		float TranslationSpeed = 1.0f;
		float RotationSpeed = 1.0f;
		float ZoomSpeed = 0.2f;
		Bounds Bounds = {{-1.0f, -1.0f, 0.1f}, {1.0f, 1.0f, 10.0f}};
	};
}