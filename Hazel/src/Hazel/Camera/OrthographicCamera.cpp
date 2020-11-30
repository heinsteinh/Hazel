#include "OrthographicCamera.h"

#include "Hazel/Geometry/MvpMatrix.h"

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
		viewMatrix = MvpMatrix::GetView(transform);
		RecomputeViewProjectionMatrix();
	}

	void OrthographicCamera::RecomputeProjectionMatrix()
	{
		projectionMatrix = MvpMatrix::GetOrthographicProjection({GetAspectRatio(), GetZoomLevel()});
		RecomputeViewProjectionMatrix();
	}

	void OrthographicCamera::RecomputeViewProjectionMatrix()
	{
		viewProjectionMatrix = MvpMatrix::GetViewProjection(viewMatrix, projectionMatrix);
	}
}