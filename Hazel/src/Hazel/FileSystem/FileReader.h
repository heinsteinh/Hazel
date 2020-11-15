#pragma once

#include "OpenFileException.h"

namespace Hazel
{
	class FileReader
	{
	public:
		static inline std::string ReadAll(const std::string &filename)
		{
			FILE *stream = nullptr;
			auto code = fopen_s(&stream, filename.c_str(), "rb");
			if (!stream)
			{
				throw OpenFileException(filename, code);
			}
			return ReadFile(stream);
		}

		static inline std::optional<std::string> TryReadAll(const std::string &filename)
		{
			FILE *stream = nullptr;
			fopen_s(&stream, filename.c_str(), "rb");
			return stream ? ReadFile(stream) : std::optional<std::string>();
		}

		static inline std::string ReadFile(FILE *stream)
		{
			fseek(stream, 0, SEEK_END);
			size_t size = ftell(stream);
			rewind(stream);
			std::string result;
			result.resize(size);
			fread(result.data(), sizeof(char), size, stream);
			return result;
		}
	};
}