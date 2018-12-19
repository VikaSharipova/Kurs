#pragma once
#include <iostream>
#include "constants.h"
#include "utilities.h"
#include "sportsman.h"
#include "discipline.h"

using namespace std;

MList<Discipline> * prepare_disciplines();

class OlimpicGame {
public:
	OlimpicGame(MList<Sportsman> * participants, MList<Discipline> * disciplines);

	void start();

	void initial_stage();							
	void default_stage();							
	void competition_stage(string competition);	
	void final_stage();						

private:
	MList<Sportsman> * participants;
	MList<Discipline> * disciplines;
	unsigned int state = 0; 
	int results[5][4] = { 0 }; 
	string cheeredCountry = ""; 
	MList<string> playedDisciplines;
};