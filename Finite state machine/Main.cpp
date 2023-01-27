#include "Agent.h"
#include "MessageDispatcher.h"
#include "EntityManager.h"

EntityManager* EntityMgr = EntityManager::Instance();


int main() {
	//EntityManager* EntityMgr = EntityManager::Instance();
	//Adding the entities
	EntityMgr->RegisterEntity(new Agent("Kevin Bacon", nextValidID));
	EntityMgr->RegisterEntity(new Agent("Jhon Cena", nextValidID));
	EntityMgr->RegisterEntity(new Agent("Andrew Lincoln", nextValidID));
	EntityMgr->RegisterEntity(new Agent("Pedro Pascal", nextValidID));

	while (true) {

		// Update all the entities
		for (int i = 0; i <= nextValidID; i++) {
			EntityMgr->GetEntityFromID(i)->Update();
		}


	}
	return 0;
}