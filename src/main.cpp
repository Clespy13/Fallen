//#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Logger.h"
#include "Window.h"
#include "Application.h"
#include "Layer.h"
#include "Events/MouseEvent.h"

class TestLayer : public Layer {
    public:
        TestLayer() : Layer("Test") {}
        ~TestLayer() {}

        void OnAttach() override {}
        void OnDetach() override {}
        void OnUpdate() override {}
        void OnEvent(Event& event) override {
            EventDispatcher dispatcher(event);
            dispatcher.dispatch<MouseMovedEvent>(TestLayer::Mouse);
        }

        static bool Mouse(MouseMovedEvent& event) {
            INFO("Mouse moved: (%f, %f)", event.getX(), event.getY());
            return false;
        }

};

int main() {
    /*
     * Application is the whole thing
     * Contains layers (GUI, Game, etc)
     * GUI is just rectangles that when clicked have different events
     * Application has main run loop
     * Game has separate loop (layer loop)
     */

    Application app;

    app.PushLayer(new TestLayer());

    app.Run();
    /* Loop until the user closes the window */ 
    //while (!glfwWindowShouldClose(app.GetWindow()->getWindow()))
    //{
        //glClearColor(0.2f, 0.2f, 0.2f, 0.0f );

        /* Render here */
        //glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        //glfwSwapBuffers(app.GetWindow()->getWindow());

        /* Poll for and process events */
        //glfwPollEvents();
    //}

    //glfwTerminate();
    return 0;
}
