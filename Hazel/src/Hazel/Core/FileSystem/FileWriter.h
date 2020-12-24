#pragma once

#include <string>

#include "OpenFileException.h"

namespace Hazel
{
	class FileWriter
	{
	public:
		static void Write(const std::string &filename, const std::string &content);
		static void Write(const std::string &filename, const char *content);
	};
}