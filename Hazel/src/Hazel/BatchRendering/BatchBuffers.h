#pragma once

#include "BatchInfo.h"
#include "BatchVertex.h"
#include "BatchIndices.h"
#include "Hazel/GraphicsContext/GraphicsContext.h"

namespace Hazel
{
	class BatchBuffers
	{
	private:
		GraphicsContext *graphicsContext = nullptr;
		std::shared_ptr<IndexBuffer> indexBuffer;
		std::shared_ptr<VertexBuffer> vertexBuffer;
		std::shared_ptr<ConstantBuffer> matrixBuffer;
		std::shared_ptr<ConstantBuffer> samplerBuffer;
		std::shared_ptr<InputLayout> inputLayout;

	public:
		inline BatchBuffers(GraphicsContext &graphicsContext, const BatchInfo &info)
			: graphicsContext(&graphicsContext),
			indexBuffer(graphicsContext.CreateIndexBuffer(info.GetIndexBufferSize())),
			vertexBuffer(graphicsContext.CreateVertexBuffer(info.GetVertexBufferSize())),
			matrixBuffer(graphicsContext.CreateConstantBuffer(sizeof(glm::mat4))),
			samplerBuffer(graphicsContext.CreateConstantBuffer(info.MaxTextureSlotCount * 4)),
			inputLayout(graphicsContext.CreateInputLayout(BatchVertex::Attributes))
		{
			Bind();
			//BufferSamplers();
		}

		inline void Bind() const
		{
			graphicsContext->SetIndexBuffer(indexBuffer);
			graphicsContext->SetVertexBuffer(vertexBuffer);
			graphicsContext->SetConstantBuffer(matrixBuffer, 0);
			graphicsContext->SetConstantBuffer(samplerBuffer, 1);
			graphicsContext->SetInputLayout(inputLayout);
		}

		inline void BufferIndices(const BatchIndices &indices)
		{
			indexBuffer->BufferData(indices.GetData(), indices.GetSize());
		}

		inline void BufferVertices(const BatchArray<BatchVertex> &vertices)
		{
			vertexBuffer->BufferData(vertices.GetData(), vertices.GetSize());
		}

		inline void BufferViewProjectionMatrix(const glm::mat4 &viewProjection)
		{
			matrixBuffer->BufferData(glm::value_ptr(viewProjection), sizeof(glm::mat4));
		}

		inline void BufferSamplers()
		{
			std::vector<int> samplers;
			auto size = samplerBuffer->GetSize() / 4;
			samplers.reserve(size);
			for (size_t i = 0; i < size; i++)
			{
				samplers.push_back(static_cast<int>(i));
			}
			samplerBuffer->BufferData(samplers.data(), samplers.size());
		}
	};
}