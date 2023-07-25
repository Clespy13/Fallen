#include "Button.h"
#include "Fallen/Logger.h"


int Button::m_NextID = 0;

Button::Button()
    : m_PosX(0), m_PosY(0), m_Width(200), m_Height(100) {
    m_ID = m_NextID;
    m_NextID++;
}

Button::Button(int x, int y, int width, int height) 
    : m_PosX(x), m_PosY(y), m_Width(width), m_Height(height) {
    m_ID = m_NextID;
    m_NextID++;
}

Button::~Button() {

}

bool Button::IsHovered(int mouseX, int mouseY)
{
    return ((mouseX >= m_PosX && mouseX <= m_PosX + m_Width) &&
        (mouseY >= m_PosY && mouseY <= m_PosY + m_Height));
}

void Button::OnHover() {
    INFO("Button %i hovered", GetID());
}

void Button::OnClick() {
    INFO("Button %i was clicked", GetID());
}

