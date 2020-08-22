#pragma once

#include "Hazel/RenderApi/ImGuiDrawer.h"
#include "ImGuiContext.h"
#include "Hazel/Geometry/Size.h"

namespace Hazel
{
	class ImGuiRenderer
	{
	private:
		ImGuiDrawer &drawer;
		ImGuiContext context;

	public:
		ImGuiRenderer(ImGuiDrawer &drawer);
		~ImGuiRenderer();

		void OnContextCurrent();
		void Init();
		void Shutdown();
		void Begin();
		void End();
		void SetDisplaySize(Size size);

	private:
		void UpdateWindows();
	};
}