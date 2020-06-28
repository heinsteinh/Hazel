#include "ShaderLibrary.h"

namespace Hazel
{
	ShaderLibrary::ShaderLibrary(RenderApiFactory &factory)
		: factory(factory)
	{
	}

	SharedPtr<Shader> ShaderLibrary::Get(const std::string &name)
	{
		auto i = shaders.find(name);
		return i == shaders.end() ? SharedPtr<Shader>() : i->second;
	}

	SharedPtr<Shader> &ShaderLibrary::Add(const SharedPtr<Shader> &shader)
	{
		return shaders[shader->GetName()] = shader;
	}

	SharedPtr<Shader> &ShaderLibrary::Load(const ShaderInfo &info)
	{
		auto i = shaders.find(info.Name);
		if (i != shaders.end())
		{
			return i->second;
		}
		return Add(factory.CreateShader(info));
	}
}