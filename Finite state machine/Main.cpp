#include "Agent.h"
#include "MessageDispatcher.h"
#include "EntityManager.h"
#include "GameClock.h"

EntityManager& EntityMgr = EntityManager::Instance();


int main() {
	GameClock clock = GameClock(1, 8, 0);
	//Adding the entities
	EntityMgr.RegisterEntity(new Agent("Kevin Bacon", nextValidID));
	EntityMgr.RegisterEntity(new Agent("Jhon Cena", nextValidID));
	EntityMgr.RegisterEntity(new Agent("Andrew Lincoln", nextValidID));
	EntityMgr.RegisterEntity(new Agent("Pedro Pascal", nextValidID));

	while (true) {
		clock.Update();
		// Update all the entities
		for (int i = 0; i < EntityMgr.m_EntityMap.size(); i++) {
			//EntityMgr.GetEntityFromID(i)->Update();
			EntityMgr.m_EntityMap[i]->Update();
		}

	}
	return 0;
}