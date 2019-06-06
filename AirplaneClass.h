#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class AirplaneClass {
private:
	const double FUEL_PRICE_PER_LITRE = 2.5;
	string maker;
	string model;
	int numberOfSeats;
	int minStripLen;
	double litresOfPetrolTank;
	double staffExpenses;
	double litresPerKm;
	double avgSpeed;
public:
	string getMaker() { return this->maker; }
	string getModel() { return this->model; }
	int getNumberOfSeats() { return this->numberOfSeats; }
	int getMinStripLen() { return this->minStripLen; }
	double getLitresOfPetrolTank() { return this->litresOfPetrolTank; }
	double getStaffExpenses() { return this->staffExpenses; }
	double getLitresPerKm() { return this->litresPerKm; }
	double getAvgSpeed() { return this->avgSpeed; }
	static AirplaneClass convertLineToAirplaneClass(string line);
	AirplaneClass();
	AirplaneClass(const char* maker, const char* model, int numberOfS, int minLSL, 
		double sExp, double litresPk, double avgS, double litresOfPetrolTank);
	AirplaneClass(const char* maker, const char* model, int numberOfS, int minLSL) : AirplaneClass(maker, model, numberOfS, minLSL,
		100, 20, 80, 500) {};
	void setAvgSpeed(double aS);
	void setLitresPerKm(double lpk);
	void setStaffExpenses(double sE);
	void setLitresOfPetrolTank(double litresOfPT);

	void setMinStripLen(int minLSL);
	void setNumberOfSeats(int numOfS);
	void setModel(string m);
	void setMaker(string m);
	double calculateExpensesForDistance(double distanceInKm);
	double getMaxDistance();
	bool areVariablesSet();
	AirplaneClass& operator=(const AirplaneClass& other);
	friend ostream& operator<<(ostream& os, AirplaneClass& aC);
};
