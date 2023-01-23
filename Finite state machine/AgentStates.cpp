#include "AgentStates.h"

void GoToSleep::Enter(Agent* pAgent) {
	if (pAgent->GetLocation() != Location::Home) {
		cout << "Walking Home" << endl;
	}
	pAgent->ChangeLocation(Location::Home);
}

void GoToSleep::Execute(Agent* pAgent) {
	cout << "Yawn, zzzzzzzzzz" << endl;
	pAgent->ChangeEnergy(rand() % (100 - 70 + 1) + 70);
}
	
void GoToSleep::Exit(Agent* pAgent) {
	cout << "Hello, world!" << endl;
}

