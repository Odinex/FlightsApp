#include "stdafx.h"
#include "AirplaneClass.h"

AirplaneClass AirplaneClass::convertLineToAirplaneClass(string line) {
	vector<string> words;
	string::size_type i = 0;
	string::size_type j = line.find(' ');
	while (j != string::npos) {
		string word = line.substr(i, (j - i));
		words.push_back(line.substr(i, j - i));
		i = ++j;
		j = line.find(' ', j);

		if (j == string::npos) {
			string word = line.substr(i, line.length());
			words.push_back(word);
		}
	}
	AirplaneClass a(words[1].c_str(), words[3].c_str(),
		stoi(words[5]), stoi(words[7]),	stod(words[11]),
		stod(words[13]), stod(words[15]), stod(words[9]));
	return a;
}

// assume the object holds reusable storage, such as a heap-allocated buffer mArray
AirplaneClass& AirplaneClass::operator=(const AirplaneClass& other) // copy assignment
{
	if (this != &other) { 
		model = other.model;
		maker = other.maker;
		avgSpeed = other.avgSpeed;
		litresOfPetrolTank = other.litresOfPetrolTank;
		litresPerKm = other.litresPerKm;
		minStripLen = other.minStripLen;
		numberOfSeats = other.numberOfSeats;
		staffExpenses = other.staffExpenses;

		return *this;
	}
	return *this;
}
ostream& operator<<(ostream& os, AirplaneClass& aC) {
	string maker = aC.getMaker();
	os << "Производител: " << maker << " Модел: " << aC.getModel() << " Брой_места: " << aC.getNumberOfSeats() <<
		" Минимална_дължина_на_писта: " << aC.getMinStripLen() << " Литри_на_резервоара: " << aC.getLitresOfPetrolTank() <<
		" Разход_за_персонал: " << aC.getStaffExpenses() << " Литри_на_километър: " << aC.getLitresPerKm() << " Средна_скорост: " << aC.getAvgSpeed() << endl;
	return os;
}
AirplaneClass::AirplaneClass() {
}
AirplaneClass::AirplaneClass(const char* maker, const char* model,
	int numberOfS, int minLSL, double sExp,
	double litresPk, double avgS, double litresOfPetrolTank) {
	setAvgSpeed(avgS); setLitresOfPetrolTank(litresOfPetrolTank); setLitresPerKm(litresPk); setMaker(maker);
	setModel(model); setMinStripLen(minLSL); setStaffExpenses(sExp);setNumberOfSeats(numberOfS);
}
bool AirplaneClass::areVariablesSet() {
	if (!this->maker.empty() && this->avgSpeed != 0 && this->litresOfPetrolTank != 0 && this->litresPerKm != 0 && this->minStripLen != 0 &&
		!this->model.empty() && this->numberOfSeats != 0 && this->staffExpenses != 0) {
		return true;
	}
	else {
		return false;
	}
}
void AirplaneClass::setAvgSpeed(double aS) {
	if (aS > 0) {
		this->avgSpeed = aS;
	}
	else {
		throw exception("Invalid Average Speed");
	}
}
void AirplaneClass::setLitresPerKm(double lpk) {
	if (lpk > 0) {
		this->litresPerKm = lpk;
	}
	else {
		throw exception("Invalid Litres Per KM");
	}
}
void AirplaneClass::setStaffExpenses(double sE) {
	if (sE > 0) {
		this->staffExpenses = sE;
	}
	else {
		throw exception("Invalid Staff Expenses");
	}
}
void AirplaneClass::setLitresOfPetrolTank(double litresOfPT) {
	if (litresOfPT > 0) {
		this->litresOfPetrolTank = litresOfPT;
	}
	else {
		throw exception("Invalid Litres Of Petrol Tank");
	}
}
void AirplaneClass::setMinStripLen(int minLSL) {
	if (minLSL > 0) {
		this->minStripLen = minLSL;
	}
	else {
		throw exception("Invalid Min Landing Strip Length");
	}
	this->minStripLen = minLSL;
}
void AirplaneClass::setNumberOfSeats(int numOfS) {
	if (numOfS > 0) {
		this->numberOfSeats = numOfS;
	}
	else {
		throw exception("Invalid Number Of Seats");
	}
}
void AirplaneClass::setModel(string m) {
	if (!m.empty()) {
		this->model = m;
	}
	else {
		throw exception("Invalid Model");
	}
	this->model = m;
}
void AirplaneClass::setMaker(string m) {
	if (!m.empty()) {
		this->maker = m;
	}
	else {
		throw exception("Invalid Maker");
	}
}

double AirplaneClass::calculateExpensesForDistance(double distanceInKm) {
	double res = distanceInKm * this->getLitresPerKm()*FUEL_PRICE_PER_LITRE + this->getStaffExpenses();
	return res;
}
double AirplaneClass::getMaxDistance() {
	double maxDistance = this->getLitresOfPetrolTank() / this->getLitresPerKm();
	return maxDistance;
}

