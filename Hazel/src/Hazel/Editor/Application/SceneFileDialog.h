#pragma once

#include "Hazel/Core/FileSystem/FileDialog.h"
#include "Hazel/Scene/Scene/Scene.h"

namespace Hazel
{
	class SceneFileDialog
	{
	private:
		FileDialog dialog;
		std::vector<FileDialogFilter> filters = {{"YAML files", "*.yaml"}};
		std::string filename;

	public:
		SceneFileDialog(const Window *window = nullptr)
			: dialog(window)
		{
			dialog.SetFilters(filters);
		}

		const std::string &GetFilename() const
		{
			return filename;
		}

		void SetWindow(const Window *window)
		{
			dialog.SetWindow(window);
		}

		bool Save(Scene &scene)
		{
			return filename.empty()
				? SaveAs(scene)
				: true;
		}

		bool SaveAs(Scene &scene)
		{
			auto filename = dialog.GetSaveFilename();
			if (filename.empty())
			{
				return false;
			}
			this->filename = filename;
			return true;
		}

		bool Open(Scene &scene)
		{
			auto filename = dialog.GetOpenFilename();
			if (filename.empty())
			{
				return false;
			}
			this->filename = filename;
			return true;
		}
	};
}