// Assignment 2 for CS 2336.002
// Programmer: Diego Lara
// Description:
// <Comments here to describe what the application does>

#include "drinkitem.h"
#include<fstream>

//constructor
drinkitem::drinkitem(string name, double price, int quantity)
{
    sales=0;
    purchased=0;
    this->name=name;
    this->price=price;
    this->quantity=quantity;

}

//default constructor
drinkitem::drinkitem()
{
    sales=0;
    purchased=0;
    price=0.0;
    quantity=0;
    name="";
}

drinkitem::~drinkitem()
{
}

string drinkitem::getname() const
{
    return name;
}

double drinkitem::getprice() const
{
    return price;
}

int drinkitem::getpurchased() const
{
    return purchased;
}

int drinkitem::getquantity() const
{
    return quantity;
}

double drinkitem::getsales() const
{
    return sales;
}

void drinkitem::setname(string newName)
{
    name=newName;
}

void drinkitem::setprice(double newPrice)
{
    price=newPrice;
}

void drinkitem::addDrinks(unsigned int amount)
{
    quantity=quantity+amount;
}

bool drinkitem::purchase()
{
    /*std::ifstream myReadfile;
    myReadfile.open("drink.txt");
    std::string currentval;
    getline(myReadfile, currentval);
    std::string nameofdrink;
    name=nameofdrink;
    myReadfile >> nameofdrink;
    double priceofdrink;
    myReadfile >> priceofdrink;
    int quantityofdrink;
    quantity=quantityofdrink;
    myReadfile >> quantityofdrink;
    name=nameofdrink;*/

    bool available=false;
    if(quantity>0)
    {
        available=true;
        quantity=quantity-1;
        purchased++;
    }
    return available;
}


