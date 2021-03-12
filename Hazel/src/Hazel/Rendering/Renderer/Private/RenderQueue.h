#pragma once

#include <vector>
#include <algorithm>

#include "Hazel/Rendering/Renderer/RenderCommand.h"

namespace Hazel
{
	class RenderQueue
	{
	private:
		std::vector<RenderCommand> commands;

	public:
		auto begin() const
		{
			return commands.begin();
		}

		auto end() const
		{
			return commands.end();
		}

		RenderCommand &Add()
		{
			return commands.emplace_back();
		}

		void Clear()
		{
			commands.clear();
		}

		template<typename FunctorType>
		void Sort(FunctorType functor)
		{
			std::sort(commands.begin(), commands.end(), std::move(functor));
		}
	};
}