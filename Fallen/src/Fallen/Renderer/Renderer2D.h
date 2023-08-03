#pragma once

#include <glm/glm.hpp>

#include "Shader.h"

class Renderer2D {
	public:

	static void Init();

	static void DrawQuad(glm::vec2 position, glm::vec2 rotation, glm::vec4 color);
	static void DrawQuad(glm::vec3 position, glm::vec3 rotation, glm::vec4 color);

	private:
		static unsigned int VAO;
		static Shader* m_ShaderProgram;
		static glm::mat4 transform;

};