#include <iostream>
#include <fstream>
#include <string>
#include "utilities.h"
#include "constants.h"
#include "sportsman.h"
#include "discipline.h"
#include "olimpic.h"

using namespace std;

MList<Sportsman> * get_sportsmans() {
	ifstream readFrom;
	readFrom.open(SPORTSMANS_FILE);

	MList<Sportsman> * newSportsmansList = new MList<Sportsman>;

	string name;
	string country;
	int strength;
	int agility;
	int luck;
	int stamina;
	for (int i = 0; i < PARTICIPANTS; i++) {
		readFrom >> name;
		readFrom >> country;
		readFrom >> strength;
		readFrom >> agility;
		readFrom >> luck;
		readFrom >> stamina;
		Node<Sportsman> * newNode = new Node<Sportsman>;
		newNode->value.set_entry(name, country, strength, agility, luck, stamina);
		newSportsmansList->push_back(newNode);
	}

	readFrom.close();
	return newSportsmansList;
}

int main() {
	setlocale(LC_ALL, "Russian");

	MList<Sportsman> * participants = get_sportsmans();
	MList<Discipline> * disciplines = prepare_disciplines();
	OlimpicGame newGame(participants, disciplines);

	newGame.start();

	input_int_with_retries(MAX_INPUT_RETRIES);
	return 0;
}