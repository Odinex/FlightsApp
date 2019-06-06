#pragma once
#include "Airport.h"
#include <iostream>
using namespace std;

class Flight
{
private:
	Airport fromDestination;
	Airport toDestination;
	double distance;
	int passengersNumber;
public:
	Flight();
	Flight(Airport from, Airport to, double distance);
	Flight(Airport from, Airport to, double distance, int numberOfP);
	Airport getFromDestination() { return this->fromDestination; }
	Airport getToDestination() { return this->toDestination; }
	double getDistance() { return this->distance; }
	void setFrom(Airport from);
	void setTo(Airport to);
	void setDistance(double d);
	int getPassengersCount() { return this->passengersNumber; }
	void setPassengerNumber(int p);
	friend ostream& operator<<(ostream& os, Flight& f);
	~Flight();
};

