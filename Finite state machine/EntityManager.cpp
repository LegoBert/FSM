#include "EntityManager.h"

void EntityManager::RegisterEntity(BaseGameEntity* newEntity) {
	bool added = false;
	for (int i = 0; i < m_EntityMap.size(); i++) {
		if (m_EntityMap[i] == newEntity)
			added = true;
	}
	if (!added)
		m_EntityMap.push_back(newEntity);
	else
		cout << "ERROR: Entity already added" << endl;
}

BaseGameEntity* EntityManager::GetEntityFromID(int id) {
	for (int i = 0; i < m_EntityMap.size(); i++) {
		if (m_EntityMap[i]->ID() == id)
			return m_EntityMap[i];
	}
	cout << "ERROR: No entity with ID: " + to_string(id) + " exists" << endl;
	return nullptr;
}

void EntityManager::RemoveEntity(BaseGameEntity* pEntity) {
	for (int i = 0; i < m_EntityMap.size(); i++) {
		if (m_EntityMap[i] == pEntity)
			m_EntityMap.erase(m_EntityMap.begin() + (i - 1), m_EntityMap.begin() + i);
	}
	cout << "ERROR: No entity was removed from map" << endl;
}