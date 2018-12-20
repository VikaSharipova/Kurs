#include "olimpic.h"

MList<Discipline> *prepare_disciplines() {
	MList<Discipline> * disciplines = new MList<Discipline>;
	for (int i = 0; i < DISCIPLINES_NUM; i++) {
		Node<Discipline> * newNode = new Node<Discipline>;
		newNode->value.set_name(DISCIPLINES[i]);
		newNode->value.set_rules(DISCIPLINE_RULES[i]);
		disciplines->push_back(newNode);
	}
	return disciplines;
}

OlimpicGame::OlimpicGame(MList<Discipline> *disciplines, MList<Sportsman> *participants) {
	this->participants = participants;
	this->disciplines = disciplines;

	for (int i = 0; i < DISCIPLINES_NUM; i++) {
		(*this->disciplines)[i].attach(*this);
	}
}

void OlimpicGame::start() {
	system("CLS");
	this->initial_stage();
}

void OlimpicGame::set_stage(unsigned int stage) {

}

void OlimpicGame::initial_stage(){
	
	letTheGameBegin();
	
	this->state = 0;
	int choice = -1;
	
	cout << "Участники соревнований!" << endl;
	this->participants->show_list();

	cout << "Выберите страну, за которую желаете болеть, из следующего списка:" << endl;
	for (int i = 0; i < COUNTRIES_NUM; i++) {
		cout << i << " : " << COUNTRIES[i] << endl;
	}

	cout << endl;
	choice = input_int_with_retries_and_borders(MAX_INPUT_RETRIES, 0, 4);

	this->cheeredCountry = COUNTRIES[choice];
	system("CLS");
	this->default_stage();
}

void OlimpicGame::default_stage(){

	cout << "Страна, за которую вы болеете: " << this->cheeredCountry << endl;
	cout << endl << "Выберите вид спорта, который желаете посмотреть из следующего списка:" << endl;

	int choice = -1;
	int actualDisciplines = 0;
	bool hasActualDisciplines = false;
	MList<Discipline> localDisciplines;
	for (int i = 0; i < 4; i++) {
		string discipline = (*disciplines)[i].get_name();
//		string discipline = disciplines.get_name();
		if (!(this->playedDisciplines.find(discipline))) {
			cout << actualDisciplines << " : " << discipline << endl;
			actualDisciplines++;

			Node<Discipline> * newNode = new Node<Discipline>;
			newNode->value = (*disciplines)[i];
			localDisciplines.push_back(newNode);
			hasActualDisciplines = true;
		}
	}
	
	if (hasActualDisciplines) {
		cout << endl << "Введите: " << ALL_DISCIPLINES_FINALIZE_VALUES << ", чтобы вывести все результаты" << endl;
		cout << "Или покиньте игры, введя любое другое число" << endl;
	}
	else {
		system("CLS");
		this->final_stage();
	}

	choice = input_int_with_retries_and_borders(MAX_INPUT_RETRIES, 0, actualDisciplines);

	switch (choice) {
		case BIATLON_FINALIZE_VALUES:
		case SKELETON_FINALIZE_VALUES:
		case SKATIONG_FINALIZE_VALUES:
		case FIGURE_SKATING_FINALIZE_VALUES:
			victorOutput(choice);
			break;
		case ALL_DISCIPLINES_FINALIZE_VALUES:
			system("CLS");
			this->competition_stage(/*localDisciplines[choice].get_name()*/);
			break;
		case EXIT_FINALIZE_VALUES:
		default:
			system("CLS");
			this->final_stage();
	}
}

void OlimpicGame::competition_stage(){
	cout << "Текущие результаты: " << endl;

	for (int i = 0; i < COUNTRIES_NUM; i++) {
		cout << COUNTRIES[i] << endl;
		for (int j = 0; j < DISCIPLINES_NUM; j++) {
			cout << DISCIPLINES[j] << " : " << results[i][j] << endl;
		}
		cout << endl;
	}

	system("CLS");
	this->default_stage();

}

void OlimpicGame::victorOutput(int discipline) {
	
	unsigned short place = 1;
	
	for (size_t i = 0; i < COUNTRIES_NUM; ++i) {
		if((*participants)[i].get_country() == this->cheeredCountry) {
			
			const int favoriteResult = results[i][discipline];
			for (size_t  j = 0; j < COUNTRIES_NUM; ++j) {
				if ((favoriteResult < results[j][discipline] ) && (j != i)) {
					++place;
				}
			}
		}
	}
	
	cout << "Ваш фаворит <<" << this->cheeredCountry << ">> занял почётное "
		<< place << " место по дисциплине <<" <<  (*disciplines)[discipline].get_name() << ">>!" << endl;
	
	system("CLS");
	this->default_stage();
}

void OlimpicGame::final_stage(){}

void OlimpicGame::letTheGameBegin() {
	for (size_t i = 0; i < DISCIPLINES_NUM; ++i) {
		/*auto resultList = */(*disciplines)[i].compete(*participants);
//		calculateResult(resultList, i);
	}
}

void OlimpicGame::calculateResult(MList<int> &resultList, const string &nameOfDiscipline ) {
	
	for (size_t i = 0; i < COUNTRIES_NUM; ++i) {
		if((*disciplines)[i].get_name() == nameOfDiscipline) {
			
			for (size_t j = 0; j < COUNTRIES_NUM; ++j) {
				
				results[j][i] = resultList[j];
			}
		}
	}
}

void OlimpicGame::updateResult(MList<int> &value, const string &nameOfDiscipline ) {
	calculateResult(value, nameOfDiscipline);
}