#include "Room.h"

Room::Room(xml_node<> * RoomNode) {
	xml_node<> * childNode = RoomNode->first_node();
	string xmlname;
	string xmlvalue;
	Trigger* newTrigger;

	this->room_type = "regular";

	while (childNode != NULL) {
		xmlname = childNode->name();
		xmlvalue = childNode->value();

		if (xmlname == "name") {
			this->name = xmlvalue;
		} else if (xmlname == "description") {
			this->description = xmlvalue;
		} else if (xmlname == "type") {
			this->room_type = xmlvalue;
		} else if (xmlname == "border") {
			createBorder(childNode);
		} else if (xmlname == "item") {
			this->items[xmlvalue] = xmlvalue;
		} else if (xmlname == "creature") {
			this->creatures[xmlvalue] = xmlvalue;
		} else if (xmlname == "container") {
			this->containers[xmlvalue] = xmlvalue;
		} else if (xmlname == "trigger"){
			newTrigger = new Trigger(childNode);
			triggers[newTrigger->name] = newTrigger;
		}

		childNode = childNode->next_sibling();

	}
}

Room::~Room() {

}

void Room::createBorder(xml_node<> * borderNode) {
	string xmlname;
	string xmlvalue;
	string direction;
	string name;
	xml_node<> * childNode = borderNode->first_node();

	while (childNode != NULL) {
		xmlname = childNode->name();
		xmlvalue = childNode->value();

		if (xmlname == "direction") {
			direction = xmlvalue;
		} else if (xmlname == "name") {
			name = xmlvalue;
		}

		childNode = childNode->next_sibling();
	}
	//add to the map
	this->borders[direction] = name;
}
