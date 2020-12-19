#pragma once

#include "Hazel/Rendering/GraphicsContext/GraphicsContext.h"
#include "Hazel/Rendering/BatchRenderer/BatchInfo.h"
#include "BatchVertex.h"
#include "BatchIndices.h"
#include "BatchConstants.h"

namespace Hazel
{
	class BatchBuffers
	{
	private:
		GraphicsContext *graphicsContext = nullptr;
		std::shared_ptr<IndexBuffer> indexBuffer;
		std::shared_ptr<VertexBuffer> vertexBuffer;
		std::shared_ptr<ConstantBuffer> constantBuffer;
		std::shared_ptr<InputLayout> inputLayout;

	public:
		BatchBuffers(GraphicsContext &graphicsContext, const BatchInfo &info);

		void BufferIndices(const BatchIndices &indices);
		void BufferVertices(const BatchArray<BatchVertex> &vertices);
		void BufferConstants(const BatchConstants &constants);
	};
}