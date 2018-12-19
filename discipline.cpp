#include "discipline.h"

Discipline::Discipline(string name,
	int str,
	int agi,
	int luc,
	int sta) : name(name), strengthModifier(str), agilityModifier(agi), luckModifier(luc), staminaModifier(sta) {}

Discipline::Discipline() {}

Discipline::Discipline(const Discipline& copyFrom) {
	this->winner = copyFrom.winner;
	this->name = copyFrom.name;
	this->agilityModifier = copyFrom.agilityModifier;
	this->strengthModifier = copyFrom.strengthModifier;
	this->luckModifier = copyFrom.luckModifier;
	this->staminaModifier = copyFrom.staminaModifier;
	this->lastResults = copyFrom.lastResults;
}

Discipline& Discipline::operator= (Discipline other) {
	if (this == &other) {
		return *this;
	}

	this->winner = other.winner;
	this->name = other.name;
	this->agilityModifier = other.agilityModifier;
	this->strengthModifier = other.strengthModifier;
	this->luckModifier = other.luckModifier;
	this->staminaModifier = other.staminaModifier;
	this->lastResults = other.lastResults;

	return *this;
}

// To set rules or change them
void Discipline::set_rules(int str,
	int agi,
	int luc,
	int sta)
{
	this->strengthModifier = str;
	this->agilityModifier = agi;
	this->luckModifier = luc;
	this->staminaModifier = sta;
}

void Discipline::set_rules(const int* rules) {
	this->set_rules(rules[0],
		rules[1],
		rules[2],
		rules[3]);
}

void Discipline::set_name(string name) {
	this->name = name;
}

MList<int> Discipline::get_results() {
	return this->lastResults;
}

string Discipline::get_name() {
	return this->name;
}

Sportsman Discipline::get_winner() {
	return this->winner;
}

MList<int> Discipline::compete(MList<Sportsman> participants) {

	for (int i = 0; i < participants.get_length(); i++) {
		Sportsman currentParticipant = participants[i];
		Node<int> * newNode = new Node<int>;
		newNode->value = strengthModifier*currentParticipant.get_strength() + agilityModifier*currentParticipant.get_agility()
			+ luckModifier*currentParticipant.get_luck() + staminaModifier*currentParticipant.get_stamina();
		this->lastResults.push_back(newNode);
	}

	int victorId = 0;
	int maxResults = 0;
	for (int i = 0; i < participants.get_length(); i++) {
		if (this->lastResults[i] > maxResults) {
			maxResults = this->lastResults[i];
			victorId = i;
		}
	}

	this->winner = participants[victorId];
	return this->lastResults;
}