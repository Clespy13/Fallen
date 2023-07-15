#pragma once

struct GLFWwindow {};

class Window {
    public:
        Window();
        ~Window();

        void CreateWindow(const char* title, int width, int height);
        void DestroyWindow();

        GLFWwindow* getWindow() { return m_Window; }
        int getWidth() { return m_Width; }
        int getHeight() { return m_Height; }

    private:
        GLFWwindow* m_Window;

        int m_Width;
        int m_Height;
        const char* m_Title;

};
