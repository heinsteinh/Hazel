#pragma once

#include <vector>
#include <memory>

#include "Hazel/Core/Utils/StaticCast.h"
#include "Hazel/Rendering/Framebuffers/OpenGL/OpenGLFramebuffer.h"
#include "Hazel/Rendering/Shaders/OpenGL/OpenGLProgram.h"
#include "Hazel/Rendering/Shaders/OpenGL/OpenGLVertexArray.h"
#include "Hazel/Rendering/Shaders/OpenGL/OpenGLUniformBuffer.h"
#include "Hazel/Rendering/Textures/OpenGL/OpenGLTexture.h"
#include "OpenGLBinder.h"

namespace Hazel
{
	class OpenGLBindingContext
	{
	private:
		std::weak_ptr<OpenGLFramebuffer> framebuffer;
		std::weak_ptr<OpenGLProgram> program;
		std::weak_ptr<OpenGLVertexArray> vertexArray;
		std::shared_ptr<OpenGLUniformBuffer> uniformBuffer;
		std::vector<std::weak_ptr<OpenGLTexture>> textures;

	public:
		OpenGLBindingContext(size_t textureSlotCount = 0, size_t uniformBufferDefaultSize = 128)
			: textures(textureSlotCount)
		{
			ResizeUniformBuffer(uniformBufferDefaultSize);
		}

		std::shared_ptr<OpenGLFramebuffer> GetFramebuffer() const
		{
			return framebuffer.lock();
		}

		bool SetFramebuffer(const std::weak_ptr<Framebuffer> &framebuffer)
		{
			return OpenGLBinder::Bind(this->framebuffer, framebuffer.lock());
		}

		bool SetProgram(const std::shared_ptr<OpenGLProgram> &program)
		{
			return OpenGLBinder::Bind(this->program, program);
		}

		bool SetVertexArray(const std::shared_ptr<OpenGLVertexArray> &vertexArray)
		{
			return OpenGLBinder::Bind(this->vertexArray, vertexArray);
		}

		const OpenGLUniformBuffer &GetUniformBuffer() const
		{
			return *uniformBuffer;
		}

		OpenGLUniformBuffer &GetUniformBuffer()
		{
			return *uniformBuffer;
		}

		OpenGLUniformBuffer &EnsureUniformBufferSize(size_t size)
		{
			if (uniformBuffer->GetSize() < size)
			{
				ResizeUniformBuffer(size);
			}
			return *uniformBuffer;
		}

		void ResizeUniformBuffer(size_t size)
		{
			uniformBuffer = std::make_shared<OpenGLUniformBuffer>(size);
			uniformBuffer->Bind();
		}

		bool SetTexture(const std::shared_ptr<OpenGLTexture> &texture, size_t slot)
		{
			return OpenGLBinder::Bind(textures[slot], texture);
		}
	};
}