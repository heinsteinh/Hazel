#pragma once

#include "Layer.h"

namespace Hazel
{
	class LayerStack
	{
	private:
		std::vector<std::shared_ptr<Layer>> layers;
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

		void LayerStack::PushLayer(const std::shared_ptr<Layer> &layer)
		{
			layers.emplace(layers.begin() + top, layer);
			top++;
		}

		void LayerStack::PushOverlay(const std::shared_ptr<Layer> &overlay)
		{
			layers.emplace_back(overlay);
		}

		void LayerStack::PopLayer(const std::shared_ptr<Layer> &layer)
		{
			auto i = std::find(layers.begin(), layers.end(), layer);
			if (i != layers.end())
			{
				layers.erase(i);
				top--;
			}
		}

		void LayerStack::PopOverlay(const std::shared_ptr<Layer> &overlay)
		{
			auto i = std::find(layers.begin(), layers.end(), overlay);
			if (i != layers.end())
			{
				layers.erase(i);
			}
		}
	};
}