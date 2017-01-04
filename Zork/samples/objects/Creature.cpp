#include "Creature.h"

Creature::Creature(xml_node<> * creatureNode) {
	// TODO Auto-generated constructor stub
	createCreature(creatureNode->first_node());
}

Creature::~Creature() {
	// TODO Auto-generated destructor stub
}

void Creature::createCreature(xml_node<> * childNode) {
	string tmpnme;
	string tmpvalue;
	Trigger * newTrigger;
	this->actions = 0;

	while (childNode != NULL) {
		tmpnme = childNode->name();
		tmpvalue = childNode->value();

		if (tmpnme == "name") {
			this->name = tmpvalue;
		} else if (tmpnme == "vulnerability") {
			this->vulns[tmpvalue] = tmpvalue;
		} else if (tmpnme == "trigger") {
			newTrigger = new Trigger(childNode);
			triggers[newTrigger->name] = newTrigger;
		} else if (tmpnme == "attack") {
			Attack(childNode->first_node());
		}
		childNode = childNode->next_sibling();
	}
}

void Creature::Attack(xml_node<> * childNode) {
	string Name;
	string Value;
	while(childNode != NULL) {
		Name = childNode->name();
		Value = childNode->value();
		if(Name == "print") { this->attack[Name] = Value; }
		else if(Name == "action") {
			string s;
			stringstream out;
			out << actions;
			s = out.str();
			this->attack[Name+s] = Value;
			actions++;
		}
		else if(Name == "condition") { createCond(childNode->first_node()); }
		childNode = childNode->next_sibling();
	}
}

void Creature::createCond(xml_node<> * childNode) {
	//check if status or has condition
	string Name;
	string Value;
	while (childNode != NULL) {
		Name = childNode->name();
		Value = childNode->value();
		if(Name == "object") { this->conditions[Name] = Value; }
		else if (Name == "status") { this->conditions[Name] = Value; }
		childNode = childNode->next_sibling();
	}
}
