#include "VertexBuffer.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLVertexBuffer.h"

namespace Hazel
{
    VertexBuffer *VertexBuffer::Create(float vertices[], size_t size)
    {
        switch (Renderer::GetApi())
        {
        case Renderer::Api::OpenGL:
            return new OpenGLVertexBuffer(vertices, size);
        }
        return nullptr;
    }
}