#pragma once

#include <string>

namespace Hazel
{
	class OpenGLShaderModule
	{
	private:
		uint32_t id = 0;

	public:
		OpenGLShaderModule() = default;
		OpenGLShaderModule(int type, const std::string &source);
		OpenGLShaderModule(const OpenGLShaderModule &other) = delete;
		OpenGLShaderModule(OpenGLShaderModule &&other) noexcept;
		~OpenGLShaderModule();

		bool IsCompiled() const;
		std::string GetInfoLog() const;

		OpenGLShaderModule &operator=(const OpenGLShaderModule &other) = delete;
		OpenGLShaderModule &operator=(OpenGLShaderModule &&other) noexcept;

		uint32_t GetId() const
		{
			return id;
		}

		bool IsValid() const
		{
			return id != 0;
		}
	};
}