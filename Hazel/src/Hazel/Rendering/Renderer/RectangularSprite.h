#pragma once

#include "GameObject.h"
#include "RectangleDrawData.h"

namespace Hazel
{
	class RectangularSprite : public GameObject
	{
	public:
		inline RectangularSprite()
			: GameObject(RectangleDrawData::Get())
		{
		}
	};
}