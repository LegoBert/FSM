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
	static EntityManager instance;
	EntityManager() = default;
	vector<BaseGameEntity*> m_EntityMap;
public:
	static EntityManager* Instance() { return &instance; }
	void RegisterEntity(BaseGameEntity* newEntity);
	BaseGameEntity* GetEntityFromID(int id);
	void RemoveEntity(BaseGameEntity* pEntity);
};
