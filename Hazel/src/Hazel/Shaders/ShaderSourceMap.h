#pragma once

#include "ShaderType.h"

namespace Hazel
{
	class ShaderSourceMap
	{
	private:
		std::vector<std::pair<ShaderType, std::string>> sources;

	public:
		inline ShaderSourceMap()
			: sources(static_cast<size_t>(ShaderType::Count))
		{
			for (size_t i = 0; i < sources.size(); i++)
			{
				sources[i].first = static_cast<ShaderType>(i);
			}
		}

		inline const std::string &Get(ShaderType type) const
		{
			return sources[static_cast<size_t>(type)].second;
		}

		inline void Add(ShaderType type, const std::string &source)
		{
			sources[static_cast<size_t>(type)].second = source;
		}

		inline size_t GetSize() const
		{
			return sources.size();
		}

		inline bool Contains(ShaderType type) const
		{
			return !Get(type).empty();
		}

		inline bool IsValid() const
		{
			return Contains(ShaderType::Vertex) && Contains(ShaderType::Pixel);
		}

		inline auto begin() const
		{
			return sources.begin();
		}

		inline auto end() const
		{
			return sources.end();
		}

		inline const std::string &operator[](ShaderType type) const
		{
			return Get(type);
		}

		inline std::string &operator[](ShaderType type)
		{
			return sources[static_cast<size_t>(type)].second;
		}
	};
}