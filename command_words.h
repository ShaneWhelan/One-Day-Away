#ifndef COMMAND_WORDS_H
#define COMMAND_WORDS_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CommandWords {
private:
	//Define a static vector for our valid command words.
	//We'll populate this in the class constructor
    static vector<string> validCommands;

public:
	CommandWords();
    bool isCommand(string userString);
    string getCommandList();
};


#endif //COMMAND_WORDS_H
