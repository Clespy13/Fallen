#pragma once

#include <string>
#include <vector>
#include <memory>

class Entity
{
/*	public:
	Entity() {};

	virtual ~Entity() = default;

	virtual void OnUpdate() {};

	template<typename T, typename... Args>
	void AddComponent(Args&&... args) {
		m_Components.push_back(std::make_shared<T>(std::forward<Args>(args)...));
	}

	template<typename T>
	bool HasComponent() {
		return std::find_if(m_Components.begin(), m_Components.end(), [](std::shared_ptr<Component> comp)
			{ return comp->Type() == T().Type(); }) != m_Components.end();
	}

	template<typename T>
	void RemoveComponent() {
		auto it = std::find_if(m_Components.begin(), m_Components.end(), [](std::shared_ptr<Component> comp)
			{ return comp->Type() == T().Type(); });

		if (it != m_Components.end())
			m_Components.erase(it);
	}

	template <typename T>
	T& getComponent() {
		if (HasComponent<T>()) {
			auto it = std::find_if(m_Components.begin(), m_Components.end(), [](std::shared_ptr<Component> comp)
				{ return comp->Type() == T().Type(); });
			return *(std::dynamic_pointer_cast<T>(*it)).get();
		}
		return T();
	}

	std::string getUUID() { if (HasComponent<ID>()) return getComponent<ID>().UUID; else return "No ID"; }
	std::string getName() { if (HasComponent<Tag>()) return getComponent<Tag>().tag; else return "No Name"; }

	auto getComponents() { return m_Components; };

	private:
	std::vector<std::shared_ptr<Component>> m_Components;*/

};