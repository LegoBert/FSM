#pragma once
#include <cmath>
#include <vector>
#include <iostream>
#include <cassert>
#include <string>
#include "BaseGameEntity.h"
using namespace std;

class EntityManager {
private:
	vector<BaseGameEntity*> m_EntityMap;
	static EntityManager instance;
	EntityManager() = default;
public:
	static EntityManager* Instance() { return &instance; }
	void RegisterEntity(BaseGameEntity* newEntity);
	BaseGameEntity* GetEntityFromID(int id);
	void RemoveEntity(BaseGameEntity* pEntity);
};
