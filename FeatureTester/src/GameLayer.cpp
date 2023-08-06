#include "GameLayer.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <Fallen/Logger.h>
#include <Fallen/Renderer/Renderer2D.h>
#include <Fallen/Renderer/Renderer.h>
#include <Fallen/Application.h>
#include "Player.h"

GameLayer::GameLayer()
{
	Renderer2D::Init();
	m_Entities.push_back(new Player());
}

GameLayer::~GameLayer()
{

}

void GameLayer::OnAttach()
{

}

void GameLayer::OnDetach()
{

}

void GameLayer::OnUpdate(TimeStep ts)
{
	Renderer::ClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	Renderer::Clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Renderer2D::Begin();

	for (auto entity : m_Entities)
	{
		entity->OnUpdate(ts);
		if (entity->HasComponent<QuadSprite>()) {
			Transform& trans = entity->GetComponent<Transform>();
			QuadSprite& sprite = entity->GetComponent<QuadSprite>();
			Renderer2D::DrawQuad(trans.position, trans.scale, sprite.color);
		}
	}

	Renderer2D::End();
}

void GameLayer::OnEvent(Event& event)
{
	EventDispatcher dispatcher(event);

}
