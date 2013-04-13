#include "player.h"

Player::Player(string name)
{
    this->name = name;
    this->overEncumbered = 0;
    this->currentWeight = 0;
    this->tooLoud = 0;
    this->loudness = 0;
    this->gameOverLoud = 6;
    this->gameOverWeight = 1000;
    this->carryingKeys = 0;
    this->carryingWallet = 0;
}

void Player::addItemToInventory(Item *itemToAdd){
    inventory.push_back(itemToAdd);
    this->currentWeight += itemToAdd->getWeight();
    this->loudness += itemToAdd->getLoudness();
    if(itemToAdd->getItemName().compare("Keys") == 0){
        this->carryingKeys = 1;
    }else if(itemToAdd->getItemName().compare("Your Wallet") == 0){
        this->carryingWallet = 1;
    }
}

// Drop item reduce weight
bool Player::dropItemFromPlayer(string itemToDrop) {
    for(unsigned int i = 0; i < inventory.size(); i++){
        string currentItem = inventory[i]->getItemName();
        transform(currentItem.begin(), currentItem.end(), currentItem.begin(), ::tolower);
        if(itemToDrop.compare(currentItem) == 0){
            loudness -= inventory[i]->getLoudness();
            currentWeight -= inventory[i]->getWeight();
            if(itemToDrop.compare("Keys") == 0){
                this->carryingKeys = 0;
            }else if(itemToDrop.compare("Your Wallet") == 0){
                this->carryingWallet = 0;
            }
            if(i == 0){
                inventory.erase(inventory.begin());
            }else{
                inventory.erase(inventory.begin()+i);
            }
            return 1;
        }
    }
    return 0;
}

bool Player::checkOverEncumbered(){
    if(currentWeight > gameOverWeight){
        this->overEncumbered = 1;
        return 1;
    }else{
        this->overEncumbered = 0;
        return 0;
    }
}

bool Player::checkTooLoud(){
    if(loudness > gameOverLoud){
        this->tooLoud = 1;
        return 1;
    }else{
        this->tooLoud = 0;
        return 0;
    }
}

vector<string> Player::getPlayerItems() {
    int itemCount = inventory.size();
    vector<string> listOfItems;
    if(itemCount < 1){
        return listOfItems;
    }else{
        for(int i = 0; i < itemCount; i++){
            listOfItems.push_back(inventory[i]->getItemName());
        }
        return listOfItems;
    }
}

int Player::getCurrentWeight(){
    return currentWeight;
}

int Player::getLoudness(){
    return loudness;
}

int Player::getGameOverLoud(){
    return this->gameOverLoud;
}

int Player::getGameOverWeight(){
    return this->gameOverWeight;
}

string Player::getGameEndingReason(){
    int heavyestItem = 0;
    int loudestItem = 0;
    string heavyestItemName;
    string loudestItemName;
    bool carryingHerWallet = 0;
    bool carryingLaptop = 0;
    bool carryingLaptopCharger = 0;
    for(unsigned int i = 0; i < inventory.size(); i++){
        string currentItem = inventory[i]->getItemName();
        if(inventory[i]->getWeight() > heavyestItem){
            heavyestItemName = currentItem;
        }
        if(inventory[i]->getLoudness() > loudestItem){
            loudestItemName = currentItem;
        }
        if(currentItem.compare("Her Wallet") == 0){
            carryingHerWallet = 1;
        }else if(currentItem.compare("Laptop") == 0){
            carryingLaptop = 1;
        }else if(currentItem.compare("Laptop Charger") == 0){
            carryingLaptopCharger = 1;
        }

    }
    string gameOver;
    if(this->tooLoud == 1 && this->overEncumbered == 1){
        gameOver = "She heard you both cause you tried to carry TOO much stuff and ALL the "
               "loud things you own. That was really dumb. Now your gonna have a chat and "
               "you're going to end up married!";
    }else if(this->tooLoud == 1 && this->overEncumbered == 0){
        gameOver =  "She heard you cause you tried to carry ALL the "
               "loud things you own. That was really dumb. Now your gonna have a chat and "
               "you're going to end up married!";
    }else if(this->tooLoud == 0 && this->overEncumbered == 1){
        gameOver =  "She heard you cause you tried to carry TOO much stuff. "
               "That was really dumb. Now your gonna have a chat and "
               "you're going to end up married!";
    }

    if(this->carryingWallet == 0 && this->carryingKeys == 0){
        gameOver += "\nEvery man should at least have wallet and keys...Phone is debatable - she can call you then";
    }

    if(carryingHerWallet == 1 || (carryingLaptop == 1 && carryingLaptopCharger == 0) ||
            (carryingLaptop == 0 && carryingLaptopCharger == 1)){
        gameOver += "\nOther reasons you screwed up:";
        if(carryingHerWallet == 1){
            gameOver += "\nIt was really silly to pickup her wallet...She has a tracking device inside...";
        }
        if(carryingLaptop == 1 && carryingLaptopCharger == 0){
            gameOver += "\nGood luck using your laptop without a charger";
        }else if(carryingLaptop == 0 && carryingLaptopCharger == 1){
            gameOver += "\nLaptop chargers are really handy...Especially WHEN YOU DIDNT PICK UP YOUR LAPTOP";
        }
    }
    return gameOver;
}

bool Player::checkHasWalletKeys(){
    if(carryingKeys == 0 || carryingWallet == 0){
        return false;
    }
    return true;
}
