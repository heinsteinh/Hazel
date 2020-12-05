#pragma once

#include "SpriteRenderer.h"

namespace Hazel
{
	class SceneRenderer
	{
	private:
		SpriteRenderer spriteRenderer;

	public:
		void OnUpdate(SceneContext &context);
	};
}