#pragma once

#include "spdlog/fmt/fmt.h"

#include "Hazel/Core/Exceptions/Exception.h"

namespace Hazel
{
	class OpenFileException : public Exception
	{
	private:
		std::string filename;

	public:
		OpenFileException(const std::string &filename)
			: Exception(fmt::format("Cannot open file '{}'.", filename)),
			filename(filename)
		{
		}

		constexpr const std::string &GetFilename() const
		{
			return filename;
		}
	};
}