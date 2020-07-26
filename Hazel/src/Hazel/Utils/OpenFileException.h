#pragma once

#include "Hazel/Core/Exception.h"

namespace Hazel
{
	class OpenFileException : public Exception
	{
	private:
		int code = 0;
		std::string filename;

	public:
		inline OpenFileException(const std::string &filename, int code)
			: Exception("Cannot open file " + filename + " (code: " + std::to_string(code) + ")."),
			code(code),
			filename(filename)
		{
		}

		constexpr int GetCode() const
		{
			return code;
		}

		constexpr const std::string &GetFilename() const
		{
			return filename;
		}
	};
}