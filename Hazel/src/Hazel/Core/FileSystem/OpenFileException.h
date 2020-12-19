#pragma once

#include "Hazel/Core/Exceptions/Exception.h"

namespace Hazel
{
	class OpenFileException : public Exception
	{
	private:
		int code = 0;
		std::string filename;

	public:
		OpenFileException(const std::string &filename, int code)
			: Exception(fmt::format("Cannot open file {} (code: {}).", filename, code)),
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