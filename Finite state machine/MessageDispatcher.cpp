#include "MessageDispatcher.h"

void MessageDispatcher::Discharge(BaseGameEntity* receiver, const Telegram& msg) {
	receiver->HandleMessage(msg);
}

void MessageDispatcher::DispatchMessage(int sender, int receiver, int msg) {
	BaseGameEntity* pReceiver = entityMgr->GetEntityFromID(receiver);
	Telegram telegram(0, sender, receiver, msg);
	Discharge(pReceiver, telegram);
}