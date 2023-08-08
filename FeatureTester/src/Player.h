#pragma once

#include <Fallen/Scene/Entity.h>
#include <Fallen/Events/KeyEvent.h>
#include <Fallen/Events/Event.h>
#include <Fallen/Time.h>
#include "Bullet.h"

class Player : public Entity
{
	public:
	Player();
	~Player();

	void OnUpdate(TimeStep ts) override;
	void OnEvent(Event& event) override;

	static bool SpawnBullet(KeyPressedEvent& event);

	private:
	int m_Health;
	int m_Stamina;

};
