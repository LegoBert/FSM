#pragma once
#include <cmath>
#include <vector>
#include <iostream>
#include <cassert>
#include <string>
#include <chrono>
#include "EntityManager.h"
using namespace std;

class MessageDispatcher {
private:
	vector<Telegram> priorityQ;
	EntityManager* entityMgr;
	void Discharge(BaseGameEntity* receiver, const Telegram& msg);
	static MessageDispatcher instance;
	MessageDispatcher() = default;
public:
	static MessageDispatcher* Instance() { return &instance; }
	void DispatchMessage(float delay, int sender, int receiver, int msg);
	void DispatchDelayedMessages();
};
