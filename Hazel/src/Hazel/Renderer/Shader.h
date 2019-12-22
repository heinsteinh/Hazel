#pragma once

#include <string>

#include "Hazel/Core/Core.h"
#include "Hazel/Utils/Bindable.h"

namespace Hazel
{
    class HAZEL_API Shader : public Bindable
    {
    public:
        virtual ~Shader() = default;

        virtual bool IsBuilt() const = 0;
    };
}