#pragma once

#include <string>
#include <unordered_map>

#include "Hazel/Rendering/Mesh/ShaderDataType.h"

namespace Hazel
{
	class GlslType
	{
	private:
		static inline const std::unordered_map<std::string, ShaderDataType> types = {
			{"float", ShaderDataType::Float},
			{"vec2", ShaderDataType::Float2},
			{"vec3", ShaderDataType::Float3},
			{"vec4", ShaderDataType::Float4},
			{"mat3", ShaderDataType::Mat3},
			{"mat4", ShaderDataType::Mat4},
			{"int", ShaderDataType::Int},
			{"ivec2", ShaderDataType::Int2},
			{"ivec3", ShaderDataType::Int3},
			{"ivec4", ShaderDataType::Int4},
			{"bool", ShaderDataType::Bool}
		};

	public:
		static ShaderDataType GetShaderDataType(const std::string &name)
		{
			auto i = types.find(name);
			return i == types.end() ? ShaderDataType::Unknown : i->second;
		}
	};
}