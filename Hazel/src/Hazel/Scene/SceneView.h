#pragma once

#include "EntityIterator.h"

namespace Hazel
{
	template<typename ViewType, typename IteratorType>
	class SceneView
	{
	private:
		ViewType view;
		entt::registry *registry;

	public:
		SceneView(ViewType view, entt::registry &registry)
			: view(view),
			registry(&registry)
		{
		}

		EntityIterator<IteratorType> begin() const
		{
			return {view.begin(), *registry};
		}

		EntityIterator<IteratorType> end() const
		{
			return {view.end(), *registry};
		}

		bool IsEmpty() const
		{
			return view.begin() == view.end();
		}

		Entity GetFirstEntity() const
		{
			return {*view.begin(), *registry};
		}
	};
}