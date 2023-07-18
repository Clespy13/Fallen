#pragma once

#include "Event.h"

class KeyEvent : public Event {
    public:
        inline int GetKeyCode() {
            return m_KeyCode;
        }

    protected:
        KeyEvent(int keycode) : m_KeyCode(keycode) {}

        int m_KeyCode;
};

class KeyPressedEvent : public KeyEvent {
    public:
        KeyPressedEvent(int keycode, int repeatCount) 
            : KeyEvent(keycode), m_RepeatCount(repeatCount) {}

        SET_EVENT_TYPE(KeyPressed);

    private:
        int m_RepeatCount;
};

class KeyReleasedEvent : public KeyEvent {
    public:
        KeyReleasedEvent(int keycode)
            : KeyEvent(keycode) {}

        SET_EVENT_TYPE(KeyReleased);
};
