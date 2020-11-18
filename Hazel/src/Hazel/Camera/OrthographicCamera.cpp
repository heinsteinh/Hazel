#include "OrthographicCamera.h"

namespace Hazel
{
	void OrthographicCamera::SetAspectRatio(float aspectRatio)
	{
		viewport.AspectRatio = aspectRatio;
		RecomputeProjectionMatrix();
	}

	void OrthographicCamera::SetZoomLevel(float zoomLevel)
	{
		viewport.ZoomLevel = zoomLevel;
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

	glm::mat4 OrthographicCamera::ComputeViewMatrix() const
	{
		return glm::rotate(
			glm::translate(
				glm::mat4(1.0f),
				transform.Position),
			transform.Angle,
			transform.Axis);
	}

	void OrthographicCamera::RecomputeViewMatrix()
	{
		viewMatrix = ComputeViewMatrix();
		RecomputeViewProjectionMatrix();
	}

	void OrthographicCamera::RecomputeProjectionMatrix()
	{
		projectionMatrix = viewport.ToProjectionMatrix();
		RecomputeViewProjectionMatrix();
	}

	void OrthographicCamera::RecomputeViewProjectionMatrix()
	{
		viewProjectionMatrix = projectionMatrix * viewMatrix;
	}
}