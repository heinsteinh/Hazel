#pragma once

namespace Hazel
{
	class Layer;

	class LayerStack
	{
	private:
		std::vector<std::shared_ptr<Layer>> layers;
		size_t top = 0;

	public:
		auto begin()
		{
			return layers.begin();
		}

		auto end()
		{
			return layers.end();
		}

		auto rbegin()
		{
			return layers.rbegin();
		}

		auto rend()
		{
			return layers.rend();
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