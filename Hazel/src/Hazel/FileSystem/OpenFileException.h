#pragma once

#include "Hazel/Exceptions/Exception.h"

namespace Hazel
{
	class OpenFileException : public Exception
	{
	private:
		int code = 0;
		std::string filename;

	public:
		inline OpenFileException(const std::string &filename, int code)
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