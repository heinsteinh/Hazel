#pragma once

#include <string>

#include "Hazel/Editor/Widgets/InputText.h"

namespace Hazel
{
	class TagWidget
	{
	public:
		static bool Draw(std::string &tag)
		{
			return InputText::Draw("##Tag", tag);
		}
	};
}