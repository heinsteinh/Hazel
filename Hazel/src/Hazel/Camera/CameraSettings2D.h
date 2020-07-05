#pragma once

namespace Hazel
{
	struct CameraSettings2D
	{
		float InitialAspectRatio = 1.0f;
		float TranslationSpeedX = 1.0f;
		float TranslationSpeedY = 1.0f;
		float RotationSpeed = 1.0f;
		float ZoomSpeed = 0.2f;
		std::optional<float> MinTranslationX;
		std::optional<float> MaxTranslationX;
		std::optional<float> MinTranslationY;
		std::optional<float> MaxTranslationY;
		std::optional<float> MinRotation;
		std::optional<float> MaxRotation;
		std::optional<float> MinZoomLevel = 0.1f;
		std::optional<float> MaxZoomLevel;
	};
}