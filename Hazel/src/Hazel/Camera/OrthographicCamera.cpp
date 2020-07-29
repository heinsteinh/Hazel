#include "OrthographicCamera.h"

namespace Hazel
{
	OrthographicCamera::OrthographicCamera(const OrthographicCameraInfo &info)
		: info(info),
		viewMatrix(info.GetViewMatrix()),
		projectionMatrix(info.GetProjectionMatrix())
	{
		RecomputeViewProjectionMatrix();
	}

	void OrthographicCamera::SetAspectRatio(float aspectRatio)
	{
		SetViewport(aspectRatio, GetZoomLevel());
	}

	void OrthographicCamera::SetZoomLevel(float zoomLevel)
	{
		SetViewport(GetAspectRatio(), zoomLevel);
	}

	void OrthographicCamera::SetViewport(float aspectRatio, float zoomLevel)
	{
		std::tie(info.AspectRatio, info.ZoomLevel) = std::tie(aspectRatio, zoomLevel);
		RecomputeProjectionMatrix();
	}

	void OrthographicCamera::SetPosition(const glm::vec2 &position)
	{
		info.Position = position;
		RecomputeViewMatrix();
	}

	void OrthographicCamera::SetRotation(float rotation)
	{
		info.Rotation = rotation;
		RecomputeViewMatrix();
	}

	void OrthographicCamera::RecomputeViewMatrix()
	{
		viewMatrix = info.GetViewMatrix();
		RecomputeViewProjectionMatrix();
	}

	void OrthographicCamera::RecomputeProjectionMatrix()
	{
		projectionMatrix = info.GetProjectionMatrix();
		RecomputeViewProjectionMatrix();
	}

	void OrthographicCamera::RecomputeViewProjectionMatrix()
	{
		viewProjectionMatrix = viewMatrix * projectionMatrix;
	}
}