#pragma once

#include "OrthographicCamera.h"
#include "CameraSettings2D.h"
#include "Hazel/Utils/Clamper.h"

namespace Hazel
{
	class OrthographicCameraController
	{
	private:
		OrthographicCamera camera;
		CameraSettings2D settings;

	public:
		inline OrthographicCameraController(const CameraSettings2D &settings)
			: settings(settings)
		{
			camera.SetAspectRatio(settings.InitialAspectRatio);
		}

		constexpr OrthographicCamera &GetCamera()
		{
			return camera;
		}

		constexpr CameraSettings2D &GetSettings()
		{
			return settings;
		}

		constexpr void OnWindowResized(Size size)
		{
			camera.SetAspectRatio(size.GetAspectRatio());
		}

		constexpr void MoveUp(float deltaTime)
		{
			camera.Position.x += settings.TranslationSpeedX * deltaTime;
			Clamper::Clamp(camera.Position.x, settings.MinTranslationX, settings.MaxTranslationX);
		}

		constexpr void MoveDown(float deltaTime)
		{
			camera.Position.x -= settings.TranslationSpeedX * deltaTime;
			Clamper::Clamp(camera.Position.x, settings.MinTranslationX, settings.MaxTranslationX);
		}

		inline void MoveRight(float deltaTime)
		{
			camera.Position.y += settings.TranslationSpeedY * deltaTime;
			Clamper::Clamp(camera.Position.y, settings.MinTranslationY, settings.MaxTranslationY);
		}

		inline void MoveLeft(float deltaTime)
		{
			camera.Position.y -= settings.TranslationSpeedY * deltaTime;
			Clamper::Clamp(camera.Position.y, settings.MinTranslationY, settings.MaxTranslationY);
		}

		inline void RotateClockwise(float deltaTime)
		{
			camera.Rotation -= settings.RotationSpeed * deltaTime;
			Clamper::Clamp(camera.Rotation, settings.MinRotation, settings.MaxRotation);
		}

		inline void RotateCounterClockwise(float deltaTime)
		{
			camera.Rotation += settings.RotationSpeed * deltaTime;
			Clamper::Clamp(camera.Rotation, settings.MinRotation, settings.MaxRotation);
		}

		inline void ZoomIn(float deltaTime)
		{
			auto zoomLevel = camera.GetZoomLevel() - settings.ZoomSpeed * deltaTime;
			Clamper::Clamp(zoomLevel, settings.MinZoomLevel, settings.MaxZoomLevel);
			camera.SetZoomLevel(zoomLevel);
		}

		inline void ZoomOut(float deltaTime)
		{
			auto zoomLevel = camera.GetZoomLevel() + settings.ZoomSpeed * deltaTime;
			Clamper::Clamp(zoomLevel, settings.MinZoomLevel, settings.MaxZoomLevel);
			camera.SetZoomLevel(zoomLevel);
		}
	};
}