
// FlightsApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
Създайте приложение, което да поддържа информация за самолетите, полетите, като с наличните данни трябва да се помогне компанията
при определяне на назначенията на самолети по определени авиолинии и да се постигне по-ефективно използване на ресурсите.
Базисните данни за самолетите включват идентификационен номер и клас.
Класът на самолета включва производителя, модела, броя места и минималната дължина на пистата за кацане/излитане.
Класът на самолета определя съвместимостта му с дадена дестинация. С цел оценка ефективността на използването на
самолета за определен маршрут трябва да се съхраняват данни за необходимите разходи за самолета.
Такива са разходите за необходимия персонал, разход на гориво за 1 километър на едно място.
За оценка на максималната далечина на полета са необходими данни за обем на резервоара в литри.
За оценка продължителността на полетите и за натовареността на пилотите трябва да се съхраняват данни за средната скорост на самолетите от класа.

Приложението да има възможност за въвеждане на произволен брой различни самолети от различен клас (10 точки).

Да има възможност за търсене на самолети,
които могат да извършват полет до определена дестинация (10 точки).

Класовете (най-малко 3 класа при реализацията) трябва да капсулира всичките детайли.
Използват се private инстанции на променливите за съхраняване на различните детайли.
Трябва да има най-малко два конструктора, public getters/setters за private инстанции на променливите(30 точки).

Необходимо е да извършвате проверка на входните данни, където е необходимо(10 точки).
Да се предефинира операцията <<, която да се използва за извеждане на данните (10 точки).
Данните да се четат и съхраняват във файл (20 точки).

Класовете да се опишат с UML клас диаграма (10 точки).
*/

#include "stdafx.h"
#include "AirplaneClass.h"
#include "Airplane.h"
#include "Flight.h"
#include <iostream>
#include <exception>
#include <vector>
#include <string>
#include <string.h>
#include <fstream>
#include <sstream>

#define MAX_SIZE 200 
using namespace std;

void addSomeAirplaneClasses() {
	vector<AirplaneClass> classes;
	classes.reserve(4);
	for (int i = 0; i < 4; i++) {
		int numberOfSeats = 60 - i * 10;
		int minLeng = 200 - i * 30;
		int staffExpenses = 200 + i * 40;
		int litresPerkm = 24 - i * 6;
		classes.push_back(AirplaneClass(to_string(i+1).c_str(),to_string(1+i).c_str() ,numberOfSeats, minLeng, staffExpenses ,litresPerkm,100, 20000));
	}
	ofstream out("classes.txt");
	if (out.is_open()) {
		for (int i = 0;i < 4;i++) {
			cout << classes[i];
			out << classes[i];
		}
	}
	out.close();
}
vector<AirplaneClass> getAirplaneClassesData() {
	vector<AirplaneClass> classes;
	classes.reserve(9);
	ifstream in("classes.txt");
	string line;
	if (in.is_open()) {
		while (getline(in, line)) {
			AirplaneClass a = AirplaneClass::convertLineToAirplaneClass(line);
			classes.push_back(a);
		}
	}
	in.close();
	cout << "Брой на примерните класове: " << classes.size() << endl;
	return classes;
}
vector<Airplane> makeAirplanes(vector<AirplaneClass> classes) {
	vector<Airplane> airplanes;
	if (classes.size() > 0) {
		airplanes.reserve(classes.size() * 3 + 1);
		for (unsigned int i = 0; i < classes.size(); i++) {
			airplanes.push_back(Airplane(classes[i]));
			airplanes.push_back(Airplane(classes[i]));
			airplanes.push_back(Airplane(classes[i]));
		}
	}
	return airplanes;
}

vector<Flight> initFlights() {
	
	vector<Flight> flights;
	flights.reserve(3);
	Airport sofia("sofia", 200);
	Airport varna("varna", 150);
	Airport atina("atina", 250);
	flights.push_back(Flight(sofia, varna, 600,30));
	flights.push_back(Flight(sofia, atina, 700,50));
	flights.push_back(Flight(varna, atina, 1000,60));
	return flights;
}
AirplaneClass createAirplaneClass() {
	char maker[MAX_SIZE] = "";
	char model[MAX_SIZE] = "";
	int numberOfSeats;
	int minStripLen;
	double litresOfPetrolTank;
	double staffExpenses;
	double litresPerKm;
	double avgSpeed;

	cout << "Въведи производител(максимум 200 знака): " << endl;
	cin >> maker;
	int len = strlen(maker) + 1;
	maker[len] = '\0';
	cout << "Въведи модел(максимум 200 знака): " << endl;
	cin >> model;
	len = strlen(model) + 1;
	model[len] = '\0';
	cout << "Въведи брой на местата" << endl;
	cin >> numberOfSeats;
	cout << "Въведи минимална дължина на писта за кацане/излитане" << endl;
	cin >> minStripLen;
	cout << "Въведи литри на резервоара" << endl;
	cin >> litresOfPetrolTank;
	cout << "Въведи разходи за персонала" << endl;
	cin >> staffExpenses;
	cout << "Въведи литри разход на километър" << endl;
	cin >> litresPerKm;
	cout << "Въведи средна скорост" << endl;
	cin >> avgSpeed;
	AirplaneClass a(maker, model, numberOfSeats, minStripLen, staffExpenses, litresPerKm, avgSpeed, litresOfPetrolTank);
	return a;
}
void addClasses() {
	vector<AirplaneClass> classes;
	cout << "Колко класа ще бъдат добавени(минимум: 3, максимум: 30)" << endl;
	int numberOfClasses = 0;
	cin >> numberOfClasses;
	if (numberOfClasses < 3) numberOfClasses = 3;
	if (numberOfClasses > 30) numberOfClasses = 30;
	classes.reserve(numberOfClasses);

	for (int i = 0; i < numberOfClasses; i++) {		
		classes.push_back(createAirplaneClass());
	}
	ofstream out("classes.txt");
	if (out.is_open()) {
		for (int i = 0;i < numberOfClasses;i++) {
			out << classes[i];
		}
	}
	out.close();
}
Airplane getTheMostSuitableAirplaneForCertainFlight(vector<Airplane> airplanes, Flight flight) {
	double distance = flight.getDistance();
	int passengersCount = flight.getPassengersCount();
	const int size = airplanes.size();
	Airplane result;
	if (airplanes.empty() == false) {
		for (int i = airplanes.size() - 1; i >= 0; i--) {
			if (airplanes.at(i).getAirplaneClass().getMaxDistance() < distance
				|| airplanes.at(i).getAirplaneClass().getNumberOfSeats()
				< passengersCount) {
				airplanes.erase(airplanes.begin() + i);
			}
		}
	}


	result = airplanes[0];
	double cost = result.getAirplaneClass().calculateExpensesForDistance(distance);
	for (int i = 1; i < airplanes.size(); i++) {
		if (cost > airplanes[i].getAirplaneClass().calculateExpensesForDistance(distance)) {
			result = airplanes[i];
		}
	}
	return result;
}

bool checkNumberOfPassengers(int numberOfPassengers) {
	if (numberOfPassengers > 0 && numberOfPassengers < 1000) {
		return true;
	}
	return false;
}
int main()
{
	setlocale(LC_CTYPE, "bg");
	try {

		vector<AirplaneClass> classes;
		vector<Airplane> airplanes;
		vector<Flight> flights = initFlights();
		cout << " Програма за оптимизиране на полети" << endl;
	    /*
		cout << endl<< " Въведи буква, за да продължим. "<<endl;
		cout << " 'a' : Използвай примерни данни за самолети и самолетни класове" << endl;
		cout << " 'b' : Въведи свои данни за самолетните класове" << endl;
		cout << " 'c' : Покажи полетите" << endl;
		cout << " 'd' : Избери полет и брой пътници, за да се изведе най-подходящия самолет" << endl;
		cout << " 'e' : Покажи класовете на самолетите и броя на самолетите" << endl;
		cout << " 'q' : Приключи" << endl;
		
		*/

		int menuChoice = 1;
		int flightChoice = -1;
		int numberOfPassengers = -1;
		char choice = 'n';
		Airplane bestAirplane;
		while (choice != 'q') {

			if (menuChoice == 1) {
				cout << endl << " Въведи буква, за да продължим. " << endl;
				cout << " 'a' : Използвай примерни данни за самолети и самолетни класове" << endl;
				cout << " 'b' : Въведи свои данни за самолетните класове" << endl;
				cout << " 'c' : Покажи класовете" << endl;
				cout << " 'd' : Продължи към следващото меню" << endl;
				//cout << " 'r' : Върни се в предишното меню" << endl;
				cout << " 'q' : Приключи" << endl;
				cin >> choice;
				switch (choice) {
				case 'a':
					addSomeAirplaneClasses();
					break;
				case 'b':
					addClasses();
					break;
				case 'c':
					classes = getAirplaneClassesData();
					if (classes.size() > 0) {
						for (int i = 0; i < classes.size(); i++) {
							cout << classes[i] << endl;
						}
					}
					else {
						cout << "Няма създадени класове на самолети" << endl;
					}

					break;
				case 'd':
					airplanes = makeAirplanes(getAirplaneClassesData());
					menuChoice++;
					break;
				//case 'r': menuChoice--;cout << menuChoice;break;
				case 'q': return 0;
				}
			}
			else if (menuChoice == 2) {
				for (int i = 0; i < flights.size(); i++) {
					cout << i + 1 <<" "<< flights[i] << endl;
				}
				cout << endl << " Избери полет: " << endl;
				cout << " 'a' : за полет 1" << endl;
				cout << " 'b' : за полет 2" << endl;
				cout << " 'c' : за полет 3" << endl;
				cout << " 'r' : Върни се в предишното меню" << endl;
				cout << " 'q' : Приключи" << endl;

				cin >> choice;
				switch (choice) {
				case 'a':
					flightChoice = 0;
					menuChoice++;
					break;
				case 'b':
					flightChoice = 1;
					menuChoice++;
					break;
				case 'c':
					flightChoice = 2;
					menuChoice++;
					break;
				case 'r': menuChoice--;break;
				case 'q': return 0;
				}
			}
			else if (menuChoice == 3) {
				cout << " 'a' : Въведи брой пътници" << endl;
				cout << " 'r' : Върни се в предишното меню" << endl;
				cout << " 'h' : Започни отначало" << endl;
				cout << " 'q' : Приключи" << endl;
				cin >> choice;
				switch (choice) {
				case 'a':
					cout << " Въведи брой пътници: " << endl;
					cin >> numberOfPassengers;
					flights[flightChoice].setPassengerNumber(numberOfPassengers);
					menuChoice++;
					break;
				case 'r':
					menuChoice--;
					break;
				case 'h':
					menuChoice = 1;
				case 'q': return 0;
				}
			}
			else if (menuChoice == 4) {
				cout << " 'a' : Покажи най-подходящия самолет" << endl;
				cout << " 'h' : Върни се в началното меню" << endl;
				cout << " 'r' : Върни се в предишното меню" << endl;
				cout << " 'q' : Приключи" << endl;
				cin >> choice;
				switch (choice) {
				case 'a':
					bestAirplane = getTheMostSuitableAirplaneForCertainFlight(airplanes, flights[flightChoice]);
					cout << bestAirplane << endl;
					break;
				case 'h':
					menuChoice = 1; break;
				case 'r':
					menuChoice--;
					break;
				case 'q': return 0;
				}
			}
			else {
				return 0;
			
			}
		}
	}
	catch (exception e) {
		cerr << e.what();
	}
}
