/*//#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Logger.h"
#include "Window.h"
#include "Application.h"
#include "Layer.h"
#include "Events/MouseEvent.h"
#include "UI/Button.h"

class UILayer : public Layer {
    public:
        UILayer() : Layer("Test") {}
        ~UILayer() {}

        void OnAttach() override {
            b1 = new Button(0, 0, 200, 100);
            b2 = new Button(500, 0, 200, 100);
        }
        void OnDetach() override {}

        void OnUpdate() override {
            //INFO("B1: %i", b1->GetID());
            //INFO("B2: %i", b2->GetID());
        }

        void OnEvent(Event& event) override {
            EventDispatcher dispatcher(event);
            dispatcher.dispatch<MouseMovedEvent>(UILayer::Mouse);
        }

        static bool Mouse(MouseMovedEvent& event) {
            //INFO("Mouse moved: (%f, %f)", event.getX(), event.getY());
            if (b1->IsHovered(event.getX(), event.getY())) {
                b1->OnHover();
            }
            if (b2->IsHovered(event.getX(), event.getY())) {
                b2->OnHover();
            }
            return false;
        }

        static Button* b1;
        static Button* b2;

};

Button* UILayer::b1 = nullptr;
Button* UILayer::b2 = nullptr;

int main() {
    /*
     * Application is the whole thing
     * Contains layers (GUI, Game, etc)
     * GUI is just rectangles that when clicked have different events
     * Application has main run loop
     * Game has separate loop (layer loop)
     

    Application app;

    app.PushLayer(new UILayer());

    app.Run();
    /* Loop until the user closes the window */ 
    //while (!glfwWindowShouldClose(app.GetWindow()->getWindow()))
    //{
        //glClearColor(0.2f, 0.2f, 0.2f, 0.0f );

        /* Render here */
        //glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        //glfwSwapBuffers(app.GetWindow()->getWindow());

        /* Poll for and process events 
        //glfwPollEvents();
    //}

    //glfwTerminate();
    return 0;
}
*/