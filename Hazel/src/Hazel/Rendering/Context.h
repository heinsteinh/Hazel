#pragma once

#include "glm/glm.hpp"

#include "ObjectFactory.h"
#include "Drawer.h"

namespace Hazel
{
    class HAZEL_API Context
    {
    public:
        virtual ~Context() = default;

        virtual void MakeCurrent() = 0;
        virtual ObjectFactory &GetFactory() = 0;
        virtual Drawer &GetDrawer() = 0;
    };
}