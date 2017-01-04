#include "Game.h"

Game::Game(string filename) {
	Game& game = *this;
	this->currentRoom = "";
	this->input = "";
	this->gameReady = false;
	try {
		gameReady = XML_load(filename);
	} catch (int error) {
		cout << "Error parsing the XML." << endl;
	}
}

Game::~Game() {
	// TODO Auto-generated destructor stub
}

template <typename K, typename V>
std::ostream& operator<<(std::ostream& os, const std::map<K, V>& m)
{
    os << "{ ";
    for (typename std::map<K, V>::const_iterator i = m.begin(); i != m.end(); ++i)
    {
        if (i != m.begin()) os << ", ";
        os << i->first << ": " << i->second;
    }
    return os << " }";
}

bool Game::XML_load(string filename) {
	xml_document<> doc;
	xml_node<> * root_node;
	// Read the xml file into a vector
	ifstream theFile (filename.c_str());
	if (!theFile.is_open()) {
		cout << "Error in opening file. Exiting now." << endl;
		return false;
	}
	vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
	buffer.push_back('\0');
	// Parse the buffer using the xml file parsing library into doc
	doc.parse<0>(&buffer[0]);
	root_node = doc.first_node();
	queue<xml_node<> *> rooms_xml;
	queue<xml_node<> *> items_xml;
	queue<xml_node<> *> triggers_xml;
	queue<xml_node<> *> containers_xml;
	queue<xml_node<> *> creatures_xml;
	xml_node<> * node = root_node->first_node();

	parseXML(node, rooms_xml, items_xml, containers_xml, creatures_xml);

	//Add the rooms to the game
	Item * newItem;
	Room * newRoom;
	Container * newContainer;
	Creature * newCreature;

	while ((items_xml.size()) != 0) {
		newItem = new Item(items_xml.front());
		items[newItem->name] = newItem;
		items_xml.pop();
	}

	while ((containers_xml.size()) != 0) {
		newContainer = new Container(containers_xml.front());
		containers[newContainer->name] = newContainer;
		containers_xml.pop();
	}

	while ((rooms_xml.size()) != 0) {
		newRoom = new Room(rooms_xml.front());
		rooms[newRoom->name] = newRoom;
		rooms_xml.pop();
	}

	while ((creatures_xml.size()) != 0) {
		newCreature = new Creature(creatures_xml.front());
		creatures[newCreature->name] = newCreature;
		creatures_xml.pop();
	}
	return true;
}

void Game::parseXML(xml_node<> * node, queue<xml_node<> *>& rooms_xml, queue<xml_node<> *>& items_xml, queue<xml_node<> *>& containers_xml, queue<xml_node<> *>& creatures_xml) {
	while (node != NULL) {
		if (string((node->name())) == string("room")) {
			rooms_xml.push(node);
		} else if (string((node->name())) == string("item")) {
			items_xml.push(node);
		} else if (string((node->name())) == string("container")){
			containers_xml.push(node);
		} else if (string((node->name())) == string("creature")){
			creatures_xml.push(node);
		}
	node = node->next_sibling();
	}
}

void Game::start() {
	//Always start at entrance
	bool rtn;
	currentRoom = "Entrance";
	cout << rooms.find(currentRoom)->second->description << endl;
	while(true) {
		cout << "What would you like to do?" << endl;
		getline(cin, input);
		if (input == "") {
			cout << "Please input a non-blank command:" << endl;
			continue;
		}

		rtn = triggercheck(input);
		if(rtn == false) {
			takeAction(input);
		}
		triggercheck("");
		rtn = false;
		input = "";
	}
}

void Game::takeAction(string input) {

	// construct a stream from the string
	stringstream strstr(input);

	// use stream iterators to copy the stream to the vector as whitespace separated strings
	istream_iterator<string> it(strstr);
	istream_iterator<string> end;
	vector<string> results(it, end);

	if (input == "n" || input == "e" || input == "s" || input == "w") {
		string direc = input;
		Room * curPtRoom = rooms.find(currentRoom)->second;
		string dir = "";
		string moveTo = "";

		if (direc == "n") {
			dir = "north";
		} else if (direc == "e") {
			dir = "east";
		} else if (direc == "s") {
			dir = "south";
		} else if (direc == "w") {
			dir = "west";
		}

		if(curPtRoom->borders.count(dir) > 0) {
			moveTo = (curPtRoom->borders.find(dir)->second);
			currentRoom = moveTo;
			cout << rooms.find(currentRoom)->second->description << endl;
		} else {
			cout << "Can't go that way." << endl;
		}
	} 
	else if (input == "i") {
		bool first = true;
		if( inventory.empty() ) {
			cout<<"There is nothing in your inventory" << endl;
		} else {
			for(map<string,string>::iterator cnt = inventory.begin(); cnt != inventory.end(); cnt++){
				if(first == true) {
					cout << "Your inventory contains " << cnt->second;
					first = false;
				} else {
					cout << ", " << cnt->second;
				}
			}
			cout << "." << endl;
		}
	} 
	else if (input == "quit") {
		cout<<"quitting game"<<endl;
		exit(EXIT_SUCCESS);
	} 
	else if (results[0] == "open" && results[1] == "exit") {
		Room * curPtRoom = rooms.find(currentRoom)->second;
		if(curPtRoom->room_type == "exit") {
			cout << "Game over!" << endl;
			exit(EXIT_SUCCESS);
		} else {
			cout << "This room is not an exit." << endl;
		}
	} 
	else if (results[0] == "take") {
		string new_item = results[1];
		Room * curPtRoom = rooms.find(currentRoom)->second;
		for(map<string,string>::iterator cnt = curPtRoom->containers.begin(); cnt!= curPtRoom->containers.end(); cnt++) {
			if (containers[cnt->first]->items.count(new_item) > 0) {
				if(containers[cnt->first]->status == "open") {
					inventory[new_item] = new_item;
					containers[cnt->first]->items.erase(new_item);
					cout << "The " << new_item << " has been added to your inventory" << endl;
					return;
				} else {
					cout << "Cannot take " << new_item << ", perhaps trying opening a container." << endl;
					return;
				}
			}
		}
		if (curPtRoom->items.count(new_item) > 0) {
			inventory[new_item] = new_item;
			curPtRoom->items.erase(new_item);
			cout << "The " << new_item << " has been added to your inventory"<<endl;
			return;
		}
		cout <<"Cannot take "<< new_item << endl;
	} else if (results[0] == "open") {
		string x = results[1];
		Room * curPtRoom = rooms.find(currentRoom)->second;
		if (curPtRoom->containers.count(x) > 0) {
			if(containers[x]->status == "locked") {
				cout << "The " << x << " is locked" << endl;
			} else {
				cout << "The " << x << " is now open. ";
				for(map<string,string>::iterator cnt = containers[x]->items.begin(); cnt != containers[x]->items.end(); cnt++) {
					cout << "The container contains " << cnt->first << "." << endl;
				}
				containers[x]->status = "open";
			}
		} else {
			cout << "A " << x << " is not found in this room." << endl;
		}
	} else if (results[0] == "read") {
		string searchItem = results[1];
		bool found = false;
		for(map<string,string>::iterator cnt = inventory.begin(); cnt != inventory.end(); cnt++){
			if (cnt->second == searchItem){
				cout << "The " << searchItem << " reads: " << items[searchItem]->writing;//need to find out how to display writing
				found = true;
			}
		}
		if (found == false){
			cout << "The " << searchItem << " is not in your inventory";
		}
		cout <<endl;
	} else if (results[0] == "drop") {
		string searchItem = results[1];
		Room * curPtRoom = rooms.find(currentRoom)->second;

		if (inventory.count(searchItem) > 0){
			curPtRoom->items[searchItem] = inventory[searchItem];
			inventory.erase(searchItem);
			cout << "The " << searchItem << " has been dropped";
		}
		else{
			cout << "The " << searchItem << " is not in your inventory";
		}
		cout<<endl;
	} else if (results[0] == "put") {
		string itemName = results[1];
		string containerName = results[3];
		Room * curPtRoom = rooms.find(currentRoom)->second;
		if (inventory.count(itemName) > 0){
			if (curPtRoom->containers.count(containerName) > 0){
				Container * curContainer = containers.find(containerName)->second;
				curContainer->items[itemName] = inventory[itemName];
				inventory.erase(itemName);
				cout<<itemName<<" has been put into "<<containerName<<endl;
			} else{
				cout<<"Cannot perform action, container does not exist in current room"<<endl;
			}
		} else{
			cout<<itemName<<"Cannot perform action, item is not in your inventory"<<endl;
		}
	} else if (results[0] == "turn" && results.size() > 2) {
		string selectedItem = results[2];
		Item* itemPtr;
		if (inventory.count(selectedItem) > 0){
			cout<<"You have activated "<<selectedItem<<endl;
			itemPtr = items.find(selectedItem)->second;
			cout<<itemPtr->turnOn["print"]<<endl;

			// construct a stream from the string
			if(!itemPtr->turnOn["action"].empty()){
				takeAction(itemPtr->turnOn["action"]);
			}
		} else {
			cout<<"Unable to turn on "<<selectedItem<<", not in your inventory"<<endl;
		}
	} else if (results[0] == "attack" && results.size() > 3) {
		string creature = results[1];
		string weapon = results[3];
		bool rtn = false;
		bool atk = false;
		Room * curPtRoom = rooms.find(currentRoom)->second;
		if(inventory.count(weapon) == 0) {
			cout << weapon << " is not in your inventory" << endl;
			return;
		}
		if(curPtRoom->creatures.count(creature) > 0) {
			for(map<string, string>::iterator cnt = creatures[creature]->vulns.begin(); cnt != creatures[creature]->vulns.end(); cnt++) {
				if(cnt->second == weapon) {
					if(creatures[creature]->conditions.empty()) {
						cout << creatures[creature]->attack["print"] << endl;
						for(int i = 0; i < creatures[creature]->actions; i++) {
							string s;
							stringstream out;
							out << i;
							s = out.str();
							atk = true;
							takeAction(creatures[creature]->attack["action"+s]);
						}
					} else {
						rtn = conditioncheck(creatures[creature]->conditions, "permanent");
						if(rtn == true) {
							cout << creatures[creature]->attack["print"] << endl;
							for(int i = 0; i < creatures[creature]->actions; i++) {
								string s;
								stringstream out;
								out << i;
								s = out.str();
								atk = true;
								takeAction(creatures[creature]->attack["action"+s]);
							}
						} else {
							cout << "Attack failed. Conditions not met." << endl;
						}
					}
				}
			}
			if(atk != true) {
				cout << "Nothing happened." << endl;
			}
		} else {
			cout << "No " << creature << " in this room." << endl;
		}
	} else if (results[0] == "Add"){
		string itemName = results[1];
		string location = results[3];
		Room * curPtRoom;
		Container * curPtCon;
		string itemType;
		string locationType = "Room";

		for(map<string,Item*>::iterator cnt = items.begin(); cnt != items.end(); cnt++){
			if (cnt->first == itemName){
				itemType = "item";
			}
			if (cnt->first == location){
				itemType = "item";
			}
		}
		for(map<string,Container*>::iterator cnt = containers.begin(); cnt != containers.end(); cnt++){
			if (cnt->first == itemName){
				itemType = "container";
			}
			if (cnt->first == location){
				locationType = "container";
			}
		}

		for(map<string,Creature*>::iterator cnt = creatures.begin(); cnt != creatures.end(); cnt++){
			if (cnt->first == itemName){
				itemType = "creature";
			}
			if (cnt->first == location){
				locationType = "creature";
			}
		}

		for(map<string,Room*>::iterator cnt = rooms.begin(); cnt != rooms.end(); cnt++){
			if (cnt->first == itemName){
				itemType = "room";
			}
			if (cnt->first == location){
				locationType = "room";
			}
		}
		if (itemType == "item"){
			if(locationType == "container"){
				curPtCon = containers.find(location)->second;
				curPtCon->items[itemName] = itemName;
			} else if(locationType == "room"){
				curPtRoom = rooms.find(location)->second;
				curPtRoom->items[itemName] = itemName;
			} else {
				cout<<"Error, location does not exist in XML"<<endl;
			}
		}else if (itemType == "container"){
			if (locationType == "room"){
				curPtRoom = rooms.find(location)->second;
				curPtRoom->containers[itemName] = itemName;
			} else {
				cout<<"Error, containers can only be added to rooms"<<endl;
			}
		} else if (itemType == "creature") {
			if (locationType == "room"){
				curPtRoom = rooms.find(location)->second;
				curPtRoom->creatures[itemName] = itemName;
			} else{
				cout<<"Error, creatures can only be added to rooms"<<endl;
			}
		} else{
			cout<<"Error, object not recognized"<<endl;
		}
	} else if(results[0] == "Delete"){
		string itemName = results[1];
		bool found = false;
		Room * curPtRoom;

		for(map<string,Room*>::iterator cnt = rooms.begin(); cnt != rooms.end(); cnt++){
			if (cnt->first == itemName){
				rooms.erase(itemName);
				found = true;
			}
		}

		if (found == false){
			for(map<string,Item*>::iterator cnt = items.begin(); cnt != items.end(); cnt++){
				if (cnt->first == itemName){
					for(map<string,Room*>::iterator cnt2 = rooms.begin(); cnt2 != rooms.end(); cnt2++){
						curPtRoom = rooms.find(cnt2->first)->second;
						curPtRoom->items.erase(itemName);
					}
					found = true;
				}
			}
		}
		if (found == false){
			for(map<string,Container*>::iterator cnt = containers.begin(); cnt != containers.end(); cnt++){
				if (cnt->first == itemName){
					for(map<string,Room*>::iterator cnt2 = rooms.begin(); cnt2 != rooms.end(); cnt2++){
						curPtRoom = rooms.find(cnt2->first)->second;
						curPtRoom->containers.erase(itemName);
					}
					found = true;
				}
			}
		}
		if (found == false){
			for(map<string,Creature*>::iterator cnt = creatures.begin(); cnt != creatures.end(); cnt++){
				if (cnt->first == itemName){
					for(map<string,Room*>::iterator cnt2 = rooms.begin(); cnt2 != rooms.end(); cnt2++){
						curPtRoom = rooms.find(cnt2->first)->second;
						curPtRoom->creatures.erase(itemName);
					}
					found = true;
				}
			}
		}
	} else if (results[0] == "Update"){
		string objectChanged = results[1]; 
		string newStatus = results[3];
		Item* curPtItem;
		Container* curPtCont;
		if(items.count(objectChanged) > 0) {
			curPtItem = items.find(objectChanged)->second;
			curPtItem->status = newStatus;
		}
		if(containers.count(objectChanged) > 0) {
			curPtCont = containers.find(objectChanged)->second;
			curPtCont->status = newStatus;
		}
	} else if (results[0] == "Game" && results[1] == "Over"){
		cout<<"Victory!!"<<endl;
		exit(EXIT_SUCCESS);
	} else {
		cout << "Command not recognized." << endl;
	}

}


bool Game::triggercheck(string input) {
	bool rtn = false;

	//CHECK ROOM TRIGGERS
	map<string, Trigger*> temp = rooms.find(currentRoom)->second->triggers;
	for(map<string, Trigger*>::iterator cnt = temp.begin(); cnt != temp.end(); cnt++) {
		if(cnt->second->command == input) {
			rtn = conditioncheck(cnt->second->conditions, cnt->second->trigger_type);
			if(rtn == true) {
				cout << cnt->second->print << endl;
				if(cnt->second->trigger_type == "single") { cnt->second->trigger_type = "done"; }
				return rtn;
			} else {
				return rtn;
			}
		}
	}
	//CHECK CREATURE TRIGGERS
	map<string, string> creat = rooms.find(currentRoom)->second->creatures;
	for(map<string,string>::iterator crt = creat.begin(); crt != creat.end(); crt++) {
		temp = creatures[crt->first]->triggers;
		for(map<string, Trigger*>::iterator cnt = temp.begin(); cnt != temp.end(); cnt++) {
			rtn = conditioncheck(cnt->second->conditions, cnt->second->trigger_type);
			if(rtn == true) {
				cout << cnt->second->print << endl;
				if(cnt->second->trigger_type == "single") { cnt->second->trigger_type = "done"; }
				return rtn;
			} else {
				return rtn;
			}
		}
	}
	//CHECK CONTAINER TRIGGERS
	map<string, string> cont = rooms.find(currentRoom)->second->containers;
	for(map<string,string>::iterator crt = cont.begin(); crt != cont.end(); crt++) {
		temp = containers[crt->first]->triggers;
		for(map<string, Trigger*>::iterator cnt = temp.begin(); cnt != temp.end(); cnt++) {
			rtn = conditioncheck(cnt->second->conditions, cnt->second->trigger_type);
			if(rtn == true) {
				cout << cnt->second->print << endl;
				takeAction(cnt->second->action);
				if(cnt->second->trigger_type == "single") { cnt->second->trigger_type = "done"; }
				return rtn;
			} else {
				return rtn;
			}
		}
	}
	return false;
}

bool Game::conditioncheck(map<string, string> conditions, string trigType) {
	if(trigType == "permanent" || trigType == "single") {
		if (conditions["has"] == "no") {
			if(inventory.count(conditions["object"]) == 0) {
				if (conditions["type"] == "single") { conditions["type"] = "done"; }
				return true;
			} else {
				return false;
			}
		} else if (conditions["has"] == "yes") {
			if(containers[conditions["owner"]]->items.count(conditions["object"]) > 0) {
				return true;
			}
		}
		if (!conditions["status"].empty() && !conditions["object"].empty()) {
			if(items.count(conditions["object"]) > 0 ) {
				if(items[conditions["object"]]->status == conditions["status"]) {
					return true;
				} else {
					return false;
				}
			} else if (containers.count(conditions["object"]) > 0) {
				if(containers[conditions["object"]]->status == conditions["status"]) {
					return true;
				} else {
					return false;
				}
			}
		}
	}
	return false;
}

