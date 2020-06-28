#pragma once

#include "Hazel/Rendering/Core/RenderApiFactory.h"
#include "Shader.h"

namespace Hazel
{
	class ShaderLibrary
	{
	private:
		RenderApiFactory &factory;
		std::unordered_map<std::string, SharedPtr<Shader>> shaders;

	public:
		ShaderLibrary(RenderApiFactory &factory);

		SharedPtr<Shader> Get(const std::string &name);
		SharedPtr<Shader> &Add(const SharedPtr<Shader> &shader);
		SharedPtr<Shader> &Load(const ShaderInfo &info);
	};
}