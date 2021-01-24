#pragma once

#include "glm/glm.hpp"

#include "Hazel/Rendering/GraphicsContext/GraphicsContext.h"
#include "Hazel/Rendering/Shaders/Shader.h"
#include "Hazel/Core/FileSystem/FileReader.h"
#include "Uniform2D.h"
#include "Vertex2D.h"

namespace Hazel
{
	class Shader2D
	{
	public:
		static std::shared_ptr<Shader> CreateShader(GraphicsContext &graphicsContext)
		{
			ShaderInfo info;
			info.UniformLayout = Uniform2D::Layout;
			info.UniformMap.ViewProjectionIndex = Uniform2D::ViewProjectionIndex;
			info.InputLayout = Vertex2D::Layout;
			info.VertexSource = FileReader::ReadAll("C:\\Users\\christian\\source\\repos\\Hazel\\Hazel\\assets\\shaders\\Shader2D.vert");
			info.PixelSource = FileReader::ReadAll("C:\\Users\\christian\\source\\repos\\Hazel\\Hazel\\assets\\shaders\\Shader2D.frag");
			return graphicsContext.CreateShader(info);
		}
	};
}