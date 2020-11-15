#pragma once

#include "Platform/OpenGL/Framebuffer/OpenGLFramebuffer.h"
#include "Platform/OpenGL/Shaders/OpenGLProgram.h"
#include "Platform/OpenGL/Buffers/OpenGLVertexBuffer.h"
#include "Platform/OpenGL/Buffers/OpenGLVertexArray.h"
#include "Platform/OpenGL/Buffers/OpenGLIndexBuffer.h"
#include "Platform/OpenGL/Textures/OpenGLTexture.h"

namespace Hazel
{
	class OpenGLContext
	{
	private:
		OpenGLFramebuffer *framebuffer = nullptr;
		OpenGLProgram *program = nullptr;
		OpenGLVertexBuffer *vertexBuffer = nullptr;
		OpenGLVertexArray *vertexArray = nullptr;
		OpenGLIndexBuffer *indexBuffer = nullptr;
		std::vector<OpenGLTexture *> textures;

	public:
		inline void SetFramebuffer(const std::shared_ptr<Framebuffer> &framebuffer)
		{
			if (framebuffer && this->framebuffer != framebuffer.get())
			{
				HZ_ASSERT(typeid(*framebuffer) == typeid(OpenGLFramebuffer), "Not an OpenGL type.");
				this->framebuffer = static_cast<OpenGLFramebuffer *>(framebuffer.get());
				this->framebuffer->Bind();
			}
		}

		inline void SetShader(const std::shared_ptr<Shader> &shader)
		{
			if (shader && program != shader.get())
			{
				HZ_ASSERT(typeid(*shader) == typeid(OpenGLProgram), "Not an OpenGL type.");
				program = static_cast<OpenGLProgram *>(shader.get());
				program->Bind();
			}
		}

		inline void SetIndexBuffer(const std::shared_ptr<IndexBuffer> &indexBuffer)
		{
			if (indexBuffer && this->indexBuffer != indexBuffer.get())
			{
				HZ_ASSERT(typeid(*indexBuffer) == typeid(OpenGLIndexBuffer), "Not an OpenGL type.");
				this->indexBuffer = static_cast<OpenGLIndexBuffer *>(indexBuffer.get());
				this->indexBuffer->Bind();
			}
		}

		inline void SetVertexBuffer(const std::shared_ptr<VertexBuffer> &vertexBuffer)
		{
			if (vertexBuffer && this->vertexBuffer != vertexBuffer.get())
			{
				HZ_ASSERT(typeid(*vertexBuffer) == typeid(VertexBuffer), "Not an OpenGL type.");
				this->vertexBuffer = static_cast<OpenGLVertexBuffer *>(vertexBuffer.get());
				this->vertexBuffer->Bind();
			}
		}

		inline void SetInputLayout(const std::shared_ptr<InputLayout> &inputLayout)
		{
			if (inputLayout && vertexArray != inputLayout.get())
			{
				HZ_ASSERT(typeid(*inputLayout) == typeid(OpenGLVertexArray), "Not an OpenGL type.");
				vertexArray = static_cast<OpenGLVertexArray *>(inputLayout.get());
				vertexArray->Bind();
			}
		}

		inline void InitTextureSlots(size_t slotCount)
		{
			textures.resize(slotCount, nullptr);
		}

		inline size_t GetTextureSlotCount() const
		{
			return textures.size();
		}

		inline void SetTexture(const std::shared_ptr<Texture> &texture, uint32_t slot)
		{
			if (texture && textures[slot] != texture.get())
			{
				HZ_ASSERT(typeid(*texture) == typeid(OpenGLTexture), "Not an OpenGL type.");
				HZ_ASSERT(slot < textures.size(), "Not enough texture slots.");
				textures[slot] = static_cast<OpenGLTexture *>(texture.get());
				textures[slot]->Bind(slot);
			}
		}
	};
}