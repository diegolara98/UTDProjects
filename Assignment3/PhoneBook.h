/* Assignment 3 for CS 2336.002
   Programmer: Diego Lara
   Description:
   This is a OrderedLinkedList of the type PhoneBookEntry. Almost everything is using the methods in DoubleLinkedList.
   Extra work had to be placed into the insert method in this class. This required for me to figure out some different
   ways in which to go about organizing a DoubleLinkedList.
 */

#ifndef ASSIGNMENT3_PHONEBOOK_H
#define ASSIGNMENT3_PHONEBOOK_H

#include "PhoneBookEntry.h"
#include "OrderedDoubleLinkedList.h"
#include <iostream>

class PhoneBook
{
private:
    OrderedDoubleLinkedList<PhoneBookEntry> list;
public:
    PhoneBook();
    void insert(const PhoneBookEntry &entry);
    void insert(const std::string &name, const std::string &number, const std::string &email);
    void insert(const std::string &name, const std::string &number);
    bool erase(std::string name);
    bool find(std::string name);
    void print() const;
    std::size_t size() const;
    ListNode<PhoneBookEntry>* first() const;
    ListNode<PhoneBookEntry>* last() const;
    void debug(std::ostream &out) const;
};


#endif //ASSIGNMENT3_PHONEBOOK_H
