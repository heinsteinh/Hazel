#pragma once

namespace Hazel
{
	class CameraProjection
	{
	private:
		glm::vec2 viewport{0.0f};
		glm::mat4 view{1.0f};
		glm::mat4 projection{1.0f};
		glm::mat4 viewProjection{1.0f};

	public:
		glm::vec3 GetWorldPosition(const glm::vec2 &screenPosition) const;
		glm::vec2 GetScreenPosition(const glm::vec3 &worldPosition) const;
		void UpdateViewProjection(const glm::mat4 &view, const glm::mat4 &projection);

		const glm::vec2 &GetViewport() const
		{
			return viewport;
		}

		void SetViewport(const glm::vec2 &viewport)
		{
			this->viewport = viewport;
		}

		const glm::mat4 &GetView() const
		{
			return view;
		}

		const glm::mat4 &GetProjection() const
		{
			return projection;
		}

		const glm::mat4 &GetViewProjection() const
		{
			return viewProjection;
		}
	};
}