#include "VertexArray.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Hazel
{
    VertexArray *VertexArray::Create()
    {
        switch (Renderer::GetApi())
        {
        case Renderer::Api::OpenGL:
            return new OpenGLVertexArray();
        }
        return nullptr;
    }
}