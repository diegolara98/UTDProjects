/* Assignment 2 for CS 2336.002
   Programmer: Diego Lara
   Description:
    Is the constructor for the Receipt class
    Receipt(unsigned int drinkId, double amount, int quantity, double currprice);

    Checks whether or not we can purchase a DrinkItem
    bool success() const;

    Checks to see if you have enough money for the selected DrinkItem
    bool insufficient() const;

    Checks to see if their is any of the specified DrinkItem left
    bool empty() const;

    Calculates the change after a purchase
    double getChange() const;
*/
#include "Receipt.h"

Receipt::Receipt(unsigned int drinkId, double amount, int quantity, double currprice) //Assigns values that are needed to successfully use this class
{
    Id=drinkId;
    totalmoney=amount;
    quant=quantity;
    price=currprice;
    getChange(); //Only chance to ever call this function, has to happen during construction
}

bool Receipt::empty() const //Checks if their is no more of the specified DrinkItem left. Returns true if so.
{
    bool value=false;
    if (quant==0)
        value=true;
    return value;
}

double Receipt::getChange() const //Calculates the change after the purchase. Returns the change.
{
    double change;
    if(success())
        change=totalmoney-price;
    else
        change=0.0;
    return change;
}

bool Receipt::insufficient() const //Checks to see if you have a enough money to purchase the DrinkItem. Returns false if so.
{
    bool value=false;
    if(price>totalmoney)
        value=true;
    return value;
}

bool Receipt::success() const //If you can make the purchase than success returns true.
{
    bool value=false;
    if (!insufficient() && !empty())
        value=true;
    return value;
}