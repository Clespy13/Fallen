#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window {
    public:
        Window(char* title, int width, int height);
        ~Window();

        void CreateWindow();
        void DestroyWindow();

    private:
        int m_Width;
        int m_Height;
        char* m_Title;

};
