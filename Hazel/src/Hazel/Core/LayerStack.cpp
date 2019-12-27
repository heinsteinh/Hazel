#include "LayerStack.h"

namespace Hazel
{
    LayerStack::LayerStack()
    {
    }

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
        layer->OnAttach();
    }

    void LayerStack::PushOverlay(Layer *overlay)
    {
        layers.emplace_back(overlay);
        overlay->OnAttach();
    }

    void LayerStack::PopLayer(Layer *layer)
    {
        auto i = std::find(layers.begin(), layers.end(), layer);
        if (i != layers.end())
        {
            layers.erase(i);
            top--;
            layer->OnDetach();
        }
    }

    void LayerStack::PopOverlay(Layer *overlay)
    {
        auto i = std::find(layers.begin(), layers.end(), overlay);
        if (i != layers.end())
        {
            layers.erase(i);
            overlay->OnDetach();
        }
    }
}