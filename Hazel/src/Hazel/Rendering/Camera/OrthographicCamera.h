#pragma once

#include "Hazel/Utils/Rectangle.h"

namespace Hazel
{
	class OrthographicCamera
	{
	private:
		glm::vec3 position = {0.0f, 0.0f, 0.0f};
		float rotation;
		glm::mat4 projectionMatrix{1.0f};
		glm::mat4 viewMatrix{1.0f};
		glm::mat4 viewProjectionMatrix{1.0f};

	public:
		inline OrthographicCamera(const Rectangle &viewport = {-1.0f, 1.0f, -1.0f, 1.0f})
			: projectionMatrix(viewport.ToProjectionMatrix())
		{
			RecalculateViewProjectionMatrix();
		}

		constexpr const glm::vec3 &GetPosition() const
		{
			return position;
		}

		constexpr float GetRotation() const
		{
			return rotation;
		}

		constexpr const glm::mat4 &GetProjectionMatrix() const
		{
			return projectionMatrix;
		}

		constexpr const glm::mat4 &GetViewMatrix() const
		{
			return viewMatrix;
		}

		constexpr const glm::mat4 &GetViewProjectionMatrix() const
		{
			return viewProjectionMatrix;
		}

		inline void SetViewport(const Rectangle &viewport)
		{
			projectionMatrix = viewport.ToProjectionMatrix();
			RecalculateViewProjectionMatrix();
		}

		inline void SetPosition(const glm::vec3 &position)
		{
			this->position = position;
			RecalculateViewMatrix();
		}

		inline void SetRotation(float rotation)
		{
			this->rotation = rotation;
			RecalculateViewMatrix();
		}

	private:
		inline void RecalculateViewMatrix()
		{
			viewMatrix = ApplyTranslation(rotation ? GetRotationMatrix() : glm::mat4(1.0f));
			RecalculateViewProjectionMatrix();
		}

		inline glm::mat4 ApplyTranslation(const glm::mat4 &matrix) const
		{
			return glm::translate(matrix, -position);
		}

		inline glm::mat4 GetRotationMatrix() const
		{
			return glm::rotate(glm::mat4(1.0f), -rotation, {0.0f, 0.0f, 1.0f});
		}

		inline void RecalculateViewProjectionMatrix()
		{
			viewProjectionMatrix = projectionMatrix * viewMatrix;
		}
	};
}