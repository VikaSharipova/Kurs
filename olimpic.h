#pragma once
#include <iostream>
#include "constants.h"
#include "sportsman.h"
#include "discipline.h"

using namespace std;

MList<Discipline> * prepare_disciplines();

class OlimpicGame : Observer {

public:

	OlimpicGame(MList<Discipline> * disciplines, MList<Sportsman> * participants);

	void start(); 
	void set_stage(unsigned int stage);

	void initial_stage();							// preparing game, sportsmans and such 
	void default_stage();							// here watcher chooses what to watch or to see final results
	void competition_stage(/*string competition*/);		// sportsmans compete with each oter
	void victorOutput(int discipline);
	void final_stage();								// results, winning
	
	void updateResult(MList<int> &value, const string &nameOfDiscipline) override;
	
private:
	MList<Sportsman> * participants;
	MList<Discipline> * disciplines;
	unsigned int state = 0; // usefull to debug current state of the game
	int results[5][4] = { 0 }; 
	string cheeredCountry = "";
	MList<string> playedDisciplines;
	
	void letTheGameBegin();
	void calculateResult(MList<int> &resultList, const string &nameOfDiscipline);
	
};