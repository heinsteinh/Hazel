#pragma once

namespace Hazel
{
	struct TreeNodeSettings
	{
		bool Selected = false;
		bool DefaultOpen = false;
		bool OpenOnArrow = false;
		bool Framed = false;
		bool SpanAvailableWidth = false;
	};
}