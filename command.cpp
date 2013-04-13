#include "command.h"

Command::Command(){

}

Command::Command(string firstWord, string secondWord) {
	this->commandWord = firstWord;
    this->secondWord = secondWord;
    CommandWords checkCommand;
    this->validCommand = checkCommand.isCommand(commandWord);
}

string Command::getCommandWord() {
	return this->commandWord;
}

string Command::getSecondWord() {
	return this->secondWord;
}

bool Command::isValid() {
    return this->validCommand;
}

bool Command::hasSecondWord() {
	return (!secondWord.empty());
}

