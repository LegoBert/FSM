#include "AgentStates.h"

// GoToSleep
void GoToSleep::Enter(Agent* pAgent) {
	if (pAgent->GetLocation() != Location::Home) {
		cout << "*Walking Home*" << endl;
		pAgent->ChangeLocation(Location::Home);
	}
}

void GoToSleep::Execute(Agent* pAgent) {
	cout << "Yawn, zzzzzzzzzz" << endl;
	pAgent->ChangeEnergy(rand() % (100 - 70 + 1) + 70);
}
	
void GoToSleep::Exit(Agent* pAgent) {
	cout << "Hello, world!" << endl;
}

// GoToWork
void GoToWork::Enter(Agent* pAgent) {
	if (pAgent->GetLocation() != Location::Home) {
		cout << "*Walking to work*" << endl;
		pAgent->ChangeLocation(Location::Work);
	}
}

void GoToWork::Execute(Agent* pAgent) {
	cout << "*Working*" << endl;
	pAgent->ChangeEnergy(-(rand() % (50 - 10 + 1) + 10));
}

void GoToWork::Exit(Agent* pAgent) {
	cout << "Done with work" << endl;
	pAgent->ChangeCurrency(rand() % (50 - 10 + 1) + 10);
}

// QuenchThirst
void QuenchThirst::Enter(Agent* pAgent) {
	cout << "Man, I am thirsty" << endl;
}

void QuenchThirst::Execute(Agent* pAgent) {
	cout << "*Drinking*" << endl;
	pAgent->ChangeThirst(rand() % (50 - 25 + 1) + 25);
}

void QuenchThirst::Exit(Agent* pAgent) {
	cout << "That's better" << endl;
}

// SatisfyHunger
void SatisfyHunger::Enter(Agent* pAgent) {
	cout << "Man, I am hungry" << endl;
	if (pAgent->GetLocation() != Location::Resturant) {
		cout << "*Walking to resturant*" << endl;
		pAgent->ChangeLocation(Location::Resturant);
	}
}

void SatisfyHunger::Execute(Agent* pAgent) {
	cout << "*Eating*" << endl;
	pAgent->ChangeCurrency(-(rand() % (40 - 10 + 1) + 10));
	pAgent->ChangeThirst(rand() % (50 - 25 + 1) + 25);
	pAgent->ChangeHunger(rand() % (50 - 25 + 1) + 25);
}

void SatisfyHunger::Exit(Agent* pAgent) {
	cout << "That's better" << endl;
}