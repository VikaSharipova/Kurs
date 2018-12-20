#pragma once

#include <string>

using namespace std;

const string SPORTSMANS_FILE = "sportsmans.txt";

const unsigned short COUNTRIES_NUM = 5;

const string COUNTRIES[COUNTRIES_NUM] = {
	"Canada",
	"Japan",
	"Russia",
	"France",
	"Finland",
};

const unsigned short DISCIPLINES_NUM = 4;

enum CONSOLE_FINALIZE_VALUES {
	BIATLON_FINALIZE_VALUES = 0,
	SKELETON_FINALIZE_VALUES = 1,
	SKATIONG_FINALIZE_VALUES = 2,
	FIGURE_SKATING_FINALIZE_VALUES = 3,
	ALL_DISCIPLINES_FINALIZE_VALUES = 4,
	EXIT_FINALIZE_VALUES = 5
};

const string DISCIPLINES[DISCIPLINES_NUM] = {
	"Biatlon",
	"Skeleton",
	"Skating",
	"Figure skating",
};

const int DISCIPLINE_RULES[4][4] = { 
	{-3, 4, 8, 6}, // biatlon
	{3, -5, 0, 4}, // skeleton
	{5, 3, 2, 8}, // skating
	{1, 8, -2, 6}, // figure skating
};

const int PARTICIPANTS = 5;
const int MAX_INPUT_RETRIES = 2;

const int LOWEST_SPORTSMAN_PARAMETER = 0;
const int MAX_SPORTSMAN_PARAMETER = 10;