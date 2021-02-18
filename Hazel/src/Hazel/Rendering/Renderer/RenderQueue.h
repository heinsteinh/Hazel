#pragma once

#include <vector>
#include <algorithm>

#include "RenderCommand.h"

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

		RenderCommand &Add(const RenderCommand &command)
		{
			commands.push_back(command);
			return commands.back();
		}

		void Clear()
		{
			commands.clear();
		}

		void Sort()
		{
			std::sort(commands.begin(), commands.end());
		}

		template<typename FunctorType>
		void Sort(FunctorType functor)
		{
			std::sort(commands.begin(), commands.end(), std::move(functor));
		}
	};
}