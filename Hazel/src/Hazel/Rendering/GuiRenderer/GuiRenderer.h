#pragma once

namespace Hazel
{
	class GuiRenderer
	{
	public:
		virtual ~GuiRenderer() = default;

		virtual void CreateNewFrame() = 0;
		virtual void RenderDrawData() = 0;
	};
}