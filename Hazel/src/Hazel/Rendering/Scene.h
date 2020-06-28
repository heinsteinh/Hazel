#pragma once

#include "Hazel/Rendering/Camera/OrthographicCamera.h"
#include "Hazel/Rendering/Buffers/VertexArray.h"
#include "Hazel/Rendering/Shaders/Shader.h"

namespace Hazel
{
	struct Scene
	{
		OrthographicCamera Camera;
		SharedPtr<Shader> Shader;
		SharedPtr<VertexArray> VertexArray;
	};
}