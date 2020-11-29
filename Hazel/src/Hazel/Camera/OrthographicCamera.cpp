#include "OrthographicCamera.h"

#include "Hazel/Geometry/MvpMatrix.h"
#include "Hazel/Geometry/Viewport.h"

namespace Hazel
{
	void OrthographicCamera::SetWindowSize(const glm::vec2 &windowSize)
	{
		this->windowSize = windowSize;
		RecomputeProjectionMatrix();
	}

	void OrthographicCamera::SetZoomLevel(float zoomLevel)
	{
		this->zoomLevel = zoomLevel;
		RecomputeProjectionMatrix();
	}

	void OrthographicCamera::SetPosition(const glm::vec2 &position)
	{
		transform.SetPosition(position);
		RecomputeViewMatrix();
	}

	void OrthographicCamera::SetRotation(float rotation)
	{
		transform.Angle = rotation;
		RecomputeViewMatrix();
	}

	void OrthographicCamera::RecomputeViewMatrix()
	{
		viewMatrix = MvpMatrix::GetViewMatrix(transform);
		RecomputeViewProjectionMatrix();
	}

	void OrthographicCamera::RecomputeProjectionMatrix()
	{
		projectionMatrix = MvpMatrix::GetProjectionMatrix(Viewport::FromAspectRatio(GetAspectRatio(), GetZoomLevel()));
		RecomputeViewProjectionMatrix();
	}

	void OrthographicCamera::RecomputeViewProjectionMatrix()
	{
		viewProjectionMatrix = projectionMatrix * viewMatrix;
	}
}