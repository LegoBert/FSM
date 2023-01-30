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
	EntityManager() = default;
	vector<BaseGameEntity*> m_EntityMap;
public:
	static EntityManager& Instance() { 
		static EntityManager instance;
		return instance;
	}
	void RegisterEntity(BaseGameEntity* newEntity);
	BaseGameEntity* GetEntityFromID(int id);
	void RemoveEntity(BaseGameEntity* pEntity);
};
