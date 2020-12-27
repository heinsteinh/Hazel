#pragma once

#include <vector>
#include <string>
#include <filesystem>

#include "Hazel/Core/Window/Window.h"
#include "FileDialogFilter.h"

namespace Hazel
{
	class FileDialog
	{
	private:
		const Window *window = nullptr;
		std::vector<FileDialogFilter> filters;
		std::string directory = std::filesystem::current_path().string();

	public:
		FileDialog(const Window &window);

		std::string GetOpenFilename();
		std::string GetSaveFilename();

		void ClearFilters()
		{
			filters.clear();
		}

		void SetFilters(const std::vector<FileDialogFilter> &filters)
		{
			this->filters = filters;
		}

		void AddFilter(const FileDialogFilter filter)
		{
			filters.push_back(filter);
		}

		void SetDirectory(const std::string &directory)
		{
			this->directory = directory;
		}
	};
}