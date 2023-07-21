#include "Button.h"

int Button::m_NextID = 0;

Button::Button()
    : m_Width(400), m_Height(200) {
    m_ID = m_NextID;
    m_NextID++;
}

Button::Button(int width, int height) 
    : m_Width(width), m_Height(height) {
    m_ID = m_NextID;
    m_NextID++;
}

Button::~Button() {

}

void Button::OnHover() {

}

void Button::OnClick() {

}
