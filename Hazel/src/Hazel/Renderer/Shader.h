#pragma once

#include "Hazel/Utils/Bindable.h"

namespace Hazel
{
    class HAZEL_API Shader : public Bindable
    {
    public:
        virtual ~Shader() = default;

        virtual bool IsExecutable() const = 0;
    };
}