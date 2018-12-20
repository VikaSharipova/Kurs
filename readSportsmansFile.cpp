#include <libloaderapi.h>
#include "readSportsmansFile.h"

ReadSportsmansFile::~ReadSportsmansFile() {
	if (nullptr != newSportsmansList) {
		delete newSportsmansList;
		newSportsmansList = nullptr;
	}
}

MList<Sportsman> *ReadSportsmansFile::get_sportsmans(std::string name) {
	
	if (nullptr != newSportsmansList) {
		delete newSportsmansList;
		newSportsmansList = nullptr;
	}
	
	ifstream readFrom(name);
	newSportsmansList = new MList<Sportsman>;
	try {
		if (readFrom.is_open()) {
			for (int i = 0; i < PARTICIPANTS; ++i) {
				string name = "";
				string country = "";
				int strength;
				int agility;
				int luck;
				int stamina;
				strength = agility = luck = stamina = 0;
				
				readFrom >> name;
				readFrom >> country;
				readFrom >> strength;
				readFrom >> agility;
				readFrom >> luck;
				readFrom >> stamina;
				
				Node<Sportsman> *newNode = new Node<Sportsman>;
				newNode->value.set_entry(name, country, strength, agility, luck, stamina);
				newSportsmansList->push_back(newNode);
			}
		} else {
			throw FILE_MISSING;
		}
	}
	catch (const unsigned int &ex) {
		cout << ex << " - Файл отсутствует";
		exit(1);
	}
	
	readFrom.close();
	return newSportsmansList;
}
