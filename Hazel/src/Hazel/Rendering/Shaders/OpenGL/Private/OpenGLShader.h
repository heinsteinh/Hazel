#pragma once

#include <string>

namespace Hazel
{
	class OpenGLShader
	{
	private:
		uint32_t id = 0;

	public:
		OpenGLShader() = default;
		OpenGLShader(int type, const std::string &source);
		OpenGLShader(const OpenGLShader &other) = delete;
		OpenGLShader(OpenGLShader &&other) noexcept;
		~OpenGLShader();

		bool IsCompiled() const;
		std::string GetInfoLog() const;

		OpenGLShader &operator=(const OpenGLShader &other) = delete;
		OpenGLShader &operator=(OpenGLShader &&other) noexcept;

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