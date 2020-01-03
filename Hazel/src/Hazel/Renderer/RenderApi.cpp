#include "RenderApi.h"

#include "Platform/OpenGL/OpenGLRenderApi.h"

namespace Hazel
{
    static OpenGLRenderApi openGL;
    RenderApi &RenderApi::OpenGL = openGL;
}