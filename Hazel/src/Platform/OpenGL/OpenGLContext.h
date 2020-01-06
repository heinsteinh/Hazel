#pragma once

#include "glm/glm.hpp"

#include "Hazel/Rendering/Context.h"
#include "OpenGLObjectFactory.h"
#include "OpenGLDrawer.h"

struct GLFWwindow;

namespace Hazel
{
    class OpenGLContext : public Context
    {
    private:
        GLFWwindow *window = nullptr;
        OpenGLObjectFactory factory;
        OpenGLDrawer drawer;

    public:
        OpenGLContext(GLFWwindow *window);

        virtual void MakeCurrent() override;
        virtual ObjectFactory &GetFactory() override;
        virtual Drawer &GetDrawer() override;

    private:
        void Init();
        void LoadGlad();
        void DisplayOpenGLInfo();
        void SetupParameters();
    };
}