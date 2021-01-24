#pragma once

#include <vector>
#include <memory>

#include "Hazel/Rendering/Mesh/PrimitiveTopology.h"
#include "Hazel/Rendering/Mesh/IndexFormat.h"
#include "Hazel/Rendering/Framebuffers/Framebuffer.h"
#include "Hazel/Rendering/Shaders/Shader.h"
#include "Hazel/Rendering/GraphicsBuffers/IndexBuffer.h"
#include "Hazel/Rendering/GraphicsBuffers/VertexBuffer.h"
#include "Hazel/Rendering/Textures/Texture.h"

namespace Hazel
{
	struct DrawCommand
	{
		PrimitiveTopology PrimitiveTopology = PrimitiveTopology::Triangles;
		IndexFormat IndexFormat = IndexFormat::UInt16;
		size_t IndexCount = 0;
		std::weak_ptr<Framebuffer> Framebuffer;
		std::weak_ptr<Shader> Shader;
		std::weak_ptr<IndexBuffer> IndexBuffer;
		std::weak_ptr<VertexBuffer> VertexBuffer;
		std::vector<std::weak_ptr<Texture>> Textures;

		DrawCommand(size_t textureSlotCount = 0)
		{
			Textures.reserve(textureSlotCount);
		}
	};
}