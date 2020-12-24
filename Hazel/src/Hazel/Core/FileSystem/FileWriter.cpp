#include "FileWriter.h"

#include <fstream>
#include <filesystem>

namespace Hazel
{
	void FileWriter::Write(const std::string &filename, const std::string &content)
	{
		Write(filename, content.c_str());
	}

	void FileWriter::Write(const std::string &filename, const char *content)
	{
		std::ofstream stream(filename);
		if (!stream)
		{
			throw OpenFileException(filename);
		}
		stream << content;
	}
}