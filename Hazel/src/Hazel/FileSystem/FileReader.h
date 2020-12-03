#pragma once

#include "OpenFileException.h"

namespace Hazel
{
	class FileReader
	{
	public:
		static std::string ReadAll(const std::string &filename);
		static std::optional<std::string> TryReadAll(const std::string &filename);
		static std::string ReadFile(FILE *stream);
	};
}