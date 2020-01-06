#include "ShaderLibrary.h"

#include "Hazel/Utils/Path.h"

namespace Hazel
{
    ShaderLibrary::ShaderLibrary(ObjectFactory &factory)
        : factory(factory)
    {
    }

    SharedPtr<Shader> ShaderLibrary::Get(const std::string &name)
    {
        auto i = shaders.find(name);
        return i == shaders.end() ? SharedPtr<Shader>() : i->second;
    }

    void ShaderLibrary::Add(const SharedPtr<Shader> &shader)
    {
        shaders[shader->GetName()] = shader;
    }

    SharedPtr<Shader> ShaderLibrary::Load(const std::string &filename)
    {
        return Load(Path(filename).GetFilename(), filename);
    }

    SharedPtr<Shader> ShaderLibrary::Load(const std::string &name, const std::string &filename)
    {
        auto shader = factory.CreateShader(name, filename);
        Add(shader);
        return shader;
    }
}