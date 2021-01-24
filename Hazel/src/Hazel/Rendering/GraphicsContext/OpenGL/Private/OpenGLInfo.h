#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Hazel/Rendering/GraphicsApi/GraphicsApiInfo.h"
#include "OpenGLContextHandle.h"
#include "OpenGLLoader.h"

namespace Hazel
{
	class OpenGLInfo
	{
	public:
		static size_t GetUniformBindingCount()
		{
			int bindingCount;
			glGetIntegerv(GL_MAX_UNIFORM_BUFFER_BINDINGS, &bindingCount);
			return bindingCount;
		}

		static size_t GetTextureSlotCount()
		{
			int slotCount;
			glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &slotCount);
			return slotCount;
		}

		static GraphicsApiInfo LoadOpenGLAndGetApiInfo(OpenGLContextHandle context)
		{
			if (OpenGLContextHandle::GetCurrentContext() == nullptr)
			{
				context.MakeCurrent();
			}
			static OpenGLLoader loader;
			return LoadApiInfo();
		}

		static GraphicsApiInfo LoadApiInfo()
		{
			GraphicsApiInfo info;
			info.Version = reinterpret_cast<const char *>(glGetString(GL_VERSION));
			info.Vendor = reinterpret_cast<const char *>(glGetString(GL_VENDOR));
			info.Renderer = reinterpret_cast<const char *>(glGetString(GL_RENDERER));
			info.TextureSlotCount = GetTextureSlotCount();
			info.UniformBindingCount = GetUniformBindingCount();
			return info;
		}
	};
}