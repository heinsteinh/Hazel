#pragma once

namespace Hazel
{
	class Filename
	{
	public:
		static std::string GetDirectory(const std::string &filename);
		static std::string GetBaseName(const std::string &filename);
		static std::string GetExtension(const std::string &filename);
	};
}