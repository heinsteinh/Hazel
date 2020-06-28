#pragma once

#include "Hazel/Utils/Transform.h"

namespace Hazel
{
	class RigidBody
	{
	private:
		Transform transform;

	public:
		constexpr RigidBody() = default;

		constexpr RigidBody(const Transform &transform)
			: transform(transform)
		{
		}

		virtual ~RigidBody() = default;

		constexpr const Transform &GetTransform() const
		{
			return transform;
		}

		constexpr void Translate(const glm::vec3 &translation)
		{
			transform.Translation += translation;
		}

		constexpr void SetTranslation(const glm::vec3 &translation)
		{
			transform.Translation = translation;
		}

		constexpr void Rotate(const glm::quat &rotation)
		{
			transform.Rotation = rotation * transform.Rotation;
		}

		constexpr void SetRotation(const glm::quat &rotation)
		{
			transform.Rotation = rotation;
		}

		constexpr void Scale(const glm::vec3 &scale)
		{
			transform.Scale *= scale;
		}

		constexpr void SetScale(const glm::vec3 &scale)
		{
			transform.Scale = scale;
		}
	};
}