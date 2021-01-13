#pragma once

#include "RendererInfo.h"
#include "Hazel/Core/Camera/Camera.h"
#include "RenderQueue.h"
#include "Private/RenderCommandHandler.h"

namespace Hazel
{
	class Renderer
	{
	private:
		RenderQueue renderQueue;
		RenderCommandHandler commandHandler;

	public:
		Renderer(const RendererInfo &info);

		void BeginScene(const Camera &camera);
		void Submit(const RenderCommand &renderCommand);
		void EndScene();

		const RendererStatistics &GetStatistics() const
		{
			return commandHandler.GetStatistics();
		}

		template<typename FunctorType>
		void SortRenderQueue(FunctorType functor)
		{
			renderQueue.Sort(functor);
		}
	};
}