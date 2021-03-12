#pragma once

#include <vector>
#include <memory>

#include "Hazel/Core/Application/ApplicationLayer.h"

namespace Hazel
{
	class ApplicationLayerStack
	{
	private:
		std::vector<std::unique_ptr<ApplicationLayer>> layers;
		size_t top = 0;

	public:
		void ApplicationLayerStack::PushLayer(std::unique_ptr<ApplicationLayer> layer)
		{
			layers.emplace(layers.begin() + top, std::move(layer));
			top++;
		}

		void ApplicationLayerStack::PushOverlay(std::unique_ptr<ApplicationLayer> overlay)
		{
			layers.emplace_back(std::move(overlay));
		}

		void ApplicationLayerStack::PopLayer(const ApplicationLayer *layer)
		{
			auto i = std::find_if(layers.begin(), layers.end(), [&](const auto &currentLayer)
			{
				return currentLayer.get() == layer;
			});
			if (i != layers.end())
			{
				layers.erase(i);
				top--;
			}
		}

		void ApplicationLayerStack::PopOverlay(const ApplicationLayer *overlay)
		{
			auto i = std::find_if(layers.begin(), layers.end(), [&](const auto &layer)
			{
				return layer.get() == overlay;
			});
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
				functor(**i);
			}
		}

		template<typename FunctorType>
		void FromBottomToTop(FunctorType functor) const
		{
			for (auto i = layers.begin(); i != layers.end(); ++i)
			{
				functor(**i);
			}
		}
	};
}