#pragma once

#include "Hazel/Application/Layer.h"

namespace Hazel
{
	class LayerStack
	{
	private:
		std::vector<std::shared_ptr<Layer>> layers;
		size_t top = 0;

	public:
		inline auto begin()
		{
			return layers.begin();
		}

		inline auto end()
		{
			return layers.end();
		}

		inline auto rbegin()
		{
			return layers.rbegin();
		}

		inline auto rend()
		{
			return layers.rend();
		}

		inline void LayerStack::PushLayer(const std::shared_ptr<Layer> &layer)
		{
			layers.emplace(layers.begin() + top, layer);
			top++;
		}

		inline void LayerStack::PushOverlay(const std::shared_ptr<Layer> &overlay)
		{
			layers.emplace_back(overlay);
		}

		inline void LayerStack::PopLayer(const std::shared_ptr<Layer> &layer)
		{
			auto i = std::find(layers.begin(), layers.end(), layer);
			if (i != layers.end())
			{
				layers.erase(i);
				top--;
			}
		}

		inline void LayerStack::PopOverlay(const std::shared_ptr<Layer> &overlay)
		{
			auto i = std::find(layers.begin(), layers.end(), overlay);
			if (i != layers.end())
			{
				layers.erase(i);
			}
		}
	};
}