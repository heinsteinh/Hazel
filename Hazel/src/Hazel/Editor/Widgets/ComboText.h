#pragma once

#include <vector>
#include <string>

#include "ComboBox.h"

namespace Hazel
{
	class ComboText
	{
	public:
		static bool Draw(const char *label, const std::vector<std::string> &items, size_t &selectedIndex)
		{
			bool changed = false;
			if (ComboBox::Begin(label, items[selectedIndex].c_str()))
			{
				for (size_t i = 0; i < items.size(); ++i)
				{
					bool selected = i == selectedIndex;
					if (ComboBox::DrawItem(items[i].c_str(), selected))
					{
						selectedIndex = i;
						changed = true;
					}
				}
				ComboBox::End();
			}
			return changed;
		}
	};
}