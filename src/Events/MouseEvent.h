#pragma once

#include "Event.h"

class MouseButtonEvent : public Event {
    public:
        int GetMouseButtonCode() { return m_MouseCode; }

    protected:
        MouseButtonEvent(int mouseCode) : m_MouseCode(mouseCode) {}
        int m_MouseCode;
};

class MouseButtonPressedEvent : public MouseButtonEvent {
    public:
        MouseButtonPressedEvent(int mouseCode)
            : MouseButtonEvent(mouseCode) {}

        SET_EVENT_TYPE(MouseButtonPressed);
};

class MouseButtonReleasedEvent: public MouseButtonEvent {
    public:
        MouseButtonReleasedEvent(int mouseCode)
            : MouseButtonEvent(mouseCode) {}

        SET_EVENT_TYPE(MouseButtonReleased);
};

class MouseMovedEvent : public Event {
    public:
        MouseMovedEvent(float x, float y)
            : m_mouseX(x), m_mouseY(y) {}

        float getX() { return m_mouseX; }
        float getY() { return m_mouseY; }

        SET_EVENT_TYPE(MouseMoved);
    private:
        float m_mouseX, m_mouseY;

};


class MouseScrolledEvent : public Event {
    public:
        MouseScrolledEvent(float xOffset, float yOffset)
            : m_XOffset(xOffset), m_YOffset(yOffset) {}

        float getXOffset() { return m_XOffset; }
        float getYOffset() { return m_YOffset; }

        SET_EVENT_TYPE(MouseScrolled);
    private:
        float m_XOffset, m_YOffset;
};



