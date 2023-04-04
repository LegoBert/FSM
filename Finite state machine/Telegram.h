#pragma once

struct Telegram {
	int sender;
	int receiver;
	int msg;
	float dispatchTime;
	Telegram(float d, int s, int r, int m) {
		dispatchTime = d;
		sender = s;
		receiver = r;
		msg = m;
	}
};

enum MessageType
{
	JoinMe,
	Hungry,
	Hello,
	OrderBeer,
	Question,
	Awnser,
	GoodBye,
};

enum Location {
	Home,
	Work,
	Bar,
	Resturant,
};