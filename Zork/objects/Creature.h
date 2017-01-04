#ifndef OBJECTS_CREATURE_H_
#define OBJECTS_CREATURE_H_

#include <string>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <cstring>
#include "Trigger.h"
#include "../rapidxml-1.13/rapidxml.hpp"

using namespace std;
using namespace rapidxml;


class Creature {
public:
	string name;
	map<string, string> vulns;
	int actions;
	map<string, string> attack;
	map<string, string> conditions;
	map<string, Trigger*> triggers;

	Creature(xml_node<> *);
	virtual ~Creature();

private:
	void createCreature(xml_node<> *);
	void createAttack(xml_node<> *);
	void createcCondition(xml_node<> *);
};

#endif /* OBJECTS_CREATURE_H_ */
