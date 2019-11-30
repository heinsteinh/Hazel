#include "LayerStack.h"

namespace Hazel
{
    LayerStack::LayerStack()
        : insert(layers.begin())
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
        insert = layers.emplace(insert, layer);
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
            insert--;
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

    LayerStack::iterator LayerStack::begin()
    {
        return layers.rbegin();
    }

    LayerStack::iterator LayerStack::end()
    {
        return layers.rend();
    }

    LayerStack::reverse_iterator LayerStack::rbegin()
    {
        return layers.begin();
    }

    LayerStack::reverse_iterator LayerStack::rend()
    {
        return layers.end();
    }
}