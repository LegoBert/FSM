#include "AgentStates.h"
#include "Agent.h"

// GoToSleep
void GoToSleep::Enter(Agent* pAgent) {
	if (pAgent->GetLocation() != Location::Home) {
		cout << pAgent->GetNameOfEntity()
			<< ": Walking Home"
			<< endl;
		pAgent->ChangeLocation(Location::Home);
	}
}

void GoToSleep::Execute(Agent* pAgent) {
	cout << pAgent->GetNameOfEntity()
		<< ": ZZZ..."
		<< endl;
}
	
void GoToSleep::Exit(Agent* pAgent) {}

// GoToWork
void GoToWork::Enter(Agent* pAgent) {
	if (pAgent->GetLocation() != Location::Work) {
		cout << pAgent->GetNameOfEntity()
			<< ": Walking to work"
			<< endl;
		pAgent->ChangeLocation(Location::Work);
	}
}

void GoToWork::Execute(Agent* pAgent) {
	cout << pAgent->GetNameOfEntity()
		<< ": Working"
		<< endl;
	pAgent->AddCurrency(rand() % (50 - 10 + 1) + 10);
}

void GoToWork::Exit(Agent* pAgent) {}

// QuenchThirst
void QuenchThirst::Enter(Agent* pAgent) {}

void QuenchThirst::Execute(Agent* pAgent) {
	cout << pAgent->GetNameOfEntity()
		<< ": Drinking water"
		<< endl;
	pAgent->SetThirst(0);
	// Revert to previous state
	//pAgent->GetFSM()->RevertState();
}

void QuenchThirst::Exit(Agent* pAgent) {}

// SatisfyHunger
void SatisfyHunger::Enter(Agent* pAgent) {
	if (pAgent->GetLocation() != Location::Resturant) {
		cout << pAgent->GetNameOfEntity()
			<< ": Walking to resturant"
			<< endl;
		pAgent->ChangeLocation(Location::Resturant);
	}
	MessageDispatcher::Instance().DispatchMessage(pAgent->ID(), pAgent->ID(), MessageType::Hungry);
}

void SatisfyHunger::Execute(Agent* pAgent) {
	cout << pAgent->GetNameOfEntity()
		<< ": Eating"
		<< endl;
	int hunger = pAgent->GetHunger();
	int currency = pAgent->GetCurrency();
	if (currency > hunger) {
		pAgent->AddCurrency(-hunger);
		pAgent->AddHunger(-hunger);
	}
	else {
		pAgent->AddCurrency(-currency);
		pAgent->AddHunger(-currency);
	}
}

void SatisfyHunger::Exit(Agent* pAgent) {}

bool SatisfyHunger::OnMessage(Agent* pAgent, const Telegram& msg) {
	switch (msg.msg)
	{
		case MessageType::Hungry:
		{
			cout << pAgent->GetNameOfEntity()
				<< ": Man, I'm hungry"
				<< endl;
		}
	}
	return true;
}

// BarHangOut
void BarHangOut::Enter(Agent* pAgent) {
	if (pAgent->GetLocation() != Location::Bar) {
		cout << pAgent->GetNameOfEntity()
			<< ": Walking to the bar"
			<< endl;
		pAgent->ChangeLocation(Location::Bar);
	}
	MessageDispatcher::Instance().DispatchMessage(pAgent->ID(), pAgent->ID(), MessageType::OrderBeer);
}

void BarHangOut::Execute(Agent* pAgent) {
	cout << pAgent->GetNameOfEntity()
		<< ": Drinking beer"
		<< endl;
	pAgent->AddHappines(7);
}

void BarHangOut::Exit(Agent* pAgent) {}

bool BarHangOut::OnMessage(Agent* pAgent, const Telegram& msg) {
	switch (msg.msg)
	{
	case MessageType::OrderBeer:
	{
		cout << pAgent->GetNameOfEntity()
			<< ": One beer please!"
			<< endl;
		break;
	}
	case MessageType::Hello:
	{
		cout << pAgent->GetNameOfEntity()
			<< ": Hey man!"
			<< endl;
		break;
	}
	case MessageType::Question:
	{
		cout << pAgent->GetNameOfEntity()
			<< ": How are you!"
			<< endl;
		break;
	}
	case MessageType::Awnser:
	{
		cout << pAgent->GetNameOfEntity()
			<< ": Great now that you are here!"
			<< endl;
		break;
	}
	case MessageType::GoodBye:
	{
		cout << pAgent->GetNameOfEntity()
			<< ": ¨See ya!"
			<< endl;
		break;
	}
	}
	return true;
}