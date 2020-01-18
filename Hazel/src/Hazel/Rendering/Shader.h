#pragma once

#include "glm/glm.hpp"

#include "Hazel/Utils/Bindable.h"

namespace Hazel
{
    class HAZEL_API Shader : public Bindable
    {
    public:
        virtual ~Shader() = default;

        virtual bool IsExecutable() const = 0;
        virtual const std::string &GetName() const = 0;
        virtual void Put(const std::string &name, int value) = 0;
        virtual void Put(const std::string &name, const glm::vec3 &value) = 0;
        virtual void Put(const std::string &name, const glm::vec4 &value) = 0;
        virtual void Put(const std::string &name, const glm::mat4 &value) = 0;
    };
}