#pragma once

#include <string>

#include "glm/glm.hpp"

#include "Hazel/Core/Core.h"
#include "Hazel/Utils/Bindable.h"

namespace Hazel
{
    class HAZEL_API Shader : public Bindable
    {
    public:
        virtual ~Shader() = default;

        virtual bool IsExecutable() const = 0;
        virtual void UploadUniformMat4(const std::string &name, const glm::mat4 &uniform) = 0;
    };
}