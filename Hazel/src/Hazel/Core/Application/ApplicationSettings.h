#pragma once

namespace Hazel
{
	struct ApplicationSettings
	{
		bool Running = false;
		bool GuiRenderingEnabled = true;
		bool GuiKeyboardFilterEnabled = true;
		bool GuiMouseFilterEnabled = true;
	};
}