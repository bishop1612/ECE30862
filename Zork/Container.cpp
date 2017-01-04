#include "Container.h"

Container::Container(xml_node<> * containernode) {
	xml_node<> * childNode = containernode->first_node();
	string tmpnme;
	string tmpvalue;
	Trigger* newTrigger;

	while (childNode != NULL) {
		tmpnme = childNode->name();
		tmpvalue = childNode->value();

		if (tmpnme == "name") {
			this->name = tmpvalue;
		}  
		if (tmpnme == "item") {
			this->items[tmpvalue] = tmpvalue;
		}  
		if (tmpnme == "accept") {
			this->accept = tmpvalue;
		}  
		if (tmpnme == "status") {
			this->status = tmpvalue;
		}  
		if (tmpnme == "trigger"){
			newTrigger = new Trigger(childNode);
			triggers[newTrigger->name] = newTrigger;
		}
		childNode = childNode->next_sibling();
	}
	
}

Container::~Container() {
	// TODO Auto-generated destructor stub
}

