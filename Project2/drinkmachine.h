//
// Created by user on 10/6/2016.
//

#ifndef PROJECT2_DRINKMACHINE_H
#define PROJECT2_DRINKMACHINE_H


#include "drinkitem.h"
#include "receipt.h"

class drinkmachine
{
private:
    unsigned int versionNum=1;
    unsigned int numDrinkItem;
    drinkitem yield[];
    unsigned int max=25;

public:
    drinkmachine();
    ~drinkmachine();
    unsigned int size() const;
    unsigned int max_size() const;
    drinkitem& at(unsigned int index);
    const drinkitem& at(unsigned int index) const;
    bool available (unsigned int drinkId) const;
    double getPrice (unsigned int drinkId) const;
    receipt purchase(unsigned int drinkId, double amount);
    void addDrinks(unsigned int drinkId, unsigned int amount);
    void print(std::ostream& outStream) const;
    double sales() const;
    double sales(unsigned int drinkId) const;
};


#endif //PROJECT2_DRINKMACHINE_H
