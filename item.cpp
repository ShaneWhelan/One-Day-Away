#include "item.h"

Item::Item(){

}

Item::Item (string name, string hint, int weightInGrams, int loudness) {
    this->name = name;
    this->hint = hint;
    setWeight(weightInGrams);
    this->loudness = loudness;
}

string Item::getItemName(){
    return name;
}

string Item::getHint(){
    return hint;
}

int Item::getWeight(){
    return weightInGrams;
}

bool Item::setWeight(int weightInGrams) {
    if (weightInGrams < 0){
       return false;
    }else{
       this->weightInGrams = weightInGrams;
       return true;
    }
}

int Item::getLoudness(){
    return loudness;
}
