#include "olimpic.h"

MList<Discipline> * prepare_disciplines() {
	MList<Discipline> * disciplines = new MList<Discipline>;
	for (int i = 0; i < 4; i++) {
		Node<Discipline> * newNode = new Node<Discipline>;
		newNode->value.set_name(DISCIPLINES[i]);
		newNode->value.set_rules(DISCIPLINE_RULES[i]);
		disciplines->push_back(newNode);
	}
	return disciplines;
}

OlimpicGame::OlimpicGame(MList<Sportsman> * participants, MList<Discipline> * disciplines) {
	this->participants = participants;
	this->disciplines = disciplines;
}

void OlimpicGame::start() {
	system("CLS");
	this->initial_stage();
}

void OlimpicGame::initial_stage() {

	this->state = 0;
	int choice = -1;

	cout << "��������� ������������!" << endl;
	this->participants->show_list();

	cout << "�������� ������, �� ������� ������� ������, �� ���������� ������:" << endl;
	for (int i = 0; i < 5; i++) {
		cout << i << " : " << COUNTRIES[i] << endl;
	}

	cout << endl;
	choice = input_int_with_retries_and_borders(MAX_INPUT_RETRIES, 0, 4);

	this->cheeredCountry = COUNTRIES[choice];
	system("CLS");
	this->default_stage();
}

void OlimpicGame::default_stage() {

	this->state = 1;

	cout << "������, �� ������� �� �������: " << this->cheeredCountry << endl;
	cout << endl << "�������� ��� ������, ������� ������� ���������� �� ���������� ������:" << endl;

	int choice = -1;
	int actualDisciplines = 0;
	bool hasActualDisciplines = false;
	MList<Discipline> localDisciplines;
	for (int i = 0; i < 4; i++) {
		string discipline = (*disciplines)[i].get_name();
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
		cout << endl << "��� �������� ����, ����� ������ ������� ����������, ������ �����: " << actualDisciplines << endl;
	}
	else {
		system("CLS");
		this->final_stage();
	}

	choice = input_int_with_retries_and_borders(MAX_INPUT_RETRIES, 0, actualDisciplines);

	if (choice == actualDisciplines) {
		system("CLS");
		this->final_stage();
	}
	else {
		system("CLS");
		this->competition_stage(localDisciplines[choice].get_name());
	}
}

void OlimpicGame::competition_stage(string competition) {
	this->state = 2;

	int competitionID = -1;
	for (int i = 0; i < 4; i++) {
		if (DISCIPLINES[i] == competition) {
			competitionID = i;
			break;
		}
	}

	cout << "������� ����������: " << endl;

	for (int i = 0; i < 5; i++) {
		cout << COUNTRIES[i] << endl;
		for (int j = 0; j < 4; j++) {
			cout << DISCIPLINES[j] << " : " << results[i][j] << endl;
		}
		cout << endl;
	}

	cout << "������? (y/n)" << endl;

	char c = 'n';
	try {
		cin >> c;
	}
	catch (int e) {
		cout << "� ��������� ��� ������� ������������ �����!" << endl;
		exit(1);
	}

	switch (c) {
	case 'y': {
		break;
	}
	case 'n': {
		system("CLS");
		this->default_stage();
	}
	default: {
		cout << "� ��������� ��� ������� ������������ �����!" << endl;
		exit(1);
	}
	}

	MList<int> results;
	Sportsman winner;
	for (int i = 0; i < 4; i++) {
		Discipline discipline = (*disciplines)[i];
		if (discipline.get_name() == competition) {
			results = discipline.compete((*participants));
			winner = discipline.get_winner();
		}
	}

	ofstream writeTo;
	writeTo.open(RESULTS_FILE, ios::app);

	writeTo << competition << endl;
	for (int i = 0; i < 5; i++) {
		writeTo << COUNTRIES[i] << " : " << results[i] << endl;
	}
	writeTo << endl;

	writeTo.close();

	cout << "���������� ������������:" << endl;
	for (int i = 0; i < participants->get_length(); i++) {
		cout << (*participants)[i] << " - " << results[i] << endl;
	}
	cout << "����������: " << winner << " !" << endl;

	//summarize results of all sportsmans for some country
	for (int i = 0; i < 5; i++) {
		string country = COUNTRIES[i];
		for (int j = 0; j < participants->get_length(); j++) {
			if ((*participants)[j].get_country() == country) {
				this->results[i][competitionID] += results[j];
			}
		}
	}

	this->playedDisciplines.push_back(competition);

	cout << "����������? (y/n)" << endl;

	char c2 = 'n';
	try {
		cin >> c2;
	}
	catch (int e) {
		cout << "� ��������� ��� ������� ������������ �����!" << endl;
		exit(1);
	}

	switch (c2) {
	case 'y': {
		system("CLS");
		this->default_stage();
	}
	case 'n': {
		system("CLS");
		this->final_stage();
	}
	default: {
		cout << "� ��������� ��� ������� ������������ �����!" << endl;
		exit(1);
	}
	}
}

void OlimpicGame::final_stage() {
	this->state = 3;

	cout << "��������� ����������:" << endl;
	for (int i = 0; i < 5; i++) {
		cout << COUNTRIES[i] << endl;
		for (int j = 0; j < 4; j++) {
			cout << DISCIPLINES[j] << " : " << results[i][j] << endl;
		}
		cout << endl;
	}

	cout << "������������� ���������� �� ���� ����� ������:" << endl;
	int summarizedResult[5] = { 0 };
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			summarizedResult[i] += results[i][j];
		}
		cout << COUNTRIES[i] << " : " << summarizedResult[i] << endl;
	}

	int winnerCountryID = -1;
	int localMaximum = 0;
	for (int i = 0; i < 5; i++) {
		if (summarizedResult[i] > localMaximum) {
			localMaximum = summarizedResult[i];
			winnerCountryID = i;
		}
	}

	if (cheeredCountry == COUNTRIES[winnerCountryID]) {
		cout << "�����������! ��� ������� �� ����� ���!" << endl;
	}
	else {
		cout << "���, �� � ���� ��� �������� " << COUNTRIES[winnerCountryID] << endl << "������ � ��������� ���!" << endl;
	}

	cout << "������� ���-������ �� ��������!" << endl;
	string something = input_string_with_retries(MAX_INPUT_RETRIES);
	exit(0);
}