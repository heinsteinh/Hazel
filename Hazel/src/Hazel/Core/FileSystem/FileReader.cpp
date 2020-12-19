#include "FileReader.h"

#include <fstream>

namespace Hazel
{
	std::string FileReader::ReadAll(const std::string &filename)
	{
		auto result = TryReadAll(filename);
		if (!result)
		{
			throw OpenFileException(filename);
		}
		return *result;
	}

	std::optional<std::string> FileReader::TryReadAll(const std::string &filename)
	{
		std::ifstream stream(filename, std::ios::binary);
		if (!stream)
		{
			return {};
		}
		stream.seekg(0, std::ios::end);
		auto size = stream.tellg();
		if (size == -1)
		{
			return {};
		}
		std::string content(size, '\0');
		stream.seekg(0, std::ios::beg);
		stream.read(content.data(), size);
		return content;
	}
}