#include "StateMachine.h"

StateMachine::StateMachine(Agent* o) {
	owner = o;
	currentState = nullptr;
	previousState = nullptr;
	//globalState = nullptr;
}

void StateMachine::Update() {
	//if (globalState) globalState->Execute(owner);
	if (currentState) currentState->Execute(owner);
}

void StateMachine::ChangeState(State* newState) {
	assert(newState);
	previousState = currentState;
	if(currentState != nullptr)
		currentState->Exit(owner);
	currentState = newState;
	currentState->Enter(owner);
}

void StateMachine::RevertState() {
	ChangeState(previousState);
}

bool StateMachine::HandleMessage(const Telegram& msg) const
{
	if (currentState && currentState->OnMessage(owner, msg))
	{
		return true;
	}
	return false;
}