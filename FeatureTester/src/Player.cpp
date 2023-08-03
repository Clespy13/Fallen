#include "Player.h"

#include <Fallen/Events/Input.h>
#include <Fallen/Logger.h>

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

void Player::OnUpdate()
{
	if (Input::IsKeyPressed(Key::W)) {
		Transform& pos = GetComponent<Transform>();
		pos.position -= glm::vec3(1.0f, 0.0f, 0.0f);
		pos.SetPosition(pos.position);
	}
	
	if (Input::IsKeyPressed(Key::A)) {
		Transform& pos = GetComponent<Transform>();
		pos.position -= glm::vec3(0.0f, 1.0f, 0.0f);
		pos.SetPosition(pos.position);
	}
	
	if (Input::IsKeyPressed(Key::S)) {
		Transform& pos = GetComponent<Transform>();
		pos.position += glm::vec3(1.0f, 0.0f, 0.0f);
		pos.SetPosition(pos.position);
	}

	if (Input::IsKeyPressed(Key::D)) {
		Transform& pos = GetComponent<Transform>();
		pos.position += glm::vec3(0.0f, 1.0f, 0.0f);
		pos.SetPosition(pos.position);
	}
}
