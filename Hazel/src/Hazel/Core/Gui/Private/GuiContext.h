#pragma once

struct ImGuiContext;

namespace Hazel
{
	class GuiContext
	{
	private:
		ImGuiContext *context;

	public:
		GuiContext();
		~GuiContext();

		void MakeCurrent();
	};
}