#pragma once
#include <cmath>
#include <vector>
#include <iostream>
#include "Agent.h"
using namespace std;

class State {
public:
	virtual void Enter(Agent*) = 0;
	virtual void Execute(Agent*) = 0;
	virtual void Exit(Agent*) = 0;
	virtual ~State() = default;
};
