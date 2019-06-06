#include "stdafx.h"
#include "Airplane.h"


ostream& operator<<(ostream& os, Airplane& a)
{
	os << "Airplane-ID: " << a.getId() << " ";
	AirplaneClass ac = a.getAirplaneClass();
		os << ac;
	return os;
}

int Airplane::getId() {
	return this->id;
}
void Airplane::setId(int id) {
	this->id = id;
}
AirplaneClass Airplane::getAirplaneClass() {
	return this->airplaneClass;
}

void Airplane::setAirplaneclass(AirplaneClass aC) {
	if (&aC == NULL)
	{
		throw exception("AirplaneClass is not initialized");
	}
	else
	{
		if (aC.areVariablesSet() == false) {
			throw exception("AirplaneClass's variables are not completely set");
		}
		this->airplaneClass = aC;
	}
}

Airplane::Airplane()
{
	this->id = idSequence++;
}

Airplane::Airplane(AirplaneClass aC) {
	this->id = idSequence++;
	this->setAirplaneclass(aC);
}

Airplane& Airplane::operator=(const Airplane& other) {
	if (this != &other) {
		id = other.id;
		airplaneClass = other.airplaneClass;
		return *this;
	}
	return *this;
}

int Airplane::idSequence = 1;
