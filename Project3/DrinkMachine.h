//
// Created by user on 10/11/2016.
//

#ifndef PROJECT3_DRINKMACHINE_H
#define PROJECT3_DRINKMACHINE_H

#include "DrinkItem.h"
#include "Receipt.h"

class DrinkMachine
{
private:
    unsigned int versionNum=1;
    unsigned int numDrinkItem;
    DrinkItem yield[25];
    unsigned int max=25;

public:
    DrinkMachine();
    ~DrinkMachine();
    unsigned int size() const;
    unsigned int max_size() const;
    DrinkItem& at(unsigned int index);
    const DrinkItem& at(unsigned int index) const;
    bool available (unsigned int drinkId) const;
    double getPrice (unsigned int drinkId) const;
    Receipt purchase(unsigned int drinkId, double amount);
    void addDrinks(unsigned int drinkId, unsigned int amount);
    void print(std::ostream& outStream) const;
    double sales() const;
    double sales(unsigned int drinkId) const;

};


#endif //PROJECT3_DRINKMACHINE_H
