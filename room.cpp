#include "room.h"

Room::Room(string roomName, string description) {
    this->roomName = roomName;
    this->description = description;
}

string Room::getExits(){
    string returnString = "\nexits =";
    for (map<string, Room*>::iterator i = exits.begin(); i != exits.end(); i++)
        // Loop through map
        returnString += "  " + i->first;	// access the "first" element of the pair (direction as a string)
    return returnString;
}

void Room::setExits(Room *north, Room *south, Room *east,Room *west){
    if(north != NULL)
        exits["north"] = north;
    if(south != NULL)
        exits["south"] = south;
    if(east != NULL)
        exits["east"] = east;
    if(west != NULL)
        exits["west"] = west;
}

string Room::getRoomName(){
    return roomName;
}

string Room::getRoomDescription() {
    return description;
}

string Room::getAllRoomInformation() {
    return roomName + "\n" + description + "\n" +
            getExits();
}

Room* Room::changeRoom(string direction) {
    map<string, Room*>::iterator next = exits.find(direction); //returns an iterator for the "pair"
    if (next == exits.end())
        return NULL; // if exits.end() was returned, there's no room in that direction.
    return next->second; // If there is a room, remove the "second" (Room*)
                // part of the "pair" (<string, Room*>) and return it.
}

void Room::addItemToRoom(Item *itemToAdd) {
    itemsInRoom.push_back(itemToAdd);
}

vector<string> Room::getRoomItems() {
    int itemCount = itemsInRoom.size();
    vector<string> listOfItems;
    if(itemCount < 1){
        return listOfItems;
    }else{
        for(int i = 0; i < itemCount; i++){
            listOfItems.push_back(itemsInRoom[i]->getItemName());
        }
        return listOfItems;
    }
}

bool Room::takeItemFromRoom(string itemToTake) {
    for(unsigned int i = 0; i < itemsInRoom.size(); i++){
        string currentItem = itemsInRoom[i]->getItemName();
        transform(currentItem.begin(), currentItem.end(), currentItem.begin(), ::tolower);
        if(itemToTake.compare(currentItem) == 0){
            if(i == 0){
                itemsInRoom.erase(itemsInRoom.begin());
            }else{
                itemsInRoom.erase(itemsInRoom.begin()+i);
            }
            return 1;
        }
    }
    return 0;
}
