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

class GoToWork : public State {
private:
	GoToWork() = default;
	static GoToWork instance;
public:
	static GoToWork* Instance() { return &instance; }
	virtual void Enter(Agent* pAgent);
	virtual void Execute(Agent* pAgent);
	virtual void Exit(Agent* pAgent);
};

class QuenchThirst : public State {
private:
	QuenchThirst() = default;
	static QuenchThirst instance;
public:
	static QuenchThirst* Instance() { return &instance; }
	virtual void Enter(Agent* pAgent);
	virtual void Execute(Agent* pAgent);
	virtual void Exit(Agent* pAgent);
};

class SatisfyHunger : public State {
private:
	SatisfyHunger() = default;
	static SatisfyHunger instance;
public:
	static SatisfyHunger* Instance() { return &instance; }
	virtual void Enter(Agent* pAgent);
	virtual void Execute(Agent* pAgent);
	virtual void Exit(Agent* pAgent);
};