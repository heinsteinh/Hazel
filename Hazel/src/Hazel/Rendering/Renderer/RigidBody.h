#pragma once

#include "Hazel/Utils/Transform.h"

namespace Hazel
{
	class RigidBody
	{
	private:
		bool moved = false;
		Transform transform;

	public:
		constexpr RigidBody() = default;

		constexpr RigidBody(const Transform &transform)
			: moved(true),
			transform(transform)
		{
		}

		virtual ~RigidBody() = default;

		constexpr bool HasMoved() const
		{
			return moved;
		}

		constexpr void SetMoved(bool moved)
		{
			this->moved = moved;
		}

		constexpr const Transform &GetTransform() const
		{
			return transform;
		}

		constexpr void Translate(const glm::vec3 &translation)
		{
			moved = true;
			transform.Translation += translation;
		}

		constexpr void SetTranslation(const glm::vec3 &translation)
		{
			moved = true;
			transform.Translation = translation;
		}

		constexpr void Rotate(const glm::quat &rotation)
		{
			moved = true;
			transform.Rotation = rotation * transform.Rotation;
		}

		constexpr void SetRotation(const glm::quat &rotation)
		{
			moved = true;
			transform.Rotation = rotation;
		}

		constexpr void Scale(const glm::vec3 &scale)
		{
			moved = true;
			transform.Scale *= scale;
		}

		constexpr void SetScale(const glm::vec3 &scale)
		{
			moved = true;
			transform.Scale = scale;
		}
	};
}