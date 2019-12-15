#include "IndexBuffer.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLIndexBuffer.h"

namespace Hazel
{
    IndexBuffer *IndexBuffer::Create(int indexes[], int count)
    {
        switch (Renderer::GetApi())
        {
        case Renderer::Api::OpenGL:
            return new OpenGLIndexBuffer(indexes, count);
        }
        return nullptr;
    }
}