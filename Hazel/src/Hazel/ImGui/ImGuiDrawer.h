#pragma once

namespace Hazel
{
	class ImGuiDrawer
	{
	public:
		virtual ~ImGuiDrawer() = default;

		virtual void Init() = 0;
		virtual void Shutdown() = 0;
		virtual void CreateNewFrame() = 0;
		virtual void RenderDrawData() = 0;
	};
}