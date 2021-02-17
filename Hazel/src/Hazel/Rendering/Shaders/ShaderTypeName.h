#pragma once

#include <string>
#include <unordered_map>

#include "ShaderType.h"

namespace Hazel
{
	class ShaderTypeName
	{
	public:
		static inline const std::string Vertex = "vertex";
		static inline const std::string Fragment = "fragment";
		static inline const std::string Unknown = "unknown";

		static inline const std::unordered_map<std::string, ShaderType> Types = {
			{Vertex, ShaderType::Vertex},
			{Fragment, ShaderType::Fragment}
		};

		static const std::string &GetName(ShaderType shaderType)
		{
			switch (shaderType)
			{
			case ShaderType::Vertex:
				return Vertex;
			case ShaderType::Fragment:
				return Fragment;
			default:
				return Unknown;
			}
		}

		static ShaderType GetType(const std::string &name)
		{
			auto i = Types.find(name);
			return i == Types.end() ? ShaderType::Unknown : i->second;
		}
	};
}