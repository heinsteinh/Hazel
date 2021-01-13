#pragma once

#include "glm/glm.hpp"

#include "Hazel/Rendering/GraphicsContext/GraphicsContext.h"
#include "Hazel/Rendering/Materials/MaterialShader.h"
#include "Hazel/Core/FileSystem/FileReader.h"
#include "Uniform2D.h"
#include "Vertex2D.h"

namespace Hazel
{
	class Shader2D
	{
	public:
		static std::shared_ptr<MaterialShader> CreateShader(GraphicsContext &graphicsContext)
		{
			auto shader = std::make_shared<MaterialShader>();
			ShaderInfo info;
			info.VertexSource = FileReader::ReadAll("C:\\Users\\christian\\source\\repos\\Hazel\\Hazel\\assets\\shaders\\Shader2D.vert");
			info.PixelSource = FileReader::ReadAll("C:\\Users\\christian\\source\\repos\\Hazel\\Hazel\\assets\\shaders\\Shader2D.frag");
			shader->Shader = graphicsContext.CreateShader(info);
			shader->Uniform.Init<Uniform2D>(Uniform2D::Layout);
			shader->ViewProjectionIndex = Uniform2D::ViewProjectionIndex;
			shader->InputLayout = graphicsContext.CreateInputLayout(Vertex2D::Layout);
			return shader;
		}
	};
}