#include "Application.h"

#include "Logger.h"
#include "Helpers.h"

#include "Events/MouseEvent.h"

Application* Application::s_Instance = nullptr;
bool Application::m_Running = true;

Application::Application() {
    s_Instance = this;

    m_Window = new Window("Fallen", 640, 480);
    m_Window->CreateWindow();
    m_Window->SetEventCallback(Application::OnEvent);
}

Application::~Application() {
}

void Application::Run() {
    while (m_Running) {
        //for (Layer* layer : m_LayerStack)
          //  layer->OnUpdate();

//        m_Window->OnUpdate();
    }
}

void Application::OnEvent(Event& event) {
    EventDispatcher dispatcher(event);
    dispatcher.dispatch<WindowCloseEvent>(Application::OnWindowClose);
    // dispatcher needed
    // then send to all layers in the stack
}
/*
void Application::PushLayer(Layer* layer) {
    m_LayerStack.PushLayer(layer);
    layer->OnAttach();
}*/

bool Application::OnWindowClose(WindowCloseEvent& event) {
    m_Running = false;
    return true;
}
