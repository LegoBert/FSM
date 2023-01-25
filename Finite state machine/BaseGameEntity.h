#pragma once
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

class BaseGameEntity {
private:
	int m_ID;
	static int nextValidID;
	void setID() {
		m_ID = nextValidID;
		nextValidID++;
	}
public:
	BaseGameEntity() { setID(); };
	~BaseGameEntity() = default;
	virtual void Update() = 0;
	int ID() { return m_ID; }
};