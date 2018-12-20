#include "discipline.h"

// pair of basic constructors, no more needed
Discipline::Discipline(	string name,
						int str,
						int agi,
						int luc,
						int sta) : name(name), strengthModifier(str), agilityModifier(agi), luckModifier(luc), staminaModifier(sta) {}

Discipline::Discipline(){}

// To set rules or change them
void Discipline::set_rules(	int str,
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

string Discipline::get_name(){
	return this->name;
}

Sportsman Discipline::get_victor(){
	return this->victor;
}

void Discipline::compete(MList<Sportsman>& participants) {

	for (int i = 0; i < participants.get_length(); ++i) {
		auto currentParticipant = participants[i];
		auto newNode = new Node<int>;
		newNode->value = strengthModifier*currentParticipant.get_strength() + agilityModifier*currentParticipant.get_agility()
			+ luckModifier*currentParticipant.get_luck() + staminaModifier*currentParticipant.get_stamina();
		this->lastResults.push_back(newNode);
	}

	int victorId = 0;
	int maxResults = 0;
	for (int i = 0; i < participants.get_length(); ++i) {
		if (this->lastResults[i] > maxResults) {
			maxResults = this->lastResults[i];
			victorId = i;
		}
	}

	this->victor = participants[victorId];
	
	observerList->updateResult(this->lastResults, this->name);
}

void Discipline::attach(Observer &obs) {
	
	observerList = &obs;
	cout << "fuck eah" << endl;
}
