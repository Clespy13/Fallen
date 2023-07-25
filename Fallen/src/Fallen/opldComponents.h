#pragma once

#include <string>

#include <glm/glm.hpp>

struct Component {
	virtual std::string Type() const { return "Component"; };
};

struct ID : public Component {
	std::string UUID;

	ID() = default;
	ID(std::string uuid) { UUID = uuid; }

	std::string Type() const override { return "ID"; };
};

struct Tag : public Component {
	std::string tag;

	Tag() = default;
	Tag(std::string name) : tag(name) {};

	std::string Type() const override { return "Tag"; };
};


struct Transform : public Component {
	glm::vec3 position{ 0.0f, 0.0f, 0.0f };
	glm::vec3 rotation{ 0.0f, 0.0f, 0.0f };
	glm::vec3 scale{ 1.0f, 1.0f, 1.0f };

	Transform() = default;

	void setPosition(glm::vec3 pos) { position.x = pos.x; position.y = pos.y; position.z = pos.z; }
	void setPosition(float* pos) { position.x = pos[0]; position.y = pos[1]; position.z = pos[2]; }

	void setRotation(glm::vec3 rot) { rotation.x = rot.x; rotation.y = rot.y; rotation.z = rot.z; }
	void setRotation(float* rot) { rotation.x = rot[0]; rotation.y = rot[1]; rotation.z = rot[2]; }

	void setScale(glm::vec3 sca) { scale.x = sca.x; scale.y = sca.y; scale.z = sca.z; }
	void setScale(float* sca) { scale.x = sca[0]; scale.y = sca[1]; scale.z = sca[2]; }

	std::string Type() const override { return "Transform"; };

};

struct QuadSprite : public Component {
	glm::vec4 color = { 1.0f, 0.0f, 0.0f, 1.0f };

	QuadSprite() = default;

	std::string Type() const override { return "QuadSprite"; };

};