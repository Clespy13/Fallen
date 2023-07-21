#pragma once

#include "Widget.h"

class Button : public Widget {
    public:
        Button();
        Button(int width, int height);
        ~Button();

        void OnHover() override;
        void OnClick() override;

        int GetID() { return m_ID; }
    private:
        static int m_NextID;
        int m_ID;

        int m_Width, m_Height;
};
