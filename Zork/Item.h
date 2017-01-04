#ifndef ITEM_H_
#define ITEM_H_

#include <string>
#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include "Trigger.h"
#include "rapidxml-1.13/rapidxml.hpp"

using namespace std;
using namespace rapidxml;

class Item {
public:
	string name;
	string description;
	string writing;
	string status;
	string debug;
	
	Item(rapidxml::xml_node<> *);
	virtual ~Item();

	
	map<string, string> turnOn;
	map<string, Trigger*> triggers;

private:
	void TurnOn(xml_node<> * );
};



#endif /* ITEM_H_ */
