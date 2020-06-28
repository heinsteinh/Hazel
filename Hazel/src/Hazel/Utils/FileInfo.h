#pragma once

namespace Hazel
{
	class FileInfo
	{
		static inline std::string GetDirectory(const std::string &filename)
		{
			size_t offset = filename.find_last_of("/\\");
			return offset == std::string::npos ? "" : filename.substr(0, offset);
		}

		static inline std::string GetBaseName(const std::string &filename)
		{
			size_t start = filename.find_last_of("/\\");
			start = start == std::string::npos ? 0 : start + 1;
			size_t end = filename.rfind('.');
			end = end == std::string::npos ? filename.size() : end;
			return filename.substr(start, (end > start ? end : filename.size()) - start);
		}

		static inline std::string GetExtension(const std::string &filename)
		{
			size_t offset = filename.find('.');
			return offset == std::string::npos
				? ""
				: filename.substr(offset + 1, filename.size() - offset);
		}
	};
}