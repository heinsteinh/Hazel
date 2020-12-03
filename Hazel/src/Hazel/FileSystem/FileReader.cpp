#include "FileReader.h"

namespace Hazel
{
	std::string FileReader::ReadAll(const std::string &filename)
	{
		FILE *stream = nullptr;
		auto code = fopen_s(&stream, filename.c_str(), "rb");
		if (!stream)
		{
			throw OpenFileException(filename, code);
		}
		return ReadFile(stream);
	}

	std::optional<std::string> FileReader::TryReadAll(const std::string &filename)
	{
		FILE *stream = nullptr;
		fopen_s(&stream, filename.c_str(), "rb");
		return stream ? ReadFile(stream) : std::optional<std::string>();
	}

	std::string FileReader::ReadFile(FILE *stream)
	{
		fseek(stream, 0, SEEK_END);
		size_t size = ftell(stream);
		rewind(stream);
		std::string result;
		result.resize(size);
		fread(result.data(), sizeof(char), size, stream);
		return result;
	}
}