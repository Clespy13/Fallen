#pragma once

#include "KeyCodes.h"
#include "MouseCodes.h"

#include <glm/vec2.hpp>

class Input {
    public:
    static bool IsKeyPressed(KeyCode key);

    static bool IsMouseButtonPressed(MouseCode button);
    static glm::vec2 GetMousePosition();
    static float GetMouseX();
    static float GetMouseY();
};