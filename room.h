#ifndef ROOM_H
#define ROOM_H

#include "item.h"

#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

class Room{
private:
    string roomName;
    string description;
    map<string, Room*> exits;
    vector<Item*> itemsInRoom;

public:
    Room(string roomName, string description);
    string getExits();
    void setExits(Room *north, Room *south, Room *east, Room *west);
    string getRoomName();
    string getRoomDescription();
    string getAllRoomInformation();
    Room* changeRoom(string direction);
    void addItemToRoom(Item *itemToAdd);
    vector<string> getRoomItems();
    bool takeItemFromRoom(string itemToTake);
};

#endif // ROOM_H
