#pragma once

#include "Hazel/Core/Exception.h"
#include "Hazel/Rendering/Shaders/ShaderTypeInfo.h"

namespace Hazel
{
	class ShaderCompilationException : public Exception
	{
	private:
		std::string description;

	public:
		inline ShaderCompilationException(ShaderType type, const std::string &infoLog)
			: description("Compilation of " + ShaderTypeInfo::GetName(type) + " shader failed: " + description)
		{
		}

		inline ShaderCompilationException(const std::string &description)
			: description(description)
		{
		}

		inline virtual const std::string &GetDescription() const override
		{
			return description;
		}
	};
}