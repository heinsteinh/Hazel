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
		std::string filename;

	public:
		FileDialog() = default;

		FileDialog(const Window &window)
			: window(&window)
		{
		}

		bool GetOpenFilename();
		bool GetSaveFilename();

		const std::string &GetFilename() const
		{
			return filename;
		}

		bool GetSaveFilenameIfEmpty()
		{
			return filename.empty() ? GetSaveFilename() : true;
		}

		void SetWindow(const Window *window)
		{
			this->window = window;
		}

		void ClearFilters()
		{
			filters.clear();
		}

		void SetFilters(const std::vector<FileDialogFilter> &filters)
		{
			this->filters = filters;
		}

		void AddFilter(const FileDialogFilter &filter)
		{
			filters.push_back(filter);
		}

		void SetDirectory(const std::string &directory)
		{
			this->directory = directory;
		}
	};
}