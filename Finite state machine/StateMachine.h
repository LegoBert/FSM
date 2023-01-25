#pragma once
#include <cmath>
#include <vector>
#include <iostream>
#include <cassert>
#include "State.h"
using namespace std;

class StateMachine {
private:
	Agent* owner;
	State* currentState;
	State* previousState;
	//State* globalState;
public:
	StateMachine(Agent* owner);
	void Update();
	void ChangeState(State* newState);
	void RevertState();

	// Getters and setters
	State* CurrentState() const { return currentState; }
	State* PreviousState() const { return previousState; }
	//State* GlobalState() const { return globalState; }
	void SetCurrent(State* s) { currentState = s; }
	void SetPrevious(State* s) { previousState = s; }
	//void SetGlobal(State* s) { globalState = s; }

};