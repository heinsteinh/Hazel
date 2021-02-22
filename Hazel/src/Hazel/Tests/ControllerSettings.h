#pragma once

#include "Hazel/Core/Input/Key.h"
#include "Hazel/Core/Geometry/Box3D.h"

namespace Hazel
{
	struct ControllerSettings
	{
		Key Up = Key::W;
		Key Down = Key::S;
		Key Right = Key::D;
		Key Left = Key::A;
		Key ClockwiseRotation = Key::Q;
		Key CounterClockwiseRotation = Key::E;
		float TranslationSpeed = 1.0f;
		float RotationSpeed = 1.0f;
		Box3D Bounds = {{-1.0f, -1.0f, 0.1f}, {1.0f, 1.0f, 10.0f}};
	};
}