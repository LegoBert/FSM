#include "Agent.h"

Agent::Agent(string n, int id) : BaseGameEntity(n,id) {
	currentLocation = Location::Home;
	currency = rand() % (100 - 50 + 1) + 50;
	thirst = rand() % (50 + 1);
	hunger = rand() % (50 + 1);
	happines = rand() % (100 - 50 + 1) + 50;

	agentStateMachine = new StateMachine(this);
	agentStateMachine->SetCurrent(&GoToWork::Instance());
};

Agent::~Agent() {
	delete agentStateMachine;
}

void Agent::Update(int hour, int min) {
	// Randomly affect stats
	if (alive) {
		if (this->GetLocation() != Location::Home) {
			thirst += rand() % (10) + 1;
			hunger += rand() % (10) + 1;
			happines -= rand() % (1) + 1;
		}
		else {
			thirst += rand() % (1) + 1;
			hunger += rand() % (1) + 1;
		}

		// Lose or regenerate HP
		if (thirst > 100 || hunger > 100 || happines < 0) {
			LossHP();
		}
		else {
			RegenHP();
		}

		MakeDecision(hour,min);
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

bool Agent::HandleMessage(const Telegram& msg) {
	return agentStateMachine->HandleMessage(msg);
}

void Agent::MakeDecision(int hour, int min) {
	// Sleep
	if (hour >= 23 || hour <= 7)
		this->GetFSM()->ChangeState(&GoToSleep::Instance());
	else
	{
		// Hungry
		if (this->IsHungry() && !(this->GetCurrency() < 25)) {
			this->GetFSM()->ChangeState(&SatisfyHunger::Instance());
			return;
		}
		// Drink
		if (this->IsThirsty()) {
			this->GetFSM()->ChangeState(&QuenchThirst::Instance());
			return;
		}
		// Go to work if not hungry or thirtsy
		this->GetFSM()->ChangeState(&GoToWork::Instance());
	}
}