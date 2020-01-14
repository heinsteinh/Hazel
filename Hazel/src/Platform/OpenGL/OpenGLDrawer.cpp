#include "OpenGLDrawer.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace Hazel
{
    OpenGLDrawer::OpenGLDrawer(GLFWwindow *window)
        : window(window)
    {
    }

    void OpenGLDrawer::SwapBuffers()
    {
        glfwSwapBuffers(window);
    }

    void OpenGLDrawer::SetViewport(const Rectangle &viewport)
    {
        glViewport(
            (int)viewport.GetLeft(),
            (int)viewport.GetBottom(),
            (int)viewport.GetWidth(),
            (int)viewport.GetHeight());
    }

    void OpenGLDrawer::SetClearColor(const glm::vec4 &color)
    {
        glClearColor(color.r, color.g, color.b, color.a);
    }

    void OpenGLDrawer::Clear()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void OpenGLDrawer::DrawIndexed(const SharedPtr<VertexArray> &vertexArray)
    {
        glDrawElements(
            GL_TRIANGLES,
            (int)vertexArray->GetIndexBuffer()->GetSize(),
            GL_UNSIGNED_INT,
            nullptr);
    }
}