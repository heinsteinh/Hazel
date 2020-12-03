#pragma once

#include "Entity.h"
#include "SceneContext.h"

namespace Hazel
{
	template<typename IteratorType>
	class EntityIterator
	{
	private:
		IteratorType iterator;
		SceneContext *context = nullptr;

	public:
		EntityIterator(IteratorType iterator, SceneContext &context)
			: iterator(iterator),
			context(&context)
		{
		}

		Entity operator*()
		{
			return {*iterator, *context};
		}

		EntityIterator operator++()
		{
			return {++iterator, *context};
		}

		bool operator==(const EntityIterator &other) const
		{
			return iterator == other.iterator;
		}

		bool operator!=(const EntityIterator &other) const
		{
			return !(*this == other);
		}
	};
}