#pragma once

#include <vector>
#include <memory>

namespace Hazel
{
	class Layer;

	class LayerStack
	{
	private:
		std::vector<std::shared_ptr<Layer>> layers;
		size_t top = 0;

	public:
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

		template<typename FunctorType>
		void FromTopToBottom(FunctorType functor) const
		{
			for (auto i = layers.rbegin(); i != layers.rend(); ++i)
			{
				functor(*i);
			}
		}

		template<typename FunctorType>
		void FromBottomToTop(FunctorType functor) const
		{
			for (auto i = layers.begin(); i != layers.end(); ++i)
			{
				functor(*i);
			}
		}
	};
}