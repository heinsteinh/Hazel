#include "Renderer.h"

namespace Hazel
{
	Renderer::Renderer(Drawer &drawer)
		: drawer(drawer)
	{
	}

	void Renderer::BeginScene()
	{
	}

	void Renderer::Submit(const Scene &scene)
	{
		scene.Shader->Bind();
		scene.Shader->Set("u_ViewProjection", scene.Camera.GetViewProjectionMatrix());
		scene.VertexArray->Bind();
		drawer.DrawIndexed(scene.VertexArray->GetIndexBuffer()->GetSize());
	}

	void Renderer::EndScene()
	{
	}
}