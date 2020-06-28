#pragma once

#include "Hazel/Core/Exception.h"

namespace Hazel
{
	class OpenFileException : public Exception
	{
	private:
		int code = 0;
		std::string filename;
		std::string description;

	public:
		inline OpenFileException(const std::string &filename, int code)
			: code(code),
			filename(filename),
			description("Cannot open file " + filename + " (code: " + std::to_string(code) + ").")
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

		inline virtual const std::string &GetDescription() const override
		{
			return description;
		}
	};
}