#include "Application.h"

#include "Logger.h"

#include "Events/MouseEvent.h"

Application* Application::s_Instance = nullptr;
bool Application::m_Running = true;
LayerStack Application::m_LayerStack;


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
        
        double time = Time::GetTime();
        TimeStep timeStep = time - m_LastFrameTime;
        m_LastFrameTime = time;

        for (Layer* layer : m_LayerStack)
            layer->OnUpdate(timeStep);

        m_Window->OnUpdate();
    }
}

void Application::OnEvent(Event& event) {
    EventDispatcher dispatcher(event);
    dispatcher.dispatch<WindowCloseEvent>(Application::OnWindowClose);

    for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it) {
        if (event.m_Handled)
            break;
        (*it)->OnEvent(event);
    }
}

void Application::PushLayer(Layer* layer) {
    m_LayerStack.PushLayer(layer);
    layer->OnAttach();
}

bool Application::OnWindowClose(WindowCloseEvent& event) {
    m_Running = false;
    return true;
}
