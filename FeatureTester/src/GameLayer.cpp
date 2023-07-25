#include "GameLayer.h"

#include <Fallen/Logger.h>
#include "Player.h"

GameLayer::GameLayer()
{
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

void GameLayer::OnUpdate()
{
	for (auto entity : m_Entities)
	{
		entity->OnUpdate();
	}
}

void GameLayer::OnEvent(Event& event)
{
	EventDispatcher dispatcher(event);

}
