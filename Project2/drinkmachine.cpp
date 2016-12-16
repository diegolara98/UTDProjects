//
// Created by user on 10/6/2016.
//

#include "drinkmachine.h"
#include <fstream>
#include <sstream>

drinkmachine::drinkmachine()
{
    unsigned int count;
    std::string currentline;
    std::ifstream myReadfile;
    myReadfile.open("drink.txt");
    count=10;
    yield[count];
    int currentposition=0;
    ofstream dbackup;
    dbackup.open ("drink_backup.txt");
    dbackup << count << endl;
    count=9;
    cout << count << "like this would seriously make like zero sense" << endl;
    while (getline(myReadfile, currentline))// Runs the loop as many times as there are lines in the input.txt file
    {
        std::string name;
        double price;
        int quantity;
        myReadfile >> name;//passes the operation given in the text file to operationperform
        myReadfile >> price;
        myReadfile >> quantity;
        dbackup << name << "    " << price<< "    " <<quantity << endl;
        drinkitem drink= drinkitem(name, price, quantity);
        yield[currentposition]= drink;
        currentposition++;
        count=currentposition;
        cout<< " do i ever even go through this loop?";
    }
    cout << "left the loop" << count;
    numDrinkItem=count;
}

drinkmachine::~drinkmachine()
{
    int privatecount=0;
    std::ofstream myReadfile;
    myReadfile.open("drink.txt");
    string newline;
    myReadfile.clear();
    myReadfile << numDrinkItem << endl;
    while(privatecount<numDrinkItem)
    {
        myReadfile << "   " << privatecount << "  " << yield[privatecount].getname() << "        " << yield[privatecount].getprice()<< "   " <<yield[privatecount].getpurchased() << "   " <<yield[privatecount].getsales() << endl;
        privatecount++;
    }
    myReadfile.close();
}

unsigned int drinkmachine::size() const
{
    return numDrinkItem;
}

unsigned int drinkmachine::max_size() const
{
    return max;
}

drinkitem& drinkmachine::at(unsigned int index)
{
    return yield[index];
}

const drinkitem& drinkmachine::at(unsigned int index) const
{
    return yield[index];
}

bool drinkmachine::available(unsigned int drinkId) const
{
    bool value=false;
    if(yield[drinkId].getquantity()>= 1)
    {
        value=true;
    }
    return value;
}

double drinkmachine::getPrice(unsigned int drinkId) const
{
    return yield[drinkId].getprice();
}

receipt drinkmachine::purchase(unsigned int drinkId, double amount)
{
    receipt rep = receipt(drinkId, amount, yield[drinkId].getquantity(), yield[drinkId].getprice());
    return rep;
}

void drinkmachine::addDrinks(unsigned int drinkId, unsigned int amount)
{
    int place=drinkId;
    yield[place].addDrinks(amount);
}

void drinkmachine::print(std::ostream &outStream) const
{
    cout << "Drink Machine Version 1" << endl;
    cout << "Number of Entries: " << numDrinkItem << endl;
    cout << endl;
    cout << "   Id" << "  Name"<< "        Price $"<< "    Qty" << "    Sold" << "    Sales $";
    int privatecount=0;
    while(privatecount<=numDrinkItem)
    {
        cout << "   " << privatecount << "  " << yield[privatecount].getname() << "        " << yield[privatecount].getprice()<< "   " <<yield[privatecount].getpurchased() << "   " <<yield[privatecount].getsales() << endl;
        privatecount++;
    }
}

double drinkmachine::sales() const
{
    int privatecount=0;
    double totalsales=0.0;
    while(privatecount<numDrinkItem)
    {
        totalsales=totalsales + yield[privatecount].getsales();
        privatecount++;
    }
    return totalsales;
}

double drinkmachine::sales(unsigned int drinkId) const
{
    return yield[drinkId].getsales();
}