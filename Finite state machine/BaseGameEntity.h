#pragma once
#include <cmath>
#include <vector>
#include <iostream>
#include "Telegram.h"
using namespace std;

class BaseGameEntity {
private:
	int m_ID;
	string name;
	void setID(int id) {
		m_ID = id;
		nextValidID++;
	}
public:
	BaseGameEntity() = default;
	BaseGameEntity(string n, int id) {
		setID(id);
		name = n;
	}
	~BaseGameEntity() = default;
	virtual void Update(int hour, int min) = 0;
	int ID() { return m_ID; }
	virtual bool HandleMessage(const Telegram& msg) = 0;
	string GetNameOfEntity() { return name; }
};