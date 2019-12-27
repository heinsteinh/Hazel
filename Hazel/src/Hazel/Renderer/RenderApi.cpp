#include "RenderApi.h"

#include "Platform/OpenGL/OpenGLRenderApi.h"

namespace Hazel
{
    static const OpenGLRenderApi openGL;
    const RenderApi &RenderApi::OpenGL = openGL;
}