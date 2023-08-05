#include "Player.h"

#include <Fallen/Events/Input.h>
#include <Fallen/Logger.h>
#include <Fallen/Application.h>

Player::Player()
{
	AddComponent<ID>("player");
	AddComponent<Tag>("Player");
	AddComponent<Transform>();
	AddComponent<QuadSprite>();
}

Player::~Player()
{
}

void Player::OnUpdate(TimeStep ts)
{
	if (Input::IsKeyPressed(Key::W)) {
		Transform& pos = GetComponent<Transform>();
		pos.position += glm::vec3(0.0f, 1.0f * ts, 0.0f);
		pos.SetPosition(pos.position);
	}
	
	if (Input::IsKeyPressed(Key::A)) {
		Transform& pos = GetComponent<Transform>();
		pos.position -= glm::vec3(1.0f * ts, 0.0f, 0.0f);
		pos.SetPosition(pos.position);
	}
	
	if (Input::IsKeyPressed(Key::S)) {
		Transform& pos = GetComponent<Transform>();
		pos.position -= glm::vec3(0.0f, 1.0f * ts, 0.0f);
		pos.SetPosition(pos.position);
	}

	if (Input::IsKeyPressed(Key::D)) {
		Transform& pos = GetComponent<Transform>();
		pos.position += glm::vec3(1.0f * ts, 0.0f, 0.0f);
		pos.SetPosition(pos.position);
	}
}
