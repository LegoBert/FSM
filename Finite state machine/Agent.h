#pragma once
#ifndef Agent_H
#define Agent_H
#include <cmath>
#include <vector>
#include <iostream>
#include "BaseGameEntity.h"
#include "StateMachine.h"
#include "AgentStates.h"
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
	void Update(int hour, int min) override;
	void MakeDecision(int hour, int min);
	bool HandleMessage(const Telegram& msg);
	StateMachine* GetFSM()const { return agentStateMachine; }

	// Getters and setters for stats
	Location GetLocation() { return currentLocation; }
	void ChangeLocation(Location newLocation) { currentLocation = newLocation; }

	int GetCurrency() { return currency; }
	void AddCurrency(int val) { currency += val; }
	void SetCurrency(int val) { currency = val; }

	int GetEnergy() { return energy; }
	void AddEnergy(int val) { energy += val; }
	void SetEnergy(int val) { energy = val; }

	int GetThirst() { return thirst; }
	void AddThirst(int val) { thirst += val; }
	void SetThirst(int val) { thirst = val; }

	int GetHunger() { return hunger; }
	void AddHunger(int val) { hunger += val; }
	void setHunger(int val) { hunger = val; }

	int GetHappines() { return happines; }
	void addHappines(int val) { happines += val; }
	void setHappines(int val) { happines = val; }

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
	bool IsHungry() {
		if (hunger >= 50) return true;
		return false;
	}
	bool IsThirsty() {
		if (thirst >= 50) return true;
		return false;
	}
	bool IsFatigue() {
		if (energy <= 0) return true;
		return false;
	}
};

#endif