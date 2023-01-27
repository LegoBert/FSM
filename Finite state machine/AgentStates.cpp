#include "AgentStates.h"

// GoToSleep
void GoToSleep::Enter(Agent* pAgent) {
	if (pAgent->GetLocation() != Location::Home) {
		cout << pAgent->GetNameOfEntity()
			<< ": Walking Home"
			<< endl;
		pAgent->ChangeLocation(Location::Home);
	}
}

void GoToSleep::Execute(Agent* pAgent) {
	cout << pAgent->GetNameOfEntity()
		<< ": ZZZ..."
		<< endl;
	pAgent->ChangeEnergy(rand() % (100 - 70 + 1) + 70);
	// Eat if hungry after waking up
	if (pAgent->GetHunger() > 20)
		pAgent->GetFSM()->ChangeState(SatisfyHunger::Instance());
	// Drink if thirsty after waking up
	if (pAgent->GetThirst() > 20)
		pAgent->GetFSM()->ChangeState(QuenchThirst::Instance());
}
	
void GoToSleep::Exit(Agent* pAgent) {
	cout << pAgent->GetNameOfEntity()
		<< ": Hello, world!"
		<< endl;
}

// GoToWork
void GoToWork::Enter(Agent* pAgent) {
	if (pAgent->GetLocation() != Location::Work) {
		cout << pAgent->GetNameOfEntity()
			<< ": Walking to work"
			<< endl;
		pAgent->ChangeLocation(Location::Work);
	}
}

void GoToWork::Execute(Agent* pAgent) {
	cout << pAgent->GetNameOfEntity()
		<< ": Working"
		<< endl;
	pAgent->ChangeEnergy(-(rand() % (50 - 10 + 1) + 10));
}

void GoToWork::Exit(Agent* pAgent) {
	cout << pAgent->GetNameOfEntity()
		<< ": Done Working"
		<< endl;
	pAgent->ChangeCurrency(rand() % (50 - 10 + 1) + 10);
}

// QuenchThirst
void QuenchThirst::Enter(Agent* pAgent) {
	cout << pAgent->GetNameOfEntity()
		<< ": Man, I am thirsty"
		<< endl;
}

void QuenchThirst::Execute(Agent* pAgent) {
	cout << pAgent->GetNameOfEntity()
		<< ": Drinking"
		<< endl;
	pAgent->ChangeThirst(rand() % (50 - 25 + 1) + 25);
}

void QuenchThirst::Exit(Agent* pAgent) {
	cout << pAgent->GetNameOfEntity()
		<< ": That's better"
		<< endl;
}

// SatisfyHunger
void SatisfyHunger::Enter(Agent* pAgent) {
	cout << pAgent->GetNameOfEntity()
		<< ": Man, I am hungry"
		<< endl;
	if (pAgent->GetLocation() != Location::Resturant) {
		cout << pAgent->GetNameOfEntity()
			<< ": Walking to resturant"
			<< endl;
		pAgent->ChangeLocation(Location::Resturant);
	}
}

void SatisfyHunger::Execute(Agent* pAgent) {
	cout << pAgent->GetNameOfEntity()
		<< ": Eating"
		<< endl;
	pAgent->ChangeCurrency(-(rand() % (40 - 10 + 1) + 10));
	pAgent->ChangeThirst(rand() % (50 - 25 + 1) + 25);
	pAgent->ChangeHunger(rand() % (50 - 25 + 1) + 25);
	// Drink if thirsty
	if (pAgent->GetThirst() > 20)
		pAgent->GetFSM()->ChangeState(QuenchThirst::Instance());
}

void SatisfyHunger::Exit(Agent* pAgent) {
	cout << pAgent->GetNameOfEntity()
		<< ": That's better"
		<< endl;
}