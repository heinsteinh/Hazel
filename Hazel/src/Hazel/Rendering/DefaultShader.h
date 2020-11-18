#pragma once

#include "Hazel/Graphics/GraphicsContext.h"

namespace Hazel
{
	class DefaultShader
	{
	private:
		std::shared_ptr<Shader> shader;

	public:
		inline DefaultShader(GraphicsContext &graphics)
			: shader(graphics.CreateShader(ShaderInfo::FromFiles({
			{ShaderType::Vertex, R"(C:\Users\christian\source\repos\Hazel\Hazel\assets\shaders\DefaultShader.vert)"},
			{ShaderType::Pixel, R"(C:\Users\christian\source\repos\Hazel\Hazel\assets\shaders\DefaultShader.frag)"}})))
		{
		}

		inline void InitSamplers(size_t maxTextures)
		{
			std::vector<int> samplers;
			samplers.reserve(maxTextures);
			for (size_t i = 0; i < maxTextures; i++)
			{
				samplers.push_back(static_cast<int>(i));
			}
			shader->Set("u_Textures", samplers.data(), samplers.size());
		}

		inline void SetViewProjectionMatrix(const glm::mat4 &matrix)
		{
			shader->Set("u_ViewProjection", matrix);
		}

		constexpr operator const std::shared_ptr<Shader> &() const
		{
			return shader;
		}
	};
}