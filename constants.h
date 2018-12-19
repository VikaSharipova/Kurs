#pragma once
#include <string>
using namespace std;

const string SPORTSMANS_FILE = "sportsmans.txt";
const string RESULTS_FILE = "results.txt";
const string COUNTRIES[5] = {
	"Russia",
	"Canada",
	"France",
	"Finland",
	"Japan",
};

const string DISCIPLINES[4] = {
	"Biatlon",
	"Skeleton",
	"Skating",
	"Figure skating",
};

const int DISCIPLINE_RULES[4][4] = { //strength, agility, luck, stamina
	{ -3, 4, 8, 6 }, // biatlon
	{ 3, -5, 0, 4 }, // skeleton
	{ 5, 3, 2, 8 }, // skating
	{ 1, 8, -2, 6 }, // figure skating
};

const int PARTICIPANTS = 5;
const int MAX_INPUT_RETRIES = 2;

const int LOWEST_SPORTSMAN_PARAMETER = 0;
const int MAX_SPORTSMAN_PARAMETER = 10;