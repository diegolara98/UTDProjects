/* Assignment 2 for CS 2336.002
   Programmer: Diego Lara
   Description:
   The purpose of the DrinkItem class is to create an object DrinkItem. Drink Item should contain the following functions:
    Both the accessor and mutator for name
    string getName() const;               allows for me to get the name of the DrinkItem
    void setName(string newName);         allows for me to change the name of the DrinkItem

    Both the accessor and mutator for price
    double getPrice() const;              allows for me to get the price of the DrinkItem
    void setPrice(double newPrice);       allows for me to change the price of the DrinkItem

    accessor for quantity
    unsigned int getQuantity() const;     allows for me to get the quantity of DrinkItem

    accessor for purchased
    unsigned int getPurchased() const;    allows for me to get the amount purchased of DrinkItem

    accessor for sales
    double getSales() const;              allows for me to get the sales of DrinkItem

    void addDrinks(unsigned int amount);  allows for me to add drinks to DrinkItem
    bool purchase();                      allows for me to buy a DrinkItem and lowers quantity


*/
#include "DrinkItem.h"
#include<iostream>

//constructor
DrinkItem::DrinkItem(string name, double price, unsigned int quantity)// Allows for me to set name, price, and quantity during construction
{
    sales=0;
    purchased=0;
    this->name=name;
    this->price=price;
    this->quantity=quantity;

}

//default constructor
DrinkItem::DrinkItem() //default constructor, sets all values to 0 or for name to ""
{
    sales=0;
    purchased=0;
    price=0.0;
    quantity=0;
    name="";
}

DrinkItem::~DrinkItem()
{

}

string DrinkItem::getName() const //returns the name of the DrinkItem
{
    return name;
}

double DrinkItem::getPrice() const //returns the price of the DrinkItem
{
    return price;
}

unsigned int DrinkItem::getPurchased() const //returns the purchased amount of the DrinkItem
{
    return purchased;
}

unsigned int DrinkItem::getQuantity() const //returns the quantity of the DrinkItem
{
    return quantity;
}

double DrinkItem::getSales() const //returns the sales of DrinkItem
{
    return sales;
}

void DrinkItem::setName(string newName) //sets the name in DrinkItem to newName
{
    name=newName;
}

void DrinkItem::setPrice(double newPrice) //sets the price in DrinkItem to newPrice
{
    price=newPrice;
}

void DrinkItem::addDrinks(unsigned int amount) //allows for me to increment quantity by the value of amount
{
    quantity=quantity+amount;
}

bool DrinkItem::purchase() //when you purchase a DrinkItem we decrease quantity by 1 and increase purchase by one, but only of available is true
{
    bool available=false;
    if(quantity>0)         //will only say that available is true if the DrinkItem has a quantity greater than 0
    {
        available=true;
        quantity=quantity-1;
        purchased++;
    }
    return available;
}



