#include "AgentStates.h"
#include "Agent.h"

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
	pAgent->SetEnergy(100);
	// Eat
	if (pAgent->IsHungry())
		pAgent->GetFSM()->ChangeState(&SatisfyHunger::Instance());
	// Drink
	if (pAgent->IsThirsty())
		pAgent->GetFSM()->ChangeState(&QuenchThirst::Instance());
	// Work 
		pAgent->GetFSM()->ChangeState(&GoToWork::Instance());
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
	pAgent->AddEnergy(-5);
	pAgent->AddCurrency(rand() % (50 - 10 + 1) + 10);
	// Eat
	if (pAgent->IsHungry())
		pAgent->GetFSM()->ChangeState(&SatisfyHunger::Instance());
	// Drink
	if (pAgent->IsThirsty())
		pAgent->GetFSM()->ChangeState(&QuenchThirst::Instance());
	// Sleep
	if (pAgent->IsFatigue())
		pAgent->GetFSM()->ChangeState(&GoToSleep::Instance());
}

void GoToWork::Exit(Agent* pAgent) {
	cout << pAgent->GetNameOfEntity()
		<< ": Done Working"
		<< endl;
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
	pAgent->AddThirst(-80);
	// Revert to previous state
	pAgent->GetFSM()->RevertState();
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
	int hunger = pAgent->GetHunger();
	int currency = pAgent->GetCurrency();
	if (currency > hunger) {
		pAgent->AddCurrency(-hunger);
		pAgent->AddHunger(-hunger);
	}
	else {
		pAgent->AddCurrency(-currency);
		pAgent->AddHunger(-currency);
	}
	// Drink if thirsty
	if (pAgent->IsThirsty())
		pAgent->GetFSM()->ChangeState(&QuenchThirst::Instance());
	// Revert to previous state
	pAgent->GetFSM()->RevertState();
}

void SatisfyHunger::Exit(Agent* pAgent) {
	cout << pAgent->GetNameOfEntity()
		<< ": That's better"
		<< endl;
}