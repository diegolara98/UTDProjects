/* Assignment 2 for CS 2336.002
   Programmer: Diego Lara
   Description:
   The purpose of the DrinkMachine class is to create an object DrinkMachine. DrinkMachine should contain the following functions:
    Is the default constructor for the DrinkMachine class
    DrinkMachine();

    Is the destructor for the DrinkMachine class
    ~DrinkMachine();

    Returns the size of the Array that holds the DrinkItems
    unsigned int size() const;

    Returns the max size that the Array is; limits the amount of DrinkItems one can create
    unsigned int max_size() const;

    Returns a refrence to DrinkItem in the Array
    DrinkItem& at(unsigned int index);

    Returns a refrence to Drinkitem in the Array
    const DrinkItem& at(unsigned int index) const;

    Returns a truth value as to whether the quantity of DrinkItems's is greater than 0
    bool available (unsigned int drinkId) const;

    Returns the price of the specified DrinkItem
    double getPrice (unsigned int drinkId) const;

    Returns a Receipt if we can purchase the specified item
    Receipt purchase(unsigned int drinkId, double amount);

    Add to the quantity by a specified amount to a specified DrinkItem
    void addDrinks(unsigned int drinkId, unsigned int amount);

    Print out the final fiqures of the process. This is kind of the end game one could say.
    void print(std::ostream& outStream) const;

    Returns the total amount of sales for all DrinkItems
    double sales() const;

    Returns the total amount of sales for one DrinkItem
    double sales(unsigned int drinkId) const;
*/
#include "DrinkMachine.h"
#include "DrinkItem.h"
#include <fstream>
#include <sstream>
#include <iomanip>


DrinkMachine::DrinkMachine() //Create a DrinkMachine that contains an array of DrinkItems that us created from data in a text file
{
    numDrinkItem = 1;
    int privatecount = 0;
    string newline;
    std::ifstream myReadfile;
    std::ofstream myWritefile;
    myReadfile.open("drink.txt");
    myWritefile.open("drink_backup.txt");
    myReadfile >> numDrinkItem; //Get the number at the top of the text file drink.txt out of the way
    string name;
    double price;
    unsigned int quantity;
    myWritefile << numDrinkItem; //Write out the same value to the text file drink_backup.txt
    while (getline(myReadfile, newline)) //Go through the text file as many times as their are lines
    {
        myReadfile >> name >> price >> quantity; //Read in values for name, price, and quantity
        if(privatecount>24)
            break;
        yield[privatecount] = DrinkItem(name, price, quantity); //Create a DrinkItem to be placed in yield at the specified index
        myWritefile << setw(20) << left<< name << "\t" << setw(10) << price << "\t"<< quantity<< endl; //Write information out to the text file drink_backup.txt
        privatecount++;
    }
    myReadfile.close();
    myWritefile.close();
}

DrinkMachine::~DrinkMachine() //Write values to text file drink.txt
{
    int privatecount=0;
    std::ofstream myOutputfile;
    myOutputfile.open("drink.txt");
    while(privatecount<numDrinkItem) //Go through the text file as many times as their are lines
    {
        //The below sends out the information to the text file drink.txt in a formatted version
        myOutputfile << setw(20) << left<< yield[privatecount].getName() << "\t" << setw(10) << yield[privatecount].getPrice() << "\t"<< yield[privatecount].getQuantity()<< endl;
    }
    myOutputfile.close();

}

unsigned int DrinkMachine::size() const //Returns the size of the Array yield
{
    return numDrinkItem;
}

unsigned int DrinkMachine::max_size() const //Returns the maximum possible size of the Array yield
{
    return max;
}

DrinkItem& DrinkMachine::at(unsigned int index)
{
    return yield[index]; //returns a reference to yield at position index
}

const DrinkItem& DrinkMachine::at(unsigned int index) const
{
    return yield[index]; //returns a reference to yield at position index
}

bool DrinkMachine::available(unsigned int drinkId) const //Checks to see whether or not the drink is available
{
    bool value=false;
    if(yield[drinkId].getQuantity()>= 1) //Being available is defined as having a quantity of at least 1 in the DrinkItem
    {
        value=true;
    }
    return value;
}

double DrinkMachine::getPrice(unsigned int drinkId) const //Return the price of the DrinkItem in the specified index
{
    return yield[drinkId].getPrice();
}

Receipt DrinkMachine::purchase(unsigned int drinkId, double amount) //If rep is declared as successful then we purchase a DrinkItem at the specified index
{
    Receipt rep = Receipt(drinkId, amount, yield[drinkId].getQuantity(), yield[drinkId].getPrice());
    if(rep.success())
        yield[drinkId].purchase();
    return rep; //Return the Receipt rep
}

void DrinkMachine::addDrinks(unsigned int drinkId, unsigned int amount) //Add DrinkItem's by a specified amount
{
    int place=drinkId;
    yield[place].addDrinks(amount); //Adds the wanted quantity amount to the DrinkItem in the specified  index yield[place]
}

void DrinkMachine::print(std::ostream &outStream) const //Print out the information in a specified format
{
    const int ID_WIDTH = 6;
    const int NAME_WIDTH = 25;
    const int PRICE_WIDTH = 10;
    const int QTY_WIDTH = 8;

    // make sure the price is output in the format xxxx.xx
    std::cout << std::fixed << std::setprecision(2);
    cout << "Drink Machine Version 1" << endl;
    cout << "Number of Entries: " << numDrinkItem << endl;
    std::cout << std::endl;

    // output some headers, derived this bit from what you did in the driver program
    std::cout << std::setw(ID_WIDTH) << "Id " << " ";
    std::cout << std::left << std::setw(NAME_WIDTH) << "Name" << std::right;
    std::cout << std::setw(PRICE_WIDTH) << "Price $";
    std::cout << std::setw(QTY_WIDTH) << "Qty";
    std::cout << std::setw(8) <<"sales";
    std::cout << std::setw(8) <<"sales $";
    std::cout << std::endl;
    int privatecount=0;
    while(privatecount<=numDrinkItem-1) //All of this is just formatting how we present the information in DrinkItem
    {
        std::cout << std::setw(ID_WIDTH) << privatecount << " " << std::left << std::setw(NAME_WIDTH) << yield[privatecount].getName() << std::right;
        cout << std::setw(PRICE_WIDTH) << yield[privatecount].getPrice()<< std::setw(QTY_WIDTH) << yield[privatecount].getQuantity() << std::setw(8);
        cout << yield[privatecount].getPurchased() << std::setw(8) << sales(privatecount)<< endl;
        privatecount++;
    }
}

double DrinkMachine::sales() const //Return the amount of sales for all DrinkItem's stored in the Array yield
{
    int privatecount=0;
    double totalsales=0.0;
    while(privatecount<numDrinkItem) //Allows me to run through all locations in the yield Array
    {
        totalsales=totalsales + yield[privatecount].getPurchased()*yield[privatecount].getPrice();
        privatecount++;
    }
    return totalsales;
}

double DrinkMachine::sales(unsigned int drinkId) const //Return the amount of sales that took place for a specific DrinkItem
{
    return yield[drinkId].getPrice()*yield[drinkId].getPurchased();
}
