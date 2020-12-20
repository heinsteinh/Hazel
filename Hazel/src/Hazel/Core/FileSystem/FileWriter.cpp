#include "FileWriter.h"

#include <fstream>
#include <filesystem>

namespace Hazel
{
	void FileWriter::Write(const std::string &filename, const std::string &content)
	{
		std::ofstream stream(filename);
		if (!stream)
		{
			throw OpenFileException(filename);
		}
		stream << content;
	}
}