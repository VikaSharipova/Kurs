#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "constants.h"
#include "utilities.h"

using namespace std;

class Sportsman {
public:
	Sportsman(string name,
		string country,
		int strength,
		int agility,
		int luck,
		int stamina);			

	Sportsman();							
	Sportsman(const Sportsman& copyFrom);
	Sportsman& operator= (Sportsman other);	

	string get_name();
	string get_country();
	int get_strength();
	int get_agility();
	int get_luck();
	int get_stamina();

	void set_entry(string name,
		string country,
		int strength,
		int agility,
		int luck,
		int stamina);

	friend ostream& operator <<(std::ostream& stream, const Sportsman& sportsman);

private:
	string name = "";
	string country = "";
	int strength = 0;
	int agility = 0;
	int luck = 0;
	int stamina = 0;
};