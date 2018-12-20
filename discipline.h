#pragma once
#include <iostream>
#include "sportsman.h"
#include "constants.h"
#include "utilities.h"
#include "observer.hpp"

using namespace std;

class Discipline {
	public:	
		Discipline( string name,
					int str,
					int agi,
					int luc,
					int sta);
		Discipline();
		
		void set_rules(	int str,
						int agi,
						int luc,
						int sta);
		
		void set_rules(const int* rules);
		
		void set_name(string name);
		string get_name();
		Sportsman get_victor();
		
		void compete(MList<Sportsman>& sportsmans);
		MList<int> get_results();
		
		void attach(Observer &obs);
		
	private:
		string name = "";
		Sportsman victor;
		int strengthModifier = 0;
		int agilityModifier = 0;
		int luckModifier = 0;
		int staminaModifier = 0;
		MList<int> lastResults;
		Observer *observerList;
};