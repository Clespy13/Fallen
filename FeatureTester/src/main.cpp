#include <Fallen/Application.h>

#include "UILayer.h"
#include "GameLayer.h"

int main() {

    Application* app = new Application();


    app->PushLayer(new GameLayer());
    app->PushLayer(new UILayer());

    app->Run();

    return 0;
}