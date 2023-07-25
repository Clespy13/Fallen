#pragma once

class Widget {
    public:
        Widget() {}
        virtual ~Widget() = default;

        virtual void OnHover() {};
        virtual void OnClick() {};
};
