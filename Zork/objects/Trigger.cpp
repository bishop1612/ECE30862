#include "Trigger.h"

Trigger::Trigger(xml_node<> * trigger) {
	// TODO Auto-generated constructor stub
	createTrigger(trigger->first_node());
}

Trigger::~Trigger() {
	// TODO Auto-generated destructor stub
}

void Trigger::createTrigger(xml_node<> * childNode) {
	string Name;
	string Value;

	this->trigger_type = "permanent";

	while(childNode != NULL) {
		Name = childNode->name();
		Value = childNode->value();

		if(Name == "type") { this->trigger_type = Value; }
		else if (Name == "command") { this->command = Value; }
		else if (Name == "print") {
			this->print = Value;
			this->name = Value;
		} else if (Name == "action") { this->action = Value; }
		else if (Name == "condition") { createCondition(childNode); }

		childNode = childNode->next_sibling();

	}
}

void Trigger::createCondition(xml_node<> * conditionNode) {
	//check if status or has condition
	xml_node<> * childNode = conditionNode->first_node();
	string Name;
	string Value;

	while (childNode != NULL) {
		Name = childNode->name();
		Value = childNode->value();

		if(Name == "has") { this->conditions[Name] = Value; }
		else if(Name == "object") { this->conditions[Name] = Value; }
		else if(Name == "status") { this->conditions[Name] = Value; }
		else if(Name == "owner") { this->conditions[Name] = Value; }

		childNode = childNode->next_sibling();
	}

}
