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

		template<typename FunctorType>
		void Sort(FunctorType functor)
		{
			std::sort(commands.begin(), commands.end(), std::move(functor));
		}

		template<typename ...Args>
		RenderCommand &Emplace(Args &&...args)
		{
			return commands.emplace_back(std::forward<Args>(args)...);
		}
	};
}