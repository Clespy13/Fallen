#pragma once

#include "Events/Event.h"

class Layer {
    public:
        Layer(const char* name = "New Layer")
            : m_Name(name) {}
        virtual ~Layer() = default;

        virtual void OnAttach() {};
        virtual void OnDetach() {};
        virtual void OnUpdate() {};
        virtual void OnEvent(Event& event) {};

        const char* GetName() const { return m_Name; }
    private:
        const char* m_Name;
};
