#pragma once

#include "Core/Drawer.h"
#include "Scene.h"

namespace Hazel
{
	class Renderer
	{
	private:
		Drawer &drawer;

	public:
		Renderer(Drawer &drawer);

		void BeginScene();
		void Submit(const Scene &scene);
		void EndScene();
	};
}