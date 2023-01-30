#pragma once
#include <cmath>
#include <vector>
#include <iostream>
#include "State.h"
using namespace std;

class GoToSleep : public State {
private:
	GoToSleep() = default;
public:
	static GoToSleep& Instance() { 
		static GoToSleep instance;
		return instance;
	}
	virtual void Enter(Agent* pAgent);
	virtual void Execute(Agent* pAgent);
	virtual void Exit(Agent* pAgent);
};

class GoToWork : public State {
private:
	GoToWork() = default;
public:
	static GoToWork& Instance() {
		static GoToWork instance;
		return instance;
	}
	virtual void Enter(Agent* pAgent);
	virtual void Execute(Agent* pAgent);
	virtual void Exit(Agent* pAgent);
};

class QuenchThirst : public State {
private:
	QuenchThirst() = default;
public:
	static QuenchThirst& Instance() {
		static QuenchThirst instance;
		return instance;
	}
	virtual void Enter(Agent* pAgent);
	virtual void Execute(Agent* pAgent);
	virtual void Exit(Agent* pAgent);
};

class SatisfyHunger : public State {
private:
	SatisfyHunger() = default;
public:
	static SatisfyHunger& Instance() {
		static SatisfyHunger instance;
		return instance;
	}
	virtual void Enter(Agent* pAgent);
	virtual void Execute(Agent* pAgent);
	virtual void Exit(Agent* pAgent);
};