#include "Renderer2D.h"
#include "Fallen/Logger.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

unsigned int Renderer2D::VAO;
Shader* Renderer2D::m_ShaderProgram;
glm::mat4 Renderer2D::transform = glm::mat4(1.0f);

void Renderer2D::Init() {
	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f,  0.5f, 0.0f
	};

	unsigned int VBO; // create VBO placement
	glGenBuffers(1, &VBO); // generate VBO ID and assign it

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	transform = glm::rotate(transform, glm::radians(90.0f), glm::vec3(0.0, 0.0, 1.0));
	transform = glm::scale(transform, glm::vec3(0.5, 0.5, 0.5));

	m_ShaderProgram = new Shader("C:/Dev/Fallen/FeatureTester/assets/shaders/Default.vs", "C:/Dev/Fallen/FeatureTester/assets/shaders/Default.fs");

	//m_ShaderProgram->Use();
	//m_ShaderProgram->SetMat4((std::string)"transform", transform);
}

void Renderer2D::DrawQuad(glm::vec2 position, glm::vec2 rotation, glm::vec4 color)
{
	DrawQuad({ position.x, position.y, 0.0f }, { rotation.x, rotation.y, 0.0f }, color);
}

void Renderer2D::DrawQuad(glm::vec3 position, glm::vec3 rotation, glm::vec4 color)
{
	transform = glm::rotate(transform, (float)glfwGetTime(), glm::vec3(0.0, 0.0, 1.0));
	m_ShaderProgram->Use();
	m_ShaderProgram->SetMat4((std::string)"transform", transform);

	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);


	//INFO("drawing quad pos: x: %f y: %f", position.x, position.y);
}
