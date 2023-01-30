#pragma once
#include <cmath>
#include <vector>
#include <iostream>
#include <cassert>
#include "Telegram.h"
using namespace std;

class State;
class Agent;

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
	bool HandleMessage(const Telegram& msg) const;

	// Getters and setters
	State* CurrentState() const { return currentState; }
	State* PreviousState() const { return previousState; }
	//State* GlobalState() const { return globalState; }
	void SetCurrent(State* s) { currentState = s; }
	void SetPrevious(State* s) { previousState = s; }
	//void SetGlobal(State* s) { globalState = s; }

};