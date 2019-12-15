#pragma once

namespace Hazel
{
    class Bindable
    {
    public:
        virtual ~Bindable() = default;

        virtual void Bind() const = 0;
        virtual void UnBind() const = 0;
    };
}