#ifndef ENGINE_H
#define ENGINE_H

#include "command.h"
#include "command_words.h"
#include "player.h"
#include "room.h"
#include "item.h"

#include <string>
#include <vector>
using namespace std;
class Engine
{

private:
    void createRooms();
    string goDirection(string direction);
    vector <Item*> itemList;
    int numberOfFailedMoves = 0;
    bool isGameOver;

public:
    Engine();
    Room *currentRoom;
    Room *hallway;
    Room *sittingRoom;
    Room *ensuite;
    Room *office;
    Room *diningRoom;
    Room *kitchen;
    Room *masterBedRoom;
    Room *exit;
    Room *garage;
    Item *yourWallet;
    Item *pillows;
    Item *herWallet;
    Item *television;
    Item *change;
    Item *Rugsack;
    Item *keys;
    Item *laptop;
    Item *laptopCharger;
    Item *knife;
    Item *atlas;
    Item *candle;
    Item *spanner;
    Item *hammer;
    Player *player = new Player("shane");
    string processCommand(Command command);
    string getCurrentRoomName();
    string getCurrentRoomDescription();
    bool takeItem(string itemName);
    bool dropItem(string itemName);
    string getItemHint(string itemName);
    void resetGame();
    bool getGameState();
    void setGameState(bool isGameOver);
};

#endif // ENGINE_H
