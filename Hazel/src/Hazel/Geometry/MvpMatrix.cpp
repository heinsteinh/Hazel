#include "MvpMatrix.h"

namespace Hazel
{
	glm::mat4 MvpMatrix::GetModel(const Transform &objectTransform)
	{
		return glm::translate(glm::mat4(1.0f), objectTransform.Translation)
			* static_cast<glm::mat4>(objectTransform.Rotation)
			* glm::scale(glm::mat4(1.0f), objectTransform.Scale);
	}

	glm::mat4 MvpMatrix::GetView(const Transform &cameraTransform)
	{
		return static_cast<glm::mat4>(glm::inverse(cameraTransform.Rotation))
			* glm::translate(glm::mat4(1.0f), -cameraTransform.Translation);
	}

	glm::mat4 MvpMatrix::GetOrthographicProjection(const ProjectionInfo &info)
	{
		return glm::ortho(
			-info.AspectRatio * info.OrthographicsSize,
			info.AspectRatio * info.OrthographicsSize,
			-info.OrthographicsSize,
			info.OrthographicsSize,
			info.NearClip,
			info.FarClip);
	}

	glm::mat4 MvpMatrix::GetViewProjection(const glm::mat4 &view, const glm::mat4 &projection)
	{
		return projection * view;
	}
}