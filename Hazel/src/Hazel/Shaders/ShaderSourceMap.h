#pragma once

#include "ShaderType.h"

namespace Hazel
{
	class ShaderSourceMap
	{
	private:
		std::vector<std::pair<ShaderType, std::string>> sources;

	public:
		ShaderSourceMap()
			: sources(static_cast<size_t>(ShaderType::Count))
		{
			for (size_t i = 0; i < sources.size(); i++)
			{
				sources[i].first = static_cast<ShaderType>(i);
			}
		}

		const std::string &Get(ShaderType type) const
		{
			return sources[static_cast<size_t>(type)].second;
		}

		void Add(ShaderType type, const std::string &source)
		{
			sources[static_cast<size_t>(type)].second = source;
		}

		size_t GetSize() const
		{
			return sources.size();
		}

		bool Contains(ShaderType type) const
		{
			return !Get(type).empty();
		}

		bool IsValid() const
		{
			return Contains(ShaderType::Vertex) && Contains(ShaderType::Pixel);
		}

		auto begin() const
		{
			return sources.begin();
		}

		auto end() const
		{
			return sources.end();
		}

		const std::string &operator[](ShaderType type) const
		{
			return Get(type);
		}

		std::string &operator[](ShaderType type)
		{
			return sources[static_cast<size_t>(type)].second;
		}
	};
}