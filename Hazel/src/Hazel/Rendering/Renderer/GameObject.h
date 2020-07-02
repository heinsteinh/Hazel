#pragma once

#include "DrawData.h"

namespace Hazel
{
	class GameObject
	{
	private:
		DrawData drawData;

	public:
		inline GameObject(const DrawData &drawData)
			: drawData(drawData)
		{
		}

		virtual ~GameObject() = default;

		constexpr DrawData &GetDrawData()
		{
			return drawData;
		}

		constexpr const DrawData &GetDrawData() const
		{
			return drawData;
		}

		constexpr Transform &GetTransform()
		{
			return drawData.Transform;
		}

		constexpr const Transform &GetTransform() const
		{
			return drawData.Transform;
		}
	};
}