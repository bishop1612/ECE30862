#include "Item.h"

Item::Item(xml_node<> * Itemnode) {
	xml_node<> * itemNode = Itemnode;
	string xmlname;
	string xmlvalue;
	Trigger* newTrigger;

	xml_node<> * childNode = itemNode->first_node();

	while (childNode != NULL) {
		xmlname = childNode->name();
		xmlvalue = childNode->value();

		if (xmlname == "name") {
			name = xmlvalue;
		} else if (xmlname == "writing") {
			writing = xmlvalue;
		} else if (xmlname == "status") {
			status = xmlvalue;
		} else if (xmlname == "trigger"){
			newTrigger = new Trigger(childNode);
			triggers[newTrigger->name] = newTrigger;
		} else if (xmlname == "turnon"){
			TurnOn(childNode);
		}
		childNode = childNode->next_sibling();
	}
}

Item::~Item() {

}

void Item::TurnOn(xml_node<> * turnNode){
		xml_node<> * childNode = turnNode->first_node();
		string Name;
		string Value;

		while (childNode != NULL) {
			Name = childNode->name();
			Value = childNode->value();

			if(Name == "print") { this->turnOn[Name] = Value; }
			else if(Name == "action") { this->turnOn[Name] = Value; }

			childNode = childNode->next_sibling();
		}
}

