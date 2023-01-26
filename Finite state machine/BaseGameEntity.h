#pragma once
#include <cmath>
#include <vector>
#include <iostream>
#include "Telegram.h"
using namespace std;

class BaseGameEntity {
private:
	int m_ID;
	void setID(int id) {
		m_ID = id;
		nextValidID++;
	}
public:
	BaseGameEntity() = default;
	BaseGameEntity(int id) {
		setID(id);
	}
	~BaseGameEntity() = default;
	virtual void Update() = 0;
	int ID() { return m_ID; }
	virtual bool HandleMessage(const Telegram& msg) = 0;
};