#include "Agent.h"

Agent::Agent() {
	currentLocation = Location::Home;
	currency = rand() % (100 - 50 + 1) + 50;
	energy = rand() % (25 + 1);
	thirst = rand() % (50 + 1);
	hunger = rand() % (50 + 1);
	happines = rand() % (100 - 50 + 1) + 50;

	agentStateMachine = new StateMachine(this);
	agentStateMachine->SetCurrent(GoToSleep::Instance());
	//agentStateMachine->SetGlobal();
};

Agent::~Agent() {
	delete agentStateMachine;
}

void Agent::Update() {
	energy += rand() % (10);
	thirst += rand() % (10);
	hunger += rand() % (10);
	happines -= rand() % (10);
	agentStateMachine->Update();
};

/*
void Agent::ChangeState(State* newState) {
	assert(currentState && newState);
	currentState->Exit(this);
	currentState = newState;
	currentState->Enter(this);
};
*/