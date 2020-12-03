#include "Filename.h"

namespace Hazel
{
	std::string Filename::GetDirectory(const std::string &filename)
	{
		size_t offset = filename.find_last_of("/\\");
		return offset == std::string::npos ? "" : filename.substr(0, offset);
	}

	std::string Filename::GetBaseName(const std::string &filename)
	{
		size_t start = filename.find_last_of("/\\");
		start = start == std::string::npos ? 0 : start + 1;
		size_t end = filename.rfind('.');
		end = end == std::string::npos ? filename.size() : end;
		return filename.substr(start, (end > start ? end : filename.size()) - start);
	}

	std::string Filename::GetExtension(const std::string &filename)
	{
		size_t offset = filename.find('.');
		return offset == std::string::npos
			? std::string()
			: filename.substr(offset + 1, filename.size() - offset);
	}
}