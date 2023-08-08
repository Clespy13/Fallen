#pragma once

#include "Events/Event.h"

#include <string>

struct GLFWwindow {};

class Window {
    public:
        Window(const char* title, int width, int height);
        ~Window();

        void CreateWindow();
        void DestroyWindow();

        void OnUpdate();

        inline void SetEventCallback(void (*callback)(Event&))
        {
            m_Data.EventCallback = callback;
        }

        GLFWwindow* getWindow() { return m_Window; }
        int getWidth() { return m_Width; }
        int getHeight() { return m_Height; }

        void Resize(int width, int height);

    private:
        GLFWwindow* m_Window;

        int m_Width;
        int m_Height;
        const char* m_Title;

        struct WindowData
        {
            std::string Title;
            unsigned int Width, Height;
            bool isVSync;

            void (*EventCallback)(Event&);
        };

        WindowData m_Data;

};
