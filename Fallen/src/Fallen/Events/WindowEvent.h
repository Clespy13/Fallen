#pragma once

#include "Event.h"

class WindowCloseEvent : public Event {
    public:
        WindowCloseEvent() {}

        SET_EVENT_TYPE(WindowClose);
};

class WindowResizeEvent : public Event {
    public:
        WindowResizeEvent(float width, float height)
            : m_Width(width), m_Height(height) {}

        float getWidth() { return m_Width; }
        float getHeight() { return m_Height; }

        SET_EVENT_TYPE(WindowResize);

    private:
        float m_Width, m_Height;
};

class WindowFocusEvent : public Event {
    public:
        WindowFocusEvent(int windowID)
            : m_WindowID(windowID) {}

        SET_EVENT_TYPE(WindowFocus);

    private:
        int m_WindowID;
};
