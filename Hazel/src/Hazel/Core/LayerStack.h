#pragma once

#include <vector>

#include "Hazel/Core/Layer.h"

namespace Hazel
{
    class LayerStack
    {
    private:
        std::vector<Layer *> layers;
        int top = 0;

    public:
        LayerStack();
        ~LayerStack();

        void PushLayer(Layer *layer);
        void PushOverlay(Layer *overlay);
        void PopLayer(Layer *layer);
        void PopOverlay(Layer *overlay);

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
    };
}