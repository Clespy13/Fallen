#pragma once

#include <Fallen/Scene/Entity.h>
#include <Fallen/Time.h>

class Player : public Entity
{
	public:
	Player();
	~Player();

	void OnUpdate(TimeStep ts);

	private:
	int m_Health;
	int m_Stamina;

};
