#include "LayerStack.h"

#include <functional>

LayerStack::LayerStack() {
}

LayerStack::~LayerStack() {
    for (Layer* layer : m_Layers) {
        layer->OnDetach();
        delete layer;
    }
}

void LayerStack::PushLayer(Layer* layer) {
    m_Layers.emplace(m_Layers.begin() + m_InsertIndex, layer);
    m_InsertIndex++;
}

void LayerStack::PopLayer(Layer* layer) {
    auto it = std::find(m_Layers.begin(), m_Layers.begin() + m_InsertIndex, layer);
    if (it != m_Layers.begin() + m_InsertIndex) {
        layer->OnDetach();
        m_Layers.erase(it);
        m_InsertIndex--;
    }
}
