#include "Agent.h"

Agent::Agent(string n, int id) : BaseGameEntity(n,id) {
	currentLocation = Location::Home;
	currency = rand() % (100 - 50 + 1) + 50;
	energy = rand() % (100);
	thirst = rand() % (50 + 1);
	hunger = rand() % (50 + 1);
	happines = rand() % (100 - 50 + 1) + 50;

	agentStateMachine = new StateMachine(this);
	agentStateMachine->SetCurrent(&GoToSleep::Instance());
	//agentStateMachine->SetGlobal();
};

Agent::~Agent() {
	delete agentStateMachine;
}

void Agent::Update() {
	// Randomly affect stats
	if (alive) {
		energy -= rand() % (6);
		thirst += rand() % (6);
		hunger += rand() % (6);
		happines -= rand() % (6);

		// Lose or regenerate HP
		if (thirst > 100 || hunger > 100 || happines < 0) {
			LossHP();
		}
		else {
			RegenHP();
		}

		agentStateMachine->Update();
	}
	else {
		cout << "Man, I am dead!" << endl;
		cout << "Money: " << GetCurrency() << endl;
		cout << "Thirst: " << GetThirst() << endl;
		cout << "Hunger: " << GetHunger() << endl;
		cout << "Happines: " << GetHappines() << endl;
	}
};

bool Agent::HandleMessage(const Telegram& msg)
{
	return agentStateMachine->HandleMessage(msg);
}