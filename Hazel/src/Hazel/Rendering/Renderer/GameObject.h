#pragma once

#include "DrawData.h"
#include "RigidBody.h"

namespace Hazel
{
	class GameObject : public RigidBody
	{
	private:
		DrawData drawData;

	public:
		inline GameObject(const DrawData &drawData, const Transform &transform = {})
			: RigidBody(transform),
			drawData(drawData)
		{
		}

		constexpr const DrawData &GetDrawData() const
		{
			return drawData;
		}

		constexpr DrawData &GetDrawData()
		{
			return drawData;
		}

		inline DrawData &GetUpdatedDrawData()
		{
			ApplyTransform();
			return drawData;
		}

		inline void ApplyTransform()
		{
			auto matrix = GetTransform().ToMatrix();
			for (auto &mesh : drawData.Meshes)
			{
				mesh.Position = matrix * mesh.Position;
			}
		}
	};
}