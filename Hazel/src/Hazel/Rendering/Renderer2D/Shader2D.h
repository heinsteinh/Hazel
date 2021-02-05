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
			info.Name = "Shader2D";
			info.Filename = "";
			info.UniformLayout = Uniform2D::Layout;
			info.Properties.ViewProjectionIndex = Uniform2D::ViewProjectionIndex;
			info.InputLayout = Vertex2D::Layout;
			info.Properties.PositionIndex = Vertex2D::PositionIndex;
			info.Properties.ColorIndex = Vertex2D::ColorIndex;
			info.Properties.TextureCoordinatesIndex = Vertex2D::TextureCoordinatesIndex;
			info.Properties.TextureSlotIndex = Vertex2D::TextureSlotIndex;
			info.Sources[ShaderType::Vertex] = FileReader::ReadAll("C:\\Users\\christian\\source\\repos\\Hazel\\Hazel\\assets\\shaders\\Shader2D.vert");
			info.Sources[ShaderType::Fragment] = FileReader::ReadAll("C:\\Users\\christian\\source\\repos\\Hazel\\Hazel\\assets\\shaders\\Shader2D.frag");
			return graphicsContext.CreateShader(info);
		}
	};
}