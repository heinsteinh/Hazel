#pragma once

#include "Hazel\Input\Input.h"
#include "OrthographicCamera.h"
#include "OrthographicCameraControllerSettings.h"

namespace Hazel
{
	struct OrthographicCameraControllerInfo
	{
		Input &Input;
		OrthographicCamera &Camera;
		OrthographicCameraControllerSettings Settings;
	};
}