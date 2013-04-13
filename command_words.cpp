#include "command_words.h"

vector<string> CommandWords::validCommands;

CommandWords::CommandWords() {
	// Populate the vector if we haven't already.
	if (validCommands.empty()) {
		validCommands.push_back("go");
		validCommands.push_back("quit");
		validCommands.push_back("info");
		validCommands.push_back("map");
		validCommands.push_back("take");
        validCommands.push_back("drop");
        validCommands.push_back("inventory");
	}
}

bool CommandWords::isCommand(string userString) {
	for (unsigned int i = 0; i < validCommands.size(); i++)	{
        if (validCommands[i].compare(userString) == 0)
			return true;
	}
	// if we get here, the string was not found in the commands
	return false;
}

/*
 * Return a stirng with all the valid commands separatedby a space.
 */
string CommandWords::getCommandList() {
    //Loops through validCommands and returns a string.
    string commandList;
	for (unsigned int i = 0; i < validCommands.size(); i++)	{
        commandList += validCommands[i] + " ";
	}
    return commandList;
}
