#pragma once
#include "AirplaneClass.h"

class Airplane {
private:
	static int idSequence;
	int id;
	AirplaneClass airplaneClass;
public:
	int getId();
	void setId(int id);
	AirplaneClass getAirplaneClass();
	void setAirplaneclass(AirplaneClass aC);
	Airplane();
	Airplane(AirplaneClass aC);
	friend ostream& operator<<(ostream& os, Airplane& a);
	Airplane& operator=(const Airplane& other);
};
