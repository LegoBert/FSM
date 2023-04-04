#pragma once
#include <cmath>
#include <vector>
#include <iostream>
#include "State.h"
#include "MessageDispatcher.h"
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
	virtual bool OnMessage(Agent*, const Telegram&) { return true; }
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
	virtual bool OnMessage(Agent*, const Telegram&);
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
	virtual bool OnMessage(Agent*, const Telegram&);
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
	virtual bool OnMessage(Agent*, const Telegram&);
};

class BarHangOut : public State {
private:
	BarHangOut() = default;
public:
	static BarHangOut& Instance() {
		static BarHangOut instance;
		return instance;
	}
	virtual void Enter(Agent* pAgent);
	virtual void Execute(Agent* pAgent);
	virtual void Exit(Agent* pAgent);
	virtual bool OnMessage(Agent*, const Telegram&);
};