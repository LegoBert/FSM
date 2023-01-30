#include "Agent.h"

Agent::Agent(string n, int id) : BaseGameEntity(n,id) {
	currentLocation = Location::Home;
	currency = rand() % (100 - 50 + 1) + 50;
	energy = rand() % (25 + 1);
	thirst = rand() % (50 + 1);
	hunger = rand() % (50 + 1);
	happines = rand() % (100 - 50 + 1) + 50;

	agentStateMachine = new StateMachine(this);
	agentStateMachine->SetCurrent(&GoToSleep::Instance());
	//agentStateMachine->SetGlobal();
};

Agent::~Agent() {
	delete agentStateMachine;
}

void Agent::Update() {
	// Randomly affect stats
	energy -= rand() % (10);
	thirst += rand() % (10);
	hunger += rand() % (10);
	happines -= rand() % (10);

	agentStateMachine->Update();

	// Lose or regenerate HP
	if (thirst > 100 || hunger > 100 || happines < 0) {
		LossHP();
	}
	else {
		RegenHP();
	}
};

bool Agent::HandleMessage(const Telegram& msg)
{
	return agentStateMachine->HandleMessage(msg);
}