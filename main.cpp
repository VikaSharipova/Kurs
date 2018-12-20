#include <iostream>
#include <fstream>
#include <string>

#include "utilities.h"
#include "constants.h"
#include "sportsman.h"
#include "discipline.h"
#include "olimpic.h"
#include "readSportsmansFile.h"

using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");

	cout << "Неужели ты работаешь" << endl;	//	Работой это не назвать =\

	system("CLS");
	
	ReadSportsmansFile readFile;
	MList<Sportsman> *participants = readFile.get_sportsmans(SPORTSMANS_FILE);
	
	MList<Discipline> * disciplines = prepare_disciplines();
	OlimpicGame newGame(disciplines, participants);
	
	newGame.start();

	input_int_with_retries(MAX_INPUT_RETRIES);
	return 0;
}