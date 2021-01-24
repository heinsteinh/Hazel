#pragma once

#include <memory>

#include "Hazel/Core/Utils/StaticCast.h"
#include "Hazel/Rendering/GraphicsContext/DrawCommand.h"
#include "Hazel/Rendering/GraphicsContext/OpenGL/OpenGLBindingContext.h"
#include "Hazel/Rendering/Shaders/OpenGL/OpenGLShaderBinder.h"
#include "Hazel/Rendering/Textures/OpenGL/OpenGLTextureBinder.h"

namespace Hazel
{
	class OpenGLCommandBinder
	{
	public:
		static void BindCommand(OpenGLBindingContext &context, const DrawCommand &command)
		{
			context.SetFramebuffer(command.Framebuffer);
			OpenGLShaderBinder::BindShader(context, command);
			OpenGLTextureBinder::BindTextures(context, command.Textures);
		}
	};
}