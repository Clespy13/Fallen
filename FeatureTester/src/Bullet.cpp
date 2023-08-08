#include "Bullet.h"

Bullet::Bullet()
{
}

Bullet::~Bullet()
{
}

void Bullet::OnUpdate(TimeStep ts)
{
	auto pos = GetComponent<Transform>().position;
	GetComponent<Transform>().SetPosition(pos + glm::vec3{1.0f * ts, 0.0f, 0.0f});
}

void Bullet::OnEvent(Event& event)
{
}
