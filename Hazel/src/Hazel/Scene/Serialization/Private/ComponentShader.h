#pragma once

#include "Hazel/Core/Yaml/YamlSerializer.h"
#include "Hazel/Scene/Entity/Entity.h"
#include "Hazel/Scene/Serialization/SpriteSerializer.h"

namespace Hazel
{
	class ComponentShader
	{
	public:
		static std::shared_ptr<Shader> ExtractShader(const YamlValue &source, Entity entity)
		{
			return nullptr;
		}
	};
}