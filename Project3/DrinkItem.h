//
// Created by user on 10/11/2016.
//

#ifndef PROJECT3_DRINKITEM_H
#define PROJECT3_DRINKITEM_H

#include <iostream>
using namespace std;

class DrinkItem
{
private:
    string name;
    double price;
    unsigned int quantity;
    unsigned int purchased=0;
    double sales=0;

public:
    //constructors and destructor for drinkitem
    DrinkItem();
    DrinkItem(string name, double price,  unsigned int quantity);
    ~DrinkItem();

    //Both the accessor and mutator for name
    string getName() const;
    void setName(string newName);

    //Both the accessor and mutator for price
    double getPrice() const;
    void setPrice(double newPrice);

    //accessor for quantity
    unsigned int getQuantity() const;

    //accessor for purchased
    unsigned int getPurchased() const;

    //accessor for sales
    double getSales() const;

    //to give everything its assigned value

    void addDrinks(unsigned int amount);

    bool purchase();

};


#endif //PROJECT3_DRINKITEM_H
