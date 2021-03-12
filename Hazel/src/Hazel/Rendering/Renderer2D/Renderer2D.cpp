#include "Renderer2D.h"

#include "SquareMesh.h"
#include "Shader2D.h"

namespace Hazel
{
	Renderer2D::Renderer2D(const RendererInfo &info)
		: renderer(info),
		squareMesh(SquareMesh::CreateMesh()),
		defaultShader(Shader2D::CreateShader(*info.GraphicsContext))
	{
	}
}