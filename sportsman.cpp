#include "sportsman.h"

void create_sportsman() {
	ofstream writeToFile;
	writeToFile.open(SPORTSMANS_FILE, ios::app);

	int retries = 0;

	string name;
	string country;
	int strength = 0;
	int agility = 0;
	int luck = 0;
	int stamina = 0;

	cout << "�������� �������� ����������. ������� ���, ������ �������������� � ������ ���������." << endl;
	cout << "���: ";
	name = input_string_with_retries(MAX_INPUT_RETRIES);
	cout << endl;

	cout << "������ ����� ��������: " << endl;
	for (int i = 0; i < 5; i++) {
		cout << COUNTRIES[i] << endl;
	}
	cout << "������� ������ ��������������" << endl;
	bool countryInTheList = false;
	while (retries <= MAX_INPUT_RETRIES)
	{
		country = input_string_with_retries(MAX_INPUT_RETRIES);
		for (int i = 0; i < 5; i++) {
			if (country == COUNTRIES[i]) {
				countryInTheList = true;
			}
		}

		if (countryInTheList) {
			break;
		}
		else {
			countryInTheList = false;
			cout << "�������� ������ ��� � ������ ����� ��������. ���������� �����. ���������� �������: " << MAX_INPUT_RETRIES - retries - 1 << endl;
			retries++;
		}

		if (retries == MAX_INPUT_RETRIES) {
			cout << "�������� ������ ��� � ������ ����� ��������. ������� ���������. ���������� ���������." << endl;
			exit(1);
		}

	}
	retries = 0;

	cout << "������� ��������� ����������:" << endl;
	cout << "������ �������: " << LOWEST_SPORTSMAN_PARAMETER << endl << "������ �������: " << MAX_SPORTSMAN_PARAMETER << endl;

	cout << "����: ";
	strength = input_int_with_retries(MAX_INPUT_RETRIES);
	check_sportsmans_parameter(strength);

	cout << "��������: ";
	agility = input_int_with_retries(MAX_INPUT_RETRIES);
	check_sportsmans_parameter(agility);

	cout << "�����: ";
	luck = input_int_with_retries(MAX_INPUT_RETRIES);
	check_sportsmans_parameter(luck);

	cout << "������������: ";
	stamina = input_int_with_retries(MAX_INPUT_RETRIES);
	check_sportsmans_parameter(stamina);

	writeToFile << name << " " << country << " " << strength << " " << agility << " " << luck << " " << stamina << endl;
	writeToFile.close();

	system("CLS");
	cout << "��������� ������� � �������!" << endl;
}


Sportsman::Sportsman(string name,
	string country,
	int strength,
	int agility,
	int luck,
	int stamina) : name(name), country(country), strength(strength), agility(agility), luck(luck), stamina(stamina) {}

Sportsman::Sportsman() {}

Sportsman::Sportsman(const Sportsman& copyFrom) {
	this->name = copyFrom.name;
	this->country = copyFrom.country;
	this->strength = copyFrom.strength;
	this->agility = copyFrom.agility;
	this->luck = copyFrom.luck;
	this->stamina = copyFrom.stamina;
}

Sportsman& Sportsman::operator= (Sportsman other) {
	if (this == &other) {
		return *this;
	}

	this->name = other.name;
	this->country = other.country;
	this->strength = other.strength;
	this->agility = other.agility;
	this->luck = other.luck;
	this->stamina = other.stamina;

	return *this;
}


void Sportsman::set_entry(string name,
	string country,
	int strength,
	int agility,
	int luck,
	int stamina)
{
	this->name = name;
	this->country = country;
	this->strength = strength;
	this->agility = agility;
	this->luck = luck;
	this->stamina = stamina;
}

ostream& operator <<(std::ostream& stream, const Sportsman& sportsman) {
	stream << sportsman.name << " ";
	stream << sportsman.country;
	return stream;
}

string Sportsman::get_name() {
	return this->name;
}

string Sportsman::get_country() {
	return this->country;
}

int Sportsman::get_strength() {
	return this->strength;
}

int Sportsman::get_agility() {
	return this->agility;
}

int Sportsman::get_luck() {
	return this->luck;
}

int Sportsman::get_stamina() {
	return this->stamina;
}