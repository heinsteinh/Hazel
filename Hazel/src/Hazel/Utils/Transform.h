#pragma once

namespace Hazel
{
	class Transform
	{
	private:
		glm::vec3 translation{0.0f};
		glm::quat rotation = {1.0f, 0.0f, 0.0f, 0.0f};
		glm::vec3 scale{1.0f};

	public:
		constexpr const glm::vec3 &GetTranslation() const
		{
			return translation;
		}

		constexpr void Translate(const glm::vec3 &translation)
		{
			this->translation += translation;
		}

		constexpr void SetTranslation(const glm::vec3 &translation)
		{
			this->translation = translation;
		}

		constexpr const glm::quat &GetRotation() const
		{
			return rotation;
		}

		constexpr void Rotate(const glm::quat &rotation)
		{
			this->rotation = rotation * this->rotation;
		}

		constexpr void SetRotation(const glm::quat &rotation)
		{
			this->rotation = rotation;
		}

		constexpr const glm::vec3 &GetScale() const
		{
			return scale;
		}

		constexpr void Scale(const glm::vec3 &scale)
		{
			this->scale *= scale;
		}

		constexpr void SetScale(const glm::vec3 &scale)
		{
			this->scale = scale;
		}

		inline glm::mat4 ToMatrix() const
		{
			return glm::translate(
				glm::rotate(
					glm::scale(
						glm::mat4(1.0f),
						scale),
					glm::angle(rotation),
					glm::axis(rotation)),
				translation);
		}
	};
}