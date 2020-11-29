#pragma once

namespace Hazel
{
	struct ApplicationSettings
	{
		bool ImGuiEnabled = true;
		bool Running = false;
		bool ImGuiRenderEnabled = true;
		bool ImGuiKeyboardFilterEnabled = true;
		bool ImGuiMouseFilterEnabled = true;
	};
}