#ifndef Room_H_
#define Room_H_

#include <string>
#include <stdio.h>
#include "Trigger.h"
#include <iostream>
#include <map>
#include <vector>
#include "rapidxml-1.13/rapidxml.hpp"

using namespace std;
using namespace rapidxml;

class Room {

public:

	string name;
	string room_type;
	string description;
	
	Room(xml_node<> *);
	virtual ~Room();

	map<string, string> borders;
	map<string, string> items;
	map<string, string> containers;
	map<string, string> creatures;
	map<string, Trigger*> triggers;

private:
	void createBorder(xml_node<> *);
};

#endif /* Room_H_ */
