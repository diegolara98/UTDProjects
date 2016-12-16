//
// Created by user on 10/6/2016.
//
#ifndef PROJECT2_DRINKITEM_H
#define PROJECT2_DRINKITEM_H

#include <iostream>
using namespace std;

class drinkitem
{
private:
    string name;
    double price;
    unsigned int quantity;
    unsigned int purchased=0;
    double sales=0;

public:
    //constructors and destructor for drinkitem
    drinkitem();
    drinkitem(string name, double price, int quantity);
    ~drinkitem();

    //Both the accessor and mutator for name
    string getname() const;
    void setname(string newName);

    //Both the accessor and mutator for price
    double getprice() const;
    void setprice(double newPrice);

    //accessor for quantity
    int getquantity() const;

    //accessor for purchased
    int getpurchased() const;

    //accessor for sales
    double getsales() const;

    //to give everything its assigned value

    void addDrinks(unsigned int amount);

    bool purchase();
};


#endif //PROJECT2_DRINKITEM_H
