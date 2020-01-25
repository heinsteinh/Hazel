#include "LayerStack.h"

namespace Hazel
{
    LayerStack::~LayerStack()
    {
        for (Layer *layer : layers)
        {
            delete layer;
        }
    }

    void LayerStack::PushLayer(Layer *layer)
    {
        layers.emplace(layers.begin() + top, layer);
        top++;
    }

    void LayerStack::PushOverlay(Layer *overlay)
    {
        layers.emplace_back(overlay);
    }

    void LayerStack::PopLayer(Layer *layer)
    {
        auto i = std::find(layers.begin(), layers.end(), layer);
        if (i != layers.end())
        {
            layers.erase(i);
            top--;
        }
    }

    void LayerStack::PopOverlay(Layer *overlay)
    {
        auto i = std::find(layers.begin(), layers.end(), overlay);
        if (i != layers.end())
        {
            layers.erase(i);
        }
    }
}