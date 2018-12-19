#pragma once
#include <iostream>
#include "sportsman.h"
#include "constants.h"
#include "utilities.h"

using namespace std;

class Discipline {
public:
	Discipline(string name,
		int str,
		int agi,
		int luc,
		int sta);

	Discipline();
	Discipline(const Discipline& copyFrom);	
	Discipline& operator= (Discipline other);

	void set_rules(int str,
		int agi,
		int luc,
		int sta);

	void set_rules(const int* rules);

	void set_name(string name);
	string get_name();
	Sportsman get_winner();

	MList<int> compete(MList<Sportsman> sportsmans);
	MList<int> get_results();

private:
	string name = "";
	Sportsman winner;
	int strengthModifier = 0;
	int agilityModifier = 0;
	int luckModifier = 0;
	int staminaModifier = 0;
	MList<int> lastResults;
};