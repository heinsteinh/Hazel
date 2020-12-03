#pragma once

#include "EntityIterator.h"

namespace Hazel
{
	template<typename ViewType, typename IteratorType>
	class EntitySubset
	{
	private:
		ViewType view;
		SceneContext *context = nullptr;

	public:
		EntitySubset(ViewType view, SceneContext &context)
			: view(view),
			context(&context)
		{
		}

		EntityIterator<IteratorType> begin() const
		{
			return {view.begin(), *context};
		}

		EntityIterator<IteratorType> end() const
		{
			return {view.end(), *context};
		}

		bool IsEmpty() const
		{
			return view.begin() == view.end();
		}

		Entity GetFirstEntity() const
		{
			return {*view.begin(), *context};
		}

		Entity TryGetFirstEntity() const
		{
			return IsEmpty() ? Entity() : GetFirstEntity();
		}
	};
}