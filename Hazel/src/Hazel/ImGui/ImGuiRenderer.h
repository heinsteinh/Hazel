#pragma once

namespace Hazel
{
	class ImGuiRenderer
	{
	public:
		virtual ~ImGuiRenderer() = default;

		virtual void CreateNewFrame() = 0;
		virtual void RenderDrawData() = 0;
	};
}