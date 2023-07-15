
//#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Logger.h"
#include "Window.h"

int main() {
    Window window;

    window.CreateWindow("Fallen", 640, 480);
    //window.SetCallbacks();

    INFO("Works on windows");

    /* Loop until the user closes the window */ 
    while (!glfwWindowShouldClose(window.getWindow()))
    {
        glClearColor(0.2f, 0.2f, 0.2f, 0.0f );

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window.getWindow());

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
