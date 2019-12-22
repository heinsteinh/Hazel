#include "OpenGLRenderApi.h"

#include "glad/glad.h"

#include "OpenGLObjectFactory.h"

namespace Hazel
{
    ObjectFactory &OpenGLRenderApi::GetObjectFactory()
    {
        static OpenGLObjectFactory factory;
        return factory;
    }

    void OpenGLRenderApi::SetClearColor(const glm::vec4 &color)
    {
        glClearColor(color.r, color.g, color.b, color.a);
    }

    void OpenGLRenderApi::Clear()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void OpenGLRenderApi::DrawIndexed(const std::shared_ptr<VertexArray> &vertexArray)
    {
        glDrawElements(
            GL_TRIANGLES,
            (int)vertexArray->GetNumIndexes(),
            GL_UNSIGNED_INT,
            nullptr);
    }
}