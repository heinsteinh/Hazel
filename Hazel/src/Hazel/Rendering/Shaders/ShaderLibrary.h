#pragma once

#include "Hazel/Rendering/RenderApi/RenderApiFactory.h"
#include "Shader.h"

namespace Hazel
{
	class ShaderLibrary
	{
	private:
		RenderApiFactory &factory;
		std::unordered_map<std::string, std::shared_ptr<Shader>> shaders;

	public:
		ShaderLibrary(RenderApiFactory &factory);

		std::shared_ptr<Shader> Get(const std::string &name);
		std::shared_ptr<Shader> &Add(const std::shared_ptr<Shader> &shader);
		std::shared_ptr<Shader> &Load(const ShaderInfo &info);
	};
}