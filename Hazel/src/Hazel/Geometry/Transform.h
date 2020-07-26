#pragma once

namespace Hazel
{
	class Transform
	{
	private:
		glm::vec3 translation{0.0f};
		glm::quat rotation = {1.0f, 0.0f, 0.0f, 0.0f};
		glm::vec3 scale{1.0f};
		glm::mat4 matrix{1.0f};

	public:
		constexpr const glm::vec3 &GetTranslation() const
		{
			return translation;
		}

		inline void Translate(const glm::vec3 &translation)
		{
			this->translation += translation;
			matrix = ComputeMatrix();
		}

		inline void SetTranslation(const glm::vec3 &translation)
		{
			this->translation = translation;
			matrix = ComputeMatrix();
		}

		constexpr const glm::quat &GetRotation() const
		{
			return rotation;
		}

		inline void Rotate(const glm::quat &rotation)
		{
			this->rotation = rotation * this->rotation;
			matrix = ComputeMatrix();
		}

		inline void SetRotation(const glm::quat &rotation)
		{
			this->rotation = rotation;
			matrix = ComputeMatrix();
		}

		constexpr const glm::vec3 &GetScale() const
		{
			return scale;
		}

		inline void Scale(const glm::vec3 &scale)
		{
			this->scale *= scale;
			matrix = ComputeMatrix();
		}

		inline void SetScale(const glm::vec3 &scale)
		{
			this->scale = scale;
			matrix = ComputeMatrix();
		}

		constexpr const glm::mat4 &GetMatrix() const
		{
			return matrix;
		}

	private:
		inline glm::mat4 ComputeMatrix() const
		{
			return glm::translate(
				static_cast<glm::mat4>(rotation) * glm::scale(glm::mat4(1.0f), scale),
				translation);
		}
	};
}