#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

class Item {
private:
    string name;
    string hint;
    int weightInGrams;
    int loudness;

public:
    Item();
    Item (string name, string hint, int inWeight, int loudness);
    string getItemName();
    string getHint();
	int getWeight();
    bool setWeight(int weightInGrams);
    int getLoudness();
};

#endif // ITEM_H
