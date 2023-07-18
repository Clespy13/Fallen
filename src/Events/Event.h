#pragma once

enum class EventType {
    None = 0,
    WindowClose, WindowFocus, WindowResize,
    KeyPressed, KeyReleased,
    MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled,
};

// Functions to be defined in every child class of the Event class
// ## returns the index in the enum up above
// # returns name of the class as a string

#define SET_EVENT_TYPE(type) \
    static EventType GetStaticType() { return EventType::type; } \
    virtual EventType GetType() const override { return GetStaticType(); } \
    virtual const char* GetName() const override { return #type; }

class Event {
    public:
        virtual EventType GetType() const = 0;
        virtual const char* GetName() const = 0;
        bool m_Handled = false;
};

class EventDispatcher {
    public:
        EventDispatcher(Event& event) : m_Event(event) { }

        template<typename T>
        void dispatch(bool (*func)(T&)) {
            if (m_Event.GetType() == T::GetStaticType())
                m_Event.m_Handled = func(*(T*)&m_Event);
        }
    private:
        Event& m_Event;

};
