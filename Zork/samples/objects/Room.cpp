#include "Room.h"

Room::Room(xml_node<> * RoomNode) {
	createRoom(RoomNode->first_node());
}

Room::~Room() {

}

void Room::createRoom(xml_node<> * childNode) {
	string xmlName;
	string xmlValue;
	Trigger* newTrigger;

	this->room_type = "regular";

	while (childNode != NULL) {
		xmlName = childNode->name();
		xmlValue = childNode->value();

		if (xmlName == "name") {
			this->name = xmlValue;
		} else if (xmlName == "description") {
			this->description = xmlValue;
		} else if (xmlName == "type") {
			this->room_type = xmlValue;
		} else if (xmlName == "border") {
			createBorder(childNode);
		} else if (xmlName == "item") {
			this->items[xmlValue] = xmlValue;
		} else if (xmlName == "creature") {
			this->creatures[xmlValue] = xmlValue;
		} else if (xmlName == "container") {
			this->containers[xmlValue] = xmlValue;
		} else if (xmlName == "trigger"){
			newTrigger = new Trigger(childNode);
			triggers[newTrigger->name] = newTrigger;
		}

		childNode = childNode->next_sibling();

	}
}

void Room::createBorder(xml_node<> * borderNode) {
	string xmlName;
	string xmlValue;
	string direction;
	string name;
	xml_node<> * childNode = borderNode->first_node();

	while (childNode != NULL) {
		xmlName = childNode->name();
		xmlValue = childNode->value();

		if (xmlName == "direction") {
			direction = xmlValue;
		} else if (xmlName == "name") {
			name = xmlValue;
		}

		childNode = childNode->next_sibling();
	}
	//add to the map
	this->borders[direction] = name;
}
