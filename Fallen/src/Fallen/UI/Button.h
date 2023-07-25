#pragma once

class Button {
    public:
        Button();
        Button(int x, int y, int width, int height);
        ~Button();

        void OnHover();
        void OnClick();

        bool IsHovered(int mouseX, int mouseY);

        int GetID() { return m_ID; }
        
        float GetPosX() { return m_PosX; }
        float GetPosY() { return m_PosY; }
        
        int GetWidth() { return m_Width; }
        int GetHeight() { return m_Height; }
    private:
        static int m_NextID;
        int m_ID;

        int m_Width, m_Height;
        float m_PosX, m_PosY;
};
