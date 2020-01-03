#pragma once

#include "ObjectFactory.h"
#include "Shader.h"

namespace Hazel
{
    class ShaderLibrary
    {
    private:
        ObjectFactory &factory;
        std::unordered_map<std::string, SharedPtr<Shader>> shaders;

    public:
        ShaderLibrary(ObjectFactory &factory);

        SharedPtr<Shader> Get(const std::string &name);
        void Add(const SharedPtr<Shader> &shader);
        SharedPtr<Shader> Load(const std::string &filename);
        SharedPtr<Shader> Load(const std::string &name, const std::string &filename);
    };
}