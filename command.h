#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include "command_words.h"
using namespace std;

class Command {
private:
	string commandWord;
	string secondWord;
    bool validCommand;

public:
    Command();
    Command(string firstWord, string secondWord);
	string getCommandWord();
	string getSecondWord();
    bool isValid();
	bool hasSecondWord();
};

#endif // COMMAND_H
