#pragma once

#include <vector>

#include "Hazel/Core/Layer.h"

namespace Hazel
{
    class LayerStack
    {
    public:
        using iterator = std::vector<Layer *>::reverse_iterator;
        using reverse_iterator = std::vector<Layer *>::iterator;

    private:
        std::vector<Layer *> layers;
        std::vector<Layer *>::iterator insert;

    public:
        LayerStack();
        ~LayerStack();

        void PushLayer(Layer *layer);
        void PushOverlay(Layer *overlay);
        void PopLayer(Layer *layer);
        void PopOverlay(Layer *overlay);

        iterator begin();
        iterator end();

        reverse_iterator rbegin();
        reverse_iterator rend();
    };
}