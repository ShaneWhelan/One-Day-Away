#include "engine.h"

Engine::Engine() {
    createRooms();
}

void Engine::createRooms()  {
    hallway = new Room("Hallway", "By failing to prepare, you are preparing to fail. Get what you need for the road before leaving. Avoid confrontation at all costs.");
    sittingRoom = new Room("Sitting Room", "This place brings back memories of all the crazy times you've had together. Like that time she asked you to marry her and that other time she asked you to marry her...Sigh...She does that a lot.");
    ensuite = new Room("Ensuite", "You were told she was in the shower but you were dumb enough to open the door? Maybe she was right and you just don't listen. You deserve to be married to this crazy bitch for good!");
    office = new Room("Office", "Ah the office, your one safe haven. Once you were destined to be a programmer and dreamed of working for Google. But when you moved in together that was it, now she has you watching Coronation Street.");
    diningRoom = new Room("Dining Room", "She has served you so many nice meals here. Maybe you should consider staying with her for her food. It wouldnt be the first time a man has made that sacrifice.");
    kitchen = new Room("Kitchen", "If you are going to have 'the talk' maybe its best to hide any sharp objects to avoid severe pain.");
    masterBedRoom = new Room("Master Bedroom", "The sex is great...when she decides to give it to you, but what about your dignity? Run, don't do it. She is C-R-A-Z-Y afterall.");
    exit = new Room("Exit", "If your seeing this then you won.........the battle.... of course you need to go back home at some stage. Maybe she will always win, maybe she will become tolerable, maybe shes not crazy at all but your the crazy one. Just maybe.");
    garage = new Room("Garage", "Pros: The car is fast. Cons: The car is loud, it will run out of petrol eventually, she will cancel your cards and you will have to crawl back to her anyway. Maybe you should consider giving up.");

    diningRoom->setExits(NULL, hallway, office, kitchen);
    hallway->setExits(diningRoom,exit,masterBedRoom,sittingRoom);
    sittingRoom->setExits(kitchen, garage, hallway, NULL);
    ensuite->setExits(NULL, masterBedRoom, NULL, NULL);
    office->setExits(NULL, NULL, NULL, diningRoom);
    kitchen->setExits(NULL, sittingRoom, diningRoom, NULL);
    masterBedRoom->setExits(ensuite, NULL, NULL, hallway);
    exit->setExits(NULL, NULL, NULL, NULL);
    garage->setExits(sittingRoom, NULL, NULL, NULL);

    yourWallet = new Item("Your Wallet", "Can't go far without a wallet!", 200, 0);
    itemList.push_back(yourWallet);
    pillows = new Item("Pillows", "Throw them as a distraction?", 1500, 0);
    itemList.push_back(pillows);
    herWallet = new Item("Her Wallet", "You would be brave to take this", 200, 0);
    itemList.push_back(herWallet);
    television = new Item("Television", "You can divide your posessions later",200, 20);
    itemList.push_back(television);
    change = new Item("Loose Change", "Could be useful", 200, 4);
    itemList.push_back(change);
    Rugsack = new Item("Rugsack", "Will you risk it?", 500, 1);
    itemList.push_back(Rugsack);
    keys = new Item("Keys", "PKW - Phone Keys Wallet", 50, 4);
    itemList.push_back(keys);
    laptop = new Item("Laptop", "You may need this to find a new Girlfriend", 500, 3);
    itemList.push_back(laptop);
    laptopCharger = new Item("Laptop Charger", "POWER", 200, 2);
    itemList.push_back(laptopCharger);
    knife = new Item("Knife", "Dont go to jail", 200, 2);
    itemList.push_back(knife);
    atlas = new Item("Atlas", "She has probably hidden your satnav", 200, 1);
    itemList.push_back(atlas);
    candle = new Item("Candle", "Witch burning is frowned upon these days", 200, 1);
    itemList.push_back(candle);
    spanner = new Item("Spanner", "You're the tool if you use this on her, jail isn't nice", 200, 1);
    itemList.push_back(spanner);
    hammer = new Item("Hammer", "It's certainly not hammer-time...", 200, 1);
    itemList.push_back(hammer);

    masterBedRoom->addItemToRoom(yourWallet);
    masterBedRoom->addItemToRoom(pillows);
    sittingRoom->addItemToRoom(herWallet);
    sittingRoom->addItemToRoom(television);
    sittingRoom->addItemToRoom(change);
    hallway->addItemToRoom(atlas);
    hallway->addItemToRoom(Rugsack);
    hallway->addItemToRoom(keys);
    office->addItemToRoom(laptop);
    office->addItemToRoom(laptopCharger);
    kitchen->addItemToRoom(knife);
    diningRoom->addItemToRoom(candle);
    garage->addItemToRoom(spanner);
    garage->addItemToRoom(hammer);
    currentRoom = kitchen;
    isGameOver = false;
}

string Engine::processCommand(Command command) {
    string commandWord = command.getCommandWord();
    string secondWord = command.getSecondWord();
    transform(secondWord.begin(), secondWord.end(), secondWord.begin(), ::tolower);

    if (!command.isValid()) {
        if(!secondWord.empty()){
            return "I do not understand the phrase \"" + commandWord + " " +
                    secondWord + "\". Try again.";
        }else{
            return "I do not understand the phrase \"" + commandWord + "\". Try again.";
        }
    }

    if (commandWord.compare("info") == 0) {
        vector<string> listOfItems = currentRoom->getRoomItems();
        string items = "Items:\n";
        int listOfItemsSize = listOfItems.size();
        if(listOfItemsSize > 0){
            for(int i = 0; i < listOfItemsSize; i++){
                items += listOfItems[i] + "\n";
            }
        }else{
            items = "No items in this room.";
        }
        CommandWords commandList;
        return "Possible Commands are: " + commandList.getCommandList() + "\n" +
                items;

    }else if (commandWord.compare("map") == 0) {
         return (string) "[Kitchen] ------- [Dining Room] ------- [Office]\n" +
                         "    |                 |                    |\n" +
                         "[Sitting Room] -- [hallway] ----------- [Ensuite]\n" +
                         "    |                 |                    |\n" +
                         "[Garage] -------- [Exit] -------------- [Bedroom]";
    }else if (commandWord.compare("go") == 0) {
        if(!secondWord.empty()){
            Room *tempRoom = currentRoom;
            string roomResult = goDirection(secondWord);
            if(currentRoom->getRoomName().compare("Exit") == 0){
                if(player->checkTooLoud() == 1 || player->checkOverEncumbered() == 1) {
                    isGameOver = true;
                    return "Game Over";
                }else if(player->checkHasWalletKeys() == false){
                    currentRoom = tempRoom;
                    return "You wont go far without your wallet and keys!";
                }else{
                    return "You Win";
               }
            }
            return roomResult;
        }else{
            return "No Direction Given";
        }
    }else if (commandWord.compare("take") == 0) {
        if (!command.hasSecondWord()) {
            return "Take what?";
        } else if(command.hasSecondWord()) {
            // Check if actually in room for Old School
            if(takeItem(secondWord)){
                return "Item taken";
            }else{
                return "Not in room";
            }
        }
    }else if (commandWord.compare("drop") == 0) {
        if (!command.hasSecondWord()) {
            return "Drop what?";
        }else{
            //Check if actually carrying item
            if(dropItem(secondWord)){
                return "Item dropped";
            }else{
                return "Not carrying that item!";
            }
        }
    }else if(commandWord.compare("inventory") == 0){
        vector<string> listOfPlayerItems = player->getPlayerItems();
        if(listOfPlayerItems.size() > 0){
            string items = "\nInventory:\n";
            for(unsigned int i = 0; i < listOfPlayerItems.size(); i++){
                items += listOfPlayerItems[i] + "\n";
            }
            return items;
        }else{
            return "Inventory Empty!";
        }
    }
    return "false";
}

string Engine::getCurrentRoomName(){
    return currentRoom->getRoomName();
}

string Engine::getCurrentRoomDescription(){
    return currentRoom->getRoomDescription();
}

string Engine::goDirection(string direction) {
    Room *changeRoom = currentRoom->changeRoom(direction);
    if (changeRoom == NULL) {
        if(numberOfFailedMoves > 4){
            return "Christ. Learn your way round your own damn house.";
        }else{
            numberOfFailedMoves++;
            return "It's just a wall. You cant travel through walls.";
        }
    } else {
        currentRoom = changeRoom;
        return currentRoom->getRoomDescription();
    }
}

bool Engine::takeItem(string itemName){
    if(currentRoom->takeItemFromRoom(itemName)){
        for(unsigned int i = 0; i < itemList.size(); i++) {
            string currentItem = itemList[i]->getItemName();
            transform(currentItem.begin(), currentItem.end(), currentItem.begin(), ::tolower);
            if(itemName.compare(currentItem) == 0){
                player->addItemToInventory(itemList[i]);
                return 1;
            }
        }
    }
    return 0;
}

bool Engine::dropItem(string itemName){
    if(player->dropItemFromPlayer(itemName)){
        for(unsigned int i = 0; i < itemList.size(); i++) {
            string currentItem = itemList[i]->getItemName();
            transform(currentItem.begin(), currentItem.end(), currentItem.begin(), ::tolower);
            if(itemName.compare(currentItem) == 0){
                currentRoom->addItemToRoom(itemList[i]);
                return 1;
            }
        }
    }
    return 0;
}

string Engine::getItemHint(string itemName){
    for(unsigned int i = 0; i < itemList.size(); i++){
        if(itemName.compare(itemList[i]->getItemName()) == 0){
            return itemList[i]->getHint();
        }
    }
    return "";
}

void Engine::resetGame(){
    delete(player);
    /*
    delete(yourWallet);
    delete(pillows);
    delete(herWallet);
    delete(television);
    delete(change);
    delete(Rugsack);
    delete(keys);
    delete(laptop);
    delete(laptopCharger);
    delete(knife);
    delete(atlas);
    delete(candle);
    delete(spanner);
    delete(hammer);

    delete(currentRoom);
    delete(hallway);
    delete(sittingRoom);
    delete(ensuite);
    delete(office);
    delete(diningRoom);
    delete(kitchen);
    delete(masterBedRoom);
    delete(exit);
    delete(garage);
*/
    player = new Player("shane");
    createRooms();
    setGameState(false);
}

bool Engine::getGameState(){
    return isGameOver;
}

void Engine::setGameState(bool isGameOver){
    this->isGameOver = isGameOver;
}
