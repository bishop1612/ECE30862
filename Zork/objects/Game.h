#ifndef OBJECTS_Game_H_
#define OBJECTS_Game_H_

#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <vector>
#include <map>
#include <queue>
#include "Room.h"
#include "Item.h"
#include "Trigger.h"
#include "Container.h"
#include "Creature.h"
#include "../rapidxml-1.13/rapidxml.hpp"

using namespace std;
using namespace rapidxml;

class Game {
public:
	Game(string);
	Game(Game&);
	virtual ~Game();
	void start();
	map<string, Room*> rooms;
	map<string, Item*> items;
	map<string, string> inventory;
	map<string, Container*> containers;
	map<string, Creature*> creatures;
	string currentRoom;
	string input;
	bool gameReady;

private:
	bool XML_load(string filename);
	void parseXML(xml_node<> *, queue<xml_node<> *>&, queue<xml_node<> *>&, queue<xml_node<> *>&, queue<xml_node<> *>&);
	void takeAction(string);
	bool triggercheck(string);
	bool conditioncheck(map<string, string>, string);
};

#endif /* OBJECTS_Game_H_ */
