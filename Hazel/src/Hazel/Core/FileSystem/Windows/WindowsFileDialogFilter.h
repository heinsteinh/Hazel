#pragma once

#include <vector>
#include <string>
#include <sstream>

#include "Hazel/Core/FileSystem/FileDialogFilter.h"

namespace Hazel
{
	class WindowsFileDialogFilter
	{
	public:
		static std::string CreateFilter(const std::vector<FileDialogFilter> &filters)
		{
			size_t size = filters.empty() ? 2 : 1;
			for (const auto &[description, pattern] : filters)
			{
				size += description.size() + pattern.size() + 2;
			}
			std::string result(size, '\0');
			auto position = result.data();
			for (const auto &[description, pattern] : filters)
			{
				description.copy(position, description.size());
				position += description.size() + 1;
				pattern.copy(position, pattern.size());
				position += pattern.size() + 1;
			}
			return result;
		}
	};
}