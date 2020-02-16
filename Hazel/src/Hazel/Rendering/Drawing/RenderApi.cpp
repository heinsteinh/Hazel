#include "RenderApi.h"

#include "Platform/OpenGL/Drawing/OpenGLRenderApi.h"

namespace Hazel
{
    static OpenGLRenderApi openGL;
    RenderApi &RenderApi::OpenGL = openGL;
}