#pragma once

#include <glm/glm.hpp>

#include "Shader.h"

class Renderer2D {
	public:

	static void Init();

	static void Begin();
	static void End();
	static void Draw();

	static void DrawQuad(glm::vec2 position, glm::vec2 size, glm::vec4 color);
	static void DrawQuad(glm::vec3 position, glm::vec3 size, glm::vec4 color);
};