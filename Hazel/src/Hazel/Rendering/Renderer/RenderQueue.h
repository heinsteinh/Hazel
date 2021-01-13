#pragma once

#include <vector>
#include <algorithm>

#include "RenderCommand.h"

namespace Hazel
{
	class RenderQueue
	{
	private:
		std::vector<RenderCommand> queue;

	public:
		auto begin() const
		{
			return queue.begin();
		}

		auto begin()
		{
			return queue.begin();
		}

		auto end() const
		{
			return queue.end();
		}

		void Clear()
		{
			queue.clear();
		}

		RenderCommand &Add(const RenderCommand &renderCommand)
		{
			return queue.emplace_back(renderCommand);
		}

		template<typename FunctorType>
		void Sort(FunctorType functor)
		{
			std::sort(queue.begin(), queue.end(), functor);
		}
	};
}