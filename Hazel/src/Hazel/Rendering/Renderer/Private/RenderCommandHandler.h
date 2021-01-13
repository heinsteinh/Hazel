#pragma once

#include "Hazel/Rendering/GraphicsContext/GraphicsContext.h"
#include "Hazel/Rendering/Renderer/RendererStatistics.h"
#include "Hazel/Rendering/Renderer/RendererException.h"
#include "RendererShader.h"
#include "RendererBatch.h"

namespace Hazel
{
	class RenderCommandHandler
	{
	private:
		GraphicsContext *graphicsContext = nullptr;
		const Camera *camera = nullptr;
		PrimitiveTopology primitiveTopology = PrimitiveTopology::Triangles;
		IndexFormat indexFormat = IndexFormat::UInt16;
		RendererShader shader;
		RendererBatch batch;
		RendererStatistics statistics;

	public:
		RenderCommandHandler(const RendererInfo &info)
			: graphicsContext(info.GraphicsContext),
			shader(info),
			batch(info),
			statistics(info)
		{
			SetupParameters(primitiveTopology, indexFormat);
		}

		void SetCamera(const Camera &camera)
		{
			this->camera = &camera;
			shader.BufferUniform(camera);
			statistics.Reset();
		}

		void Submit(const RenderCommand &command)
		{
			SetShader(command.Material->Shader.get());
			SetupContext(*command.Mesh);
			if (!batch.Add(command))
			{
				Flush();
				if (!batch.Add(command))
				{
					throw RendererException("The batch is too small to contain the object");
				}
			}
		}

		void Flush()
		{
			batch.BufferData();
			statistics.IndexCount += batch.GetIndexCount();
			statistics.VertexCount += batch.GetVertexCount();
			statistics.TextureCount += batch.GetTextureCount();
			graphicsContext->DrawIndexed(batch.GetIndexCount());
			statistics.DrawCallCount++;
			batch.Clear();
		}

		const RendererStatistics &GetStatistics() const
		{
			return statistics;
		}

	private:
		void SetShader(MaterialShader *shader)
		{
			if (this->shader.GetShader() != shader)
			{
				Flush();
				this->shader.SetShader(shader);
				batch.SetVertexLayout(shader->InputLayout->GetVertexLayout());
				this->shader.BufferUniform(*camera);
			}
		}

		void SetupContext(const Mesh &mesh)
		{
			if (!CanRenderMesh(mesh))
			{
				Flush();
				SetupParameters(mesh.PrimitiveTopology, mesh.Indices.GetIndexFormat());
			}
		}

		bool CanRenderMesh(const Mesh &mesh) const
		{
			return mesh.PrimitiveTopology == primitiveTopology && mesh.Indices.GetIndexFormat() == indexFormat;
		}

		void SetupParameters(PrimitiveTopology primitiveTopology, IndexFormat indexFormat)
		{
			this->primitiveTopology = primitiveTopology;
			graphicsContext->SetPrimitiveTopology(primitiveTopology);
			this->indexFormat = indexFormat;
			graphicsContext->SetIndexFormat(indexFormat);
			batch.SetIndexFormat(indexFormat);
		}
	};
}