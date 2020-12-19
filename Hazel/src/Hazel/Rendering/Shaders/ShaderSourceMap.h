#pragma once

#include <array>

#include "ShaderType.h"

namespace Hazel
{
	class ShaderSourceMap
	{
	private:
		std::array<std::pair<ShaderType, std::string>, static_cast<size_t>(ShaderType::Count)> sources;

	public:
		ShaderSourceMap()
		{
			Init();
		}

		ShaderSourceMap(std::initializer_list<std::pair<ShaderType, std::string>> args)
		{
			Init();
			for (const auto &[type, source] : args)
			{
				Add(type, source);
			}
		}

		const std::string &Get(ShaderType type) const
		{
			return sources[static_cast<size_t>(type)].second;
		}

		std::string &Get(ShaderType type)
		{
			return sources[static_cast<size_t>(type)].second;
		}

		void Clear()
		{
			for (auto &[type, source] : sources)
			{
				source.clear();
			}
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
			return Get(type);
		}

	private:
		void Init()
		{
			for (size_t i = 0; i < sources.size(); i++)
			{
				sources[i].first = static_cast<ShaderType>(i);
			}
		}
	};
}