#pragma once

#include "Layer.h"

namespace Hazel
{
	class LayerStack
	{
	private:
		std::vector<SharedPtr<Layer>> layers;
		int top = 0;

	public:
		inline auto begin()
		{
			return layers.rbegin();
		}

		inline auto end()
		{
			return layers.rend();
		}

		inline auto rbegin()
		{
			return layers.begin();
		}

		inline auto rend()
		{
			return layers.end();
		}

		void LayerStack::PushLayer(const SharedPtr<Layer> &layer)
		{
			layers.emplace(layers.begin() + top, layer);
			top++;
		}

		void LayerStack::PushOverlay(const SharedPtr<Layer> &overlay)
		{
			layers.emplace_back(overlay);
		}

		void LayerStack::PopLayer(const SharedPtr<Layer> &layer)
		{
			auto i = std::find(layers.begin(), layers.end(), layer);
			if (i != layers.end())
			{
				layers.erase(i);
				top--;
			}
		}

		void LayerStack::PopOverlay(const SharedPtr<Layer> &overlay)
		{
			auto i = std::find(layers.begin(), layers.end(), overlay);
			if (i != layers.end())
			{
				layers.erase(i);
			}
		}
	};
}