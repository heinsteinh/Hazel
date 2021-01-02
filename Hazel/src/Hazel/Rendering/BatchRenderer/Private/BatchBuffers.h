#pragma once

#include "Hazel/Rendering/GraphicsContext/GraphicsContext.h"
#include "Hazel/Rendering/Renderer2D/RendererInfo.h"
#include "BatchVertex.h"
#include "BatchIndices.h"
#include "BatchConstants.h"

namespace Hazel
{
	class BatchBuffers
	{
	private:
		std::shared_ptr<IndexBuffer> indexBuffer;
		std::shared_ptr<VertexBuffer> vertexBuffer;
		std::shared_ptr<ConstantBuffer> constantBuffer;
		std::shared_ptr<InputLayout> inputLayout;

	public:
		BatchBuffers(GraphicsContext &graphicsContext, const RendererInfo &info);

		void BufferIndices(const BatchIndices &indices);
		void BufferVertices(const BatchArray<BatchVertex> &vertices);
		void BufferConstants(const BatchConstants &constants);
	};
}