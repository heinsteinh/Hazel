#pragma once

#include <cstdio>
#include <string>
#include <optional>

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