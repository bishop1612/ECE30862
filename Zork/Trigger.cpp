#include "Trigger.h"

Trigger::Trigger(xml_node<> * trigger) {
	// TODO Auto-generated constructor stub
	xml_node<> * childNode = trigger->first_node();
	string name;
	string val;

	this->trigger_type = "permanent";

	while(childNode != NULL) {
		name = childNode->name();
		val = childNode->value();

		if(name == "type") { this->trigger_type = val; }
		else if (name == "command") { this->command = val; }
		else if (name == "print") {
			this->print = val;
			this->name = val;
		} else if (name == "action") { this->action = val; }
		else if (name == "condition") { createCondition(childNode); }

		childNode = childNode->next_sibling();

	}
}

Trigger::~Trigger() {
	// TODO Auto-generated destructor stub
}


void Trigger::createCondition(xml_node<> * conditionNode) {
	//check if status or has condition
	xml_node<> * childNode = conditionNode->first_node();
	string name;
	string val;

	while (childNode != NULL) {
		name = childNode->name();
		val = childNode->value();

		if(name == "has") { this->conditions[name] = val; }
		else if(name == "object") { this->conditions[name] = val; }
		else if(name == "status") { this->conditions[name] = val; }
		else if(name == "owner") { this->conditions[name] = val; }

		childNode = childNode->next_sibling();
	}

}
