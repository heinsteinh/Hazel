#pragma once

#include "Entity.h"

namespace Hazel
{
	template<typename IteratorType>
	class EntityIterator
	{
	private:
		IteratorType iterator;
		entt::registry *registry;

	public:
		EntityIterator(IteratorType iterator, entt::registry &registry)
			: iterator(iterator),
			registry(&registry)
		{
		}

		Entity operator*()
		{
			return {*iterator, *registry};
		}

		EntityIterator operator++()
		{
			return {++iterator, *registry};
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