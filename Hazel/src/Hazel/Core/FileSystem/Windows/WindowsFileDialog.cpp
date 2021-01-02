#ifdef HZ_WINDOWS

#include "Hazel/Core/FileSystem/FileDialog.h"

#include <filesystem>

#include <Windows.h>
#include <commdlg.h>

#include "GLFW/glfw3.h"
#define GLFW_EXPOSE_NATIVE_WIN32
#include "GLFW/glfw3native.h"

#include "Hazel/Core/FileSystem/Filename.h"
#include "WindowsFileDialogFilter.h"

namespace Hazel
{
	bool FileDialog::GetOpenFilename()
	{
		char buffer[512] = {};
		OPENFILENAMEA info = {};
		info.lStructSize = sizeof(OPENFILENAMEA);
		info.hwndOwner = window ? glfwGetWin32Window(window->GetHandle()) : nullptr;
		info.lpstrFile = buffer;
		info.nMaxFile = sizeof(buffer);
		auto filterCode = WindowsFileDialogFilter::CreateFilter(filters);
		info.lpstrFilter = filterCode.c_str();
		info.lpstrInitialDir = directory.c_str();
		info.nFilterIndex = 1;
		info.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_NOCHANGEDIR;
		if (GetOpenFileNameA(&info) == TRUE)
		{
			filename = info.lpstrFile;
			return true;
		}
		return false;
	}

	bool FileDialog::GetSaveFilename()
	{
		char buffer[512] = {};
		OPENFILENAMEA info = {};
		info.lStructSize = sizeof(OPENFILENAME);
		info.hwndOwner = window ? glfwGetWin32Window(window->GetHandle()) : nullptr;
		info.lpstrFile = buffer;
		info.nMaxFile = sizeof(buffer);
		info.lpstrInitialDir = directory.c_str();
		auto filterCode = WindowsFileDialogFilter::CreateFilter(filters);
		info.lpstrFilter = filterCode.c_str();
		info.nFilterIndex = 1;
		info.Flags = OFN_PATHMUSTEXIST | OFN_OVERWRITEPROMPT | OFN_NOCHANGEDIR;
		std::string extension;
		if (!filters.empty())
		{
			extension = Filename::GetExtension(filters[0].Pattern);
		}
		info.lpstrDefExt = extension.c_str();
		if (GetSaveFileNameA(&info) == TRUE)
		{
			filename = info.lpstrFile;
			return true;
		}
		return false;
	}
}

#endif