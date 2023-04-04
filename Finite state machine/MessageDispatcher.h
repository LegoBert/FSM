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
	static MessageDispatcher& Instance() { 
		static MessageDispatcher instance;
		return instance; 
	}
	void DispatchMessage(int sender, int receiver, int msg);
	void SetEntityManager(EntityManager* entityMgr) { this->entityMgr = entityMgr; }
	EntityManager* GetEntityManager() { return entityMgr; }
};