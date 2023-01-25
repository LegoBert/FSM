#pragma once
#include <cmath>
#include <vector>
#include <iostream>
#include "BaseGameEntity.h"
#include "StateMachine.h"
using namespace std;

enum Location{
	Home,
	Work,
	Bar,
	Resturant,
};

class StateMachine;

class Agent : public BaseGameEntity {
private:
	StateMachine* agentStateMachine;
	Location currentLocation;

	int currency;
	int energy;
	int thirst;
	int hunger;
	int happines;

public:
	Agent();
	~Agent();
	void Update();
	//void ChangeState(State* newState);

	// Getters and setters
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
};