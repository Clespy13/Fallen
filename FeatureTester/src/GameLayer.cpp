#include "GameLayer.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <Fallen/Logger.h>
#include <Fallen/Renderer/Renderer2D.h>
#include <Fallen/Renderer/Renderer.h>
#include <Fallen/Application.h>
#include "Player.h"

GameLayer* GameLayer::s_Instance = nullptr;

GameLayer::GameLayer()
{
	s_Instance = this;

	Renderer2D::Init();

	m_Scene = new Scene();
	m_Scene->CreateEntity<Player>("Player");
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

	auto entities = m_Scene->GetAllEntities();
	auto entity = entities->begin();
	for (; entity != entities->end(); entity++)
	{
		(*entity)->OnUpdate(ts);
		if ((*entity)->HasComponent<QuadSprite>()) {
			INFO("Entity: %s", (*entity)->GetComponent<Tag>().tag.c_str());
			Transform& trans = (*entity)->GetComponent<Transform>();
			QuadSprite& sprite = (*entity)->GetComponent<QuadSprite>();
			INFO("Scale: %f", trans.scale.x);
			Renderer2D::DrawQuad(trans.position, trans.scale, sprite.color);
		}
	}

	Renderer2D::End();
}

void GameLayer::OnEvent(Event& event)
{
	EventDispatcher dispatcher(event);
	auto entities = m_Scene->GetAllEntities();
	int nbOfEntities = m_Scene->GetNumberOfEntities();
	for (int i = 0; i != nbOfEntities; i++)
	{
		(*entities)[i]->OnEvent(event);
	}
}
