#include "stdafx.h"
#include "Flight.h"


Flight::Flight()
{
}
Flight::Flight(Airport from, Airport to, double distance) {
	setFrom(from); setTo(to); setDistance(distance);
}

Flight::Flight(Airport from, Airport to, double distance, int numberOfP)
{
	setFrom(from); setTo(to); setDistance(distance);
	setPassengerNumber(numberOfP);
}
void Flight::setFrom(Airport f) {
	if (&f != NULL) {
		this->fromDestination = f;
	}
}

void Flight::setTo(Airport t) {
	if (&t != NULL) {
		this->toDestination = t;
	}
}
void Flight::setDistance(double d) {
	if (d > 0) {
		this->distance = d;
	}
}
void Flight::setPassengerNumber(int p) {
	if (p > 0) {
		this->passengersNumber = p;
	}
}
ostream& operator<<(ostream& os, Flight& f)
{
	os << "�����_��: "<< f.fromDestination.getName() <<" ��: "<<f.toDestination.getName()<<" ���������: "<<f.distance<<" ����_�������: "<<f.passengersNumber;
		return os;
}
Flight::~Flight()
{
}
