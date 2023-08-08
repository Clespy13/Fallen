#pragma once

#include "Entity.h"
#include <string>
#include <vector>
#include <map>
#include <set>

class Scene {
	public:
	Scene();
	~Scene();

	template<typename T>
	T CreateEntity(std::string name)
	{
		T* entity = new T();

		//std::string uuid = get_UUID();
		// check uuid doesn't already exist
		entity->AddComponent<ID>("uuid");

		int count = 1;
		size_t len = name.length();
		std::string nameSave = name + ' ';
		while (m_EntityNames.find(name) != m_EntityNames.end()) {
			name = nameSave + std::to_string(count);
			count++;
		}

		entity->AddComponent<Tag>(name.c_str());
		entity->AddComponent<Transform>();
		entity->AddComponent<QuadSprite>();

		//m_EntityMap[uuid] = *entity;
		m_EntityNames.insert(name);
		m_Entities.push_back(entity);
		m_NumberOfEntities++;

		return *entity;
	}


	auto GetAllEntities() { return &m_Entities; }

	int GetNumberOfEntities() { return m_NumberOfEntities; }

	private:
	std::map<std::string, Entity> m_EntityMap;
	std::set<std::string> m_EntityNames;
	std::vector<Entity*> m_Entities;
	int m_NumberOfEntities = 0;
};