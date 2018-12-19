#include "sportsman.h"

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