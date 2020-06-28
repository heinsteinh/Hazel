#include "AvailableRenderApi.h"

#include "Platform/OpenGL/Core/OpenGLRenderApi.h"

namespace Hazel
{
	static OpenGLRenderApi openGL;
	RenderApi &AvailableRenderApi::OpenGL = openGL;
}