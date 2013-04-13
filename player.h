#ifndef PLAYER_H
#define PLAYER_H

#include "item.h"
#include "room.h"

#include <string>
#include <vector>
using namespace std;

class Player {
private:
    string name;
    vector<Item*> inventory;
    bool overEncumbered;
    int currentWeight;
    bool tooLoud;
    int loudness;
    int gameOverLoud;
    int gameOverWeight;
    bool carryingWallet;
    bool carryingKeys;

public:
    Player(string name);
    void addItemToInventory(Item *itemToAdd);
    bool dropItemFromPlayer(string itemToDrop);
    bool checkOverEncumbered();
    bool checkTooLoud();
    int getCurrentWeight();
    int getLoudness();
    vector<string> getPlayerItems();
    int getGameOverLoud();
    int getGameOverWeight();
    string getGameEndingReason();
    bool checkHasWalletKeys();
};

#endif // PLAYER_H
