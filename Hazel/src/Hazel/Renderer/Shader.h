#pragma once

#include <string>

#include "Hazel/Core/Core.h"
#include "Hazel/Utils/Bindable.h"

namespace Hazel
{
    class HAZEL_API Shader : public Bindable
    {
    public:
        static Shader *Create(const std::string &vertexSource, const std::string &fragmentSource);

        virtual ~Shader() = default;

        virtual bool IsBuilt() const = 0;
    };
}