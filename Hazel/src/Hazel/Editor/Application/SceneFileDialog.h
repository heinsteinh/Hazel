#pragma once

#include "Hazel/Core/FileSystem/FileDialog.h"
#include "Hazel/Scene/Scene/Scene.h"
#include "Hazel/Scene/Serialization/SceneSerializer.h"

namespace Hazel
{
	class SceneFileDialog
	{
	private:
		FileDialog dialog;
		std::vector<FileDialogFilter> filters = {{"YAML files", "*.yaml"}};
		std::string lastFilename;

	public:
		SceneFileDialog(const Window *window = nullptr)
			: dialog(window)
		{
			dialog.SetFilters(filters);
		}

		void SetWindow(const Window *window)
		{
			dialog.SetWindow(window);
		}

		void Save(Scene &scene)
		{
			lastFilename.empty()
				? SaveAs(scene)
				: SceneSerializer::Serialize(scene, lastFilename);
		}

		void SaveAs(Scene &scene)
		{
			auto filename = dialog.GetSaveFilename();
			if (!filename.empty())
			{
				lastFilename = filename;
				SceneSerializer::Serialize(scene, filename);
			}
		}

		void Open(Scene &scene)
		{
			auto filename = dialog.GetOpenFilename();
			if (!filename.empty())
			{
				lastFilename = filename;
				SceneSerializer::Deserialize(scene, filename);
			}
		}
	};
}