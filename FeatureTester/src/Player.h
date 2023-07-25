#pragma once

#include <Fallen/Scene/Entity.h>

class Player : public Entity
{
	public:
	Player();
	~Player();

	void OnUpdate();

	private:
	int m_Health;
	int m_Stamina;

};
