#pragma once

#include "utilities.h"
#include "sportsman.h"

class ReadSportsmansFile {
	public:
		~ReadSportsmansFile();
		MList<Sportsman> *get_sportsmans(std::string name);
		
	private:
		const unsigned int FILE_MISSING = 404;

		MList<Sportsman> *newSportsmansList = nullptr;
};