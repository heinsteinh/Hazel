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
	static constexpr size_t bufferSize = 512;

	FileDialog::FileDialog(const Window &window)
		: window(&window)
	{
	}

	std::string FileDialog::GetOpenFilename()
	{
		char buffer[bufferSize] = {};
		OPENFILENAMEA info = {};
		info.lStructSize = sizeof(OPENFILENAMEA);
		info.hwndOwner = glfwGetWin32Window(window->GetHandle());
		info.lpstrFile = buffer;
		info.nMaxFile = sizeof(buffer);
		auto filterCode = WindowsFileDialogFilter::CreateFilter(filters);
		info.lpstrFilter = filterCode.c_str();
		info.lpstrInitialDir = directory.c_str();
		info.nFilterIndex = 1;
		info.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_NOCHANGEDIR;
		return GetOpenFileNameA(&info) == TRUE ? info.lpstrFile : std::string();
	}

	std::string FileDialog::GetSaveFilename()
	{
		char buffer[bufferSize] = {};
		OPENFILENAMEA info = {};
		info.lStructSize = sizeof(OPENFILENAME);
		info.hwndOwner = glfwGetWin32Window(window->GetHandle());
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
		return GetSaveFileNameA(&info) == TRUE ? info.lpstrFile : std::string();
	}
}

#endif