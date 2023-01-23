#pragma once
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

class BaseGameEntity {
private:
	int ID;
	static int nextValidID;
	void setID() {
		ID = nextValidID;
		nextValidID++;
	}
public:
	BaseGameEntity() { setID(); };
	~BaseGameEntity() = default;
	virtual void Update() = 0;
	int ID() const { return ID; }
};