#pragma once
#ifndef Agent_H
#define Agent_H
#include <cmath>
#include <vector>
#include <iostream>
#include "BaseGameEntity.h"
#include "StateMachine.h"
#include "AgentStates.h" // problem?
using namespace std;

class StateMachine;

class Agent : public BaseGameEntity {
private:
	StateMachine* agentStateMachine;
	Location currentLocation;

	// Health
	int hp = 100;
	int max_hp = 100;
	int hp_loss = 10;
	int hp_regen = 5;
	bool alive = true;

	// Stats
	int currency;
	int energy;
	int thirst;
	int hunger;
	int happines;

public:
	Agent(string n , int id);
	~Agent();
	void Update();
	bool HandleMessage(const Telegram& msg);
	StateMachine* GetFSM()const { return agentStateMachine; }

	// Getters and setters for stats
	Location GetLocation() { return currentLocation; }
	void ChangeLocation(Location newLocation) { currentLocation = newLocation; }

	int GetCurrency() { return currency; }
	void ChangeCurrency(int val) { currency += val; }

	int GetEnergy() { return energy; }
	void ChangeEnergy(int val) { energy += val; }

	int GetThirst() { return thirst; }
	void ChangeThirst(int val) { thirst += val; }

	int GetHunger() { return hunger; }
	void ChangeHunger(int val) { hunger += val; }

	int GetHappines() { return happines; }
	void ChangeHappines(int val) { happines += val; }

	// Health Functions
	int GetHP() { return hp; }
	void RegenHP() { 
		if (hp < max_hp)
			hp += hp_regen;
		if (hp > max_hp)
			hp = max_hp;
	}
	void LossHP() {
		hp -= hp_loss;
		if (hp <= 0)
			alive = false;
	}
	bool GetAlive() { return alive; }
};

#endif