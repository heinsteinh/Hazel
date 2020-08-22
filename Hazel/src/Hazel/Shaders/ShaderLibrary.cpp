#include "ShaderLibrary.h"

namespace Hazel
{
	ShaderLibrary::ShaderLibrary(RenderApiFactory &factory)
		: factory(factory)
	{
	}

	std::shared_ptr<Shader> ShaderLibrary::Get(const std::string &name)
	{
		auto i = shaders.find(name);
		return i == shaders.end() ? std::shared_ptr<Shader>() : i->second;
	}

	std::shared_ptr<Shader> &ShaderLibrary::Add(const std::shared_ptr<Shader> &shader)
	{
		return shaders[shader->GetName()] = shader;
	}

	std::shared_ptr<Shader> &ShaderLibrary::Load(const ShaderInfo &info)
	{
		auto i = shaders.find(info.Name);
		if (i != shaders.end())
		{
			return i->second;
		}
		return Add(factory.CreateShader(info));
	}
}