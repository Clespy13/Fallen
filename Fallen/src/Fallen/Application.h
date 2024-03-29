#pragma once

#include "Window.h"
#include "Events/Event.h"
#include "Events/KeyEvent.h"
#include "Events/WindowEvent.h"
#include "LayerStack.h"
#include "Time.h"

class Application {
    public:
        Application();
        ~Application();

        void Run();
        static void OnEvent(Event& event);

        void PushLayer(Layer* layer);

        inline Window* GetWindow() { return m_Window; }

        inline static Application& Get() { return *s_Instance; }

        

    private:
        // layer stack needed
        static Window* m_Window;
        static bool m_Running;
        static LayerStack m_LayerStack;
        double m_LastFrameTime = 0.0f;

        //bool OnWindowClose(WindowCloseEvent& event);
        static bool OnWindowClose(WindowCloseEvent& event);
        static bool Resize(WindowResizeEvent& event);

        static Application* s_Instance;
};
