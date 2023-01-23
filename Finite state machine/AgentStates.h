#pragma once
#include <cmath>
#include <vector>
#include <iostream>
#include "State.h"
using namespace std;

class GoToSleep : public State {
private:
	GoToSleep() = default;
	static GoToSleep instance;
public:
	static GoToSleep* Instance() { return &instance; }
	virtual void Enter(Agent* pAgent);
	virtual void Execute(Agent* pAgent);
	virtual void Exit(Agent* pAgent);
};

