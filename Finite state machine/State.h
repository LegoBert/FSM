#pragma once
#include <cmath>
#include <vector>
#include <iostream>
#include "Agent.h"
#include "StateMachine.h"
#include "Telegram.h"
using namespace std;

class StateMachine;

class State {
public:
	virtual void Enter(Agent*) = 0;
	virtual void Execute(Agent*) = 0;
	virtual void Exit(Agent*) = 0;
	virtual ~State() = default;
	virtual bool OnMessage(Agent*, const Telegram&) = 0;
};
