#include "IndexBuffer.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLIndexBuffer.h"

namespace Hazel
{
    IndexBuffer *IndexBuffer::Create(unsigned int indexes[], size_t count)
    {
        switch (Renderer::GetApi())
        {
        case Renderer::Api::OpenGL:
            return new OpenGLIndexBuffer(indexes, count);
        }
        return nullptr;
    }
}