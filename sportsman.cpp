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

	cout << "Создайте карточку спортсмена. Введите имя, страну принадлежности и четыре параметра." << endl;
	cout << "ФИО: ";
	name = input_string_with_retries(MAX_INPUT_RETRIES);
	cout << endl;

	cout << "Список стран участниц: " << endl;
	for (int i = 0; i < COUNTRIES_NUM; i++) {
		cout << COUNTRIES[i] << endl;
	}
	cout << "Введите страну принадлежности" << endl;
	bool countryInTheList = false;
	while (retries <= MAX_INPUT_RETRIES)
	{
		country = input_string_with_retries(MAX_INPUT_RETRIES);
		// Checking if country is in the list
		for (int i = 0; i < COUNTRIES_NUM; i++) {
			if (country == COUNTRIES[i]) {
				countryInTheList = true;
			}
		}

		if (countryInTheList) {
			break;
		}
		else {
			countryInTheList = false;
			cout << "Введённой страны нет в списке стран участниц. Попробуйте снова. Количество попыток: " << MAX_INPUT_RETRIES - retries - 1 << endl;
			retries++;
		}

		if (retries == MAX_INPUT_RETRIES) {
			cout << "Введённой страны нет в списке стран участниц. Попытки исчерпаны. Выключение программы." << endl;
			exit(1);
		}

	}
	retries = 0;

	cout << "Введите параметры спортсмена:" << endl;
	cout << "Низшая граница: " << LOWEST_SPORTSMAN_PARAMETER << endl << "Высшая граница: " << MAX_SPORTSMAN_PARAMETER << endl;

	cout << "Сила: ";
	strength = input_int_with_retries(MAX_INPUT_RETRIES);
	check_sportsmans_parameter(strength);

	cout << "Ловкость: ";
	agility = input_int_with_retries(MAX_INPUT_RETRIES);
	check_sportsmans_parameter(agility);

	cout << "Удача: ";
	luck = input_int_with_retries(MAX_INPUT_RETRIES);
	check_sportsmans_parameter(luck);

	cout << "Выносливость: ";
	stamina = input_int_with_retries(MAX_INPUT_RETRIES);
	check_sportsmans_parameter(stamina);

	writeToFile << name << " " << country << " " << strength << " " << agility << " " << luck << " " << stamina << endl;
	writeToFile.close();


	system("CLS");
}


Sportsman::Sportsman(	string name,
						string country,
						int strength,
						int agility,
						int luck,
						int stamina) : name(name), country(country), strength(strength), agility(agility), luck(luck), stamina(stamina) {}

Sportsman::Sportsman(){}

void Sportsman::set_entry(	string name,
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

//void Sportsman::operator=(Sportsman& sportsman) {
Sportsman& Sportsman::operator=(Sportsman& sportsman) {
	this->name = sportsman.name;
	this->country = sportsman.country;
	this->strength = sportsman.strength;
	this->agility = sportsman.agility;
	this->luck = sportsman.luck;
	this->stamina = sportsman.stamina;
	
	return *this;
}

string Sportsman::get_name(){
	return this->name;
}

string Sportsman::get_country(){
	return this->country;
}

int Sportsman::get_strength(){
	return this->strength;
}

int Sportsman::get_agility(){
	return this->agility;
}

int Sportsman::get_luck(){
	return this->luck;
}

int Sportsman::get_stamina(){
	return this->stamina;
}
