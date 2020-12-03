#pragma once

namespace Hazel
{
	class CameraProjection
	{
	private:
		glm::vec2 windowSize{1.0f};
		glm::mat4 view{1.0f};
		glm::mat4 projection{1.0f};

	public:
		glm::vec3 GetWorldPosition(const glm::vec2 &screenPosition);
		glm::vec2 GetScreenPosition(const glm::vec3 &worldPosition);

		void SetWindowSize(const glm::vec2 &windowSize)
		{
			this->windowSize = windowSize;
		}

		void SetView(const glm::mat4 &view)
		{
			this->view = view;
		}

		void SetProjection(const glm::mat4 &projection)
		{
			this->projection = projection;
		}
	};
}