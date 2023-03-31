#pragma once
#pragma once
#include <iostream>
#include <string>
using namespace std;

class GameClock {
public:
	int day, hour, min;
	GameClock(int day, int hour, int min);
	void Update();
};

GameClock::GameClock(int day, int hour, int min) {
	this->day = day;
	this->hour = hour;
	this->min = min;
	if (hour > 24)
		this->hour = 0;
	if (min != 0 && min != 30)
		this->hour = 0;
}

void GameClock::Update() {
	min += 30;
	if (min == 60)
	{
		hour++;
		min = 0;
		if (hour == 24)
		{
			day++;
			hour = 0;
			cout << "----------------------------------------" << endl;
		}
	}

	string h, m;
	if (hour < 10)
		h = "0";
	else
		h = "";
	if (min == 0)
		m = "0";
	else
		m = "";
	
	cout << "Day: " << day << " Time: " << h << hour << ":" << m << min << endl;
}