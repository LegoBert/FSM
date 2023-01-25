#include "MessageDispatcher.h"

void MessageDispatcher::Discharge(BaseGameEntity* receiver, const Telegram& msg) {

}

void MessageDispatcher::DispatchMessage(float delay, int sender, int receiver, int msg) {
	BaseGameEntity* pReceiver = entityMgr->GetEntityFromID(receiver);
	Telegram telegram(0, sender, receiver, msg);

	if (delay <= 0.0) {
		Discharge(pReceiver, telegram);
	}
	else {
		float currentTime = std::chrono::steady_clock::now();
		telegram.dispatchTime = currentTime + delay;
		priorityQ.push_back(telegram);
	}
}

void MessageDispatcher::DispatchDelayedMessages() {
	float CurrentTime = Clock->GetCurrentTime();
	while ((priorityQ.begin()->dispatchTime < CurrentTime) && (priorityQ.begin()->dispatchTime > 0))
	{
		Telegram telegram = *priorityQ.begin();
		BaseGameEntity* pReceiver = entityMgr->GetEntityFromID(telegram.receiver);
		Discharge(pReceiver, telegram);
		priorityQ.erase(priorityQ.begin());
	}
}