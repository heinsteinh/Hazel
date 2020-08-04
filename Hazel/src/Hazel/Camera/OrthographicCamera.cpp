#include "OrthographicCamera.h"

namespace Hazel
{
	OrthographicCamera::OrthographicCamera(float aspectRatio)
		: viewport({aspectRatio})
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
		viewport = {aspectRatio, zoomLevel};
		RecomputeViewProjectionMatrix();
	}

	void OrthographicCamera::SetPosition(const glm::vec2 &position)
	{
		transform.SetTranslation(position);
		RecomputeViewProjectionMatrix();
	}

	void OrthographicCamera::SetRotation(float rotation)
	{
		transform.Angle = rotation;
		RecomputeViewProjectionMatrix();
	}

	void OrthographicCamera::RecomputeViewProjectionMatrix()
	{
		viewProjectionMatrix = viewport.ToMatrix() * transform.ToInverseMatrix();
	}
}