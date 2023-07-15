#include "Window.h"
#include "Logger.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

Window::Window() 
    : m_Width(0), m_Height(0) {

    if (!glfwInit())
        ERROR("Couldn't init glfw!");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

Window::~Window() {
}

void Window::CreateWindow(const char* title, int width, int height) {
    m_Width = width;
    m_Height = height;
    m_Title = title;

    m_Window = glfwCreateWindow(width, height, title, NULL, NULL);

    if (!m_Window) {
        glfwTerminate();
        ERROR("Couldn't create glfw window!");
    }

    glfwMakeContextCurrent(m_Window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        ERROR("Couldn't init glad!");

    glViewport(0, 0, width, height);
}

/*void Window::SetCallbacks() {
    glfwSetKeyCallback(m_Window, )
}*/

void Window::DestroyWindow() {
}

