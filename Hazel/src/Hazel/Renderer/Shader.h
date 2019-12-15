#pragma once

#include <string>

#include "Hazel/Core/Core.h"
#include "Hazel/Utils/Bindable.h"

namespace Hazel
{
    class HAZEL_API Shader : public Bindable
    {
    private:
        unsigned int rendererId = 0;

    public:
        Shader(const std::string &vertexSource, const std::string &fragmentSource);
        virtual ~Shader();

        virtual void Bind() const override;
        virtual void UnBind() const override;
    };
}