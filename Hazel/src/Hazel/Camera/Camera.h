#pragma once

#include "Hazel/Geometry/Size.h"
#include "Hazel/Geometry/MvpMatrix.h"

namespace Hazel
{
	class Camera
	{
	private:
		glm::vec2 windowSize{0.0f};
		OrthographicViewport viewport;
		glm::mat4 projection{1.0f};

	public:
		const glm::vec2 &GetWindowSize() const
		{
			return windowSize;
		}

		void SetWindowSize(const glm::vec2 &windowSize)
		{
			this->windowSize = windowSize;
			viewport.AspectRatio = Size::GetAspectRatio(windowSize);
			RecomputeProjection();
		}

		const OrthographicViewport &GetViewport() const
		{
			return viewport;
		}

		void SetOrthographicSize(float size)
		{
			viewport.Size = size;
			RecomputeProjection();
		}

		const glm::mat4 &GetProjection() const
		{
			return projection;
		}

	private:
		void RecomputeProjection()
		{
			projection = MvpMatrix::GetOrthographicProjection(viewport);
		}
	};
}