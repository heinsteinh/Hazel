#include "ShaderLibrary.h"

namespace Hazel
{
    ShaderLibrary::ShaderLibrary(ObjectFactory &factory)
        : factory(factory)
    {
    }

    SharedPtr<Shader> ShaderLibrary::Get(const std::string &name)
    {
        auto i = shaders.find(name);
        return i == shaders.end()
            ? SharedPtr<Shader>()
            : i->second;
    }

    void ShaderLibrary::Add(const SharedPtr<Shader> &shader)
    {
        shaders[shader->GetName()] = shader;
    }

    SharedPtr<Shader> ShaderLibrary::Load(const ShaderInfo &info)
    {
        auto i = shaders.find(info.GetName());
        if (i == shaders.end())
        {
            return i->second;
        }
        auto shader = factory.CreateShader(info);
        Add(shader);
        return shader;
    }
}