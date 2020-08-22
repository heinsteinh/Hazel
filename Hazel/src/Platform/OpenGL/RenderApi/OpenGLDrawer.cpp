#include "OpenGLDrawer.h"

#include "glad/glad.h"

namespace Hazel
{
	void OpenGLDrawer::SetViewport(const Rectangle &viewport)
	{
		glViewport(
			static_cast<int>(viewport.Left),
			static_cast<int>(viewport.Bottom),
			static_cast<int>(viewport.GetWidth()),
			static_cast<int>(viewport.GetHeight()));
	}

	void OpenGLDrawer::SetClearColor(const glm::vec4 &color)
	{
		glClearColor(color.r, color.g, color.b, color.a);
	}

	void OpenGLDrawer::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void OpenGLDrawer::DrawIndexed(size_t count)
	{
		glDrawElements(
			GL_TRIANGLES,
			static_cast<int>(count),
			GL_UNSIGNED_INT,
			nullptr);
	}
}