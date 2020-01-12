#pragma once

#include "Hazel.h"

namespace Sandbox
{
    class Layer2D : public Hazel::Layer
    {
    private:
        Hazel::Window &parent;

    public:
        Layer2D(Hazel::Window &parent)
            : parent(parent)
        {
        }
    };
}