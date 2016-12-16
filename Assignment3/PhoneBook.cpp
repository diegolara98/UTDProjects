/* Assignment 3 for CS 2336.002
   Programmer: Diego Lara
   Description:
   This is a OrderedLinkedList of the type PhoneBookEntry. Almost everything is using the methods in DoubleLinkedList.
   Extra work had to be placed into the insert method in this class. This required for me to figure out some different
   ways in which to go about organizing a DoubleLinkedList.
 */
#include "PhoneBook.h"
#include "OrderedDoubleLinkedList.h"
#include "DoubleLinkedList.h"

PhoneBook::PhoneBook()//create a PhoneBook
{
    list = OrderedDoubleLinkedList<PhoneBookEntry>();
}
void PhoneBook::insert(const PhoneBookEntry &entry)//Insert a entry into list
{
    list.insert(entry);
}


void PhoneBook::insert(const std::string &name, const std::string &number, const std::string &email)//Create and insert a PhoneBookEntry into list
{
    list.insert(PhoneBookEntry(name, number, email));
}


void PhoneBook::insert(const std::string &name, const std::string &number)//Create and insert a PhoneBookEntry into list
{
    list.insert(PhoneBookEntry(name, number));
}


bool PhoneBook::erase(std::string name)//erase a specified PhoneBookEntry that matches name
{
    if (list.find(PhoneBookEntry(name,""))) {
        list.erase(PhoneBookEntry(name, ""));
        return true;
    }
    else
        return false;
}

bool PhoneBook::find(std::string name)//finds the PhoneBookEntry that is equal to that with name
{
    PhoneBookEntry entry=PhoneBookEntry(name,"");
    return(list.find(entry)!=nullptr);
}

void PhoneBook::print() const//Prints list
{
    list.print();
}

std::size_t PhoneBook::size() const//Returns the size of the list
{
    list.size();
}

ListNode<PhoneBookEntry>* PhoneBook::first() const//Returns the first item in list (by pointer)
{
    return list.first();
}

ListNode<PhoneBookEntry>* PhoneBook::last() const//Returns the last item in list (by pointer)
{
    return list.last();
}

void PhoneBook::debug(std::ostream &out) const//Runs debug on list
{
    list.debug(out);
}
