#include "AvailableRenderApi.h"

#include "Platform/OpenGL/RenderApi/OpenGLRenderApi.h"

namespace Hazel
{
	static OpenGLRenderApi openGL;
	RenderApi &AvailableRenderApi::OpenGL = openGL;
}