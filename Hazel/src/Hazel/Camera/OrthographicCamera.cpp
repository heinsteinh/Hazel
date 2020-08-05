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
		transform.SetPosition(position);
		RecomputeViewProjectionMatrix();
	}

	void OrthographicCamera::SetRotation(float rotation)
	{
		transform.Angle = rotation;
		RecomputeViewProjectionMatrix();
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

	void OrthographicCamera::RecomputeViewProjectionMatrix()
	{
		viewProjectionMatrix = viewport.ToMatrix() * ComputeViewMatrix();
	}
}