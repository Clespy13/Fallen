#pragma once

#include <Fallen/Scene/Entity.h>
#include <Fallen/Events/Event.h>

class Bullet : public Entity {
	public:
	Bullet();
	~Bullet();

	void OnUpdate(TimeStep ts) override;
	void OnEvent(Event& event) override;
};