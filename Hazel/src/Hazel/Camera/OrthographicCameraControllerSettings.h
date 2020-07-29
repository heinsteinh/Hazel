#pragma once

#include "Hazel/Input/Key.h"
#include "OrthographicCameraInfo.h"
#include "Hazel/Geometry/Boundary2D.h"

namespace Hazel
{
	struct OrthographicCameraControllerSettings
	{
		Key Up = Key::W;
		Key Down = Key::S;
		Key Right = Key::D;
		Key Left = Key::A;
		Key ClockwiseRotation = Key::E;
		Key CounterClockwiseRotation = Key::Q;
		float TranslationSpeed = 1.0f;
		float RotationSpeed = 1.0f;
		float ZoomSpeed = 0.2f;
		Boundary2D Boundary;
	};
}