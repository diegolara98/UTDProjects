/* Assignment 3 for CS 2336.002
   Programmer: Diego Lara
   Description:
   This is the Header file for the PhoneBookEntry which is a type of possible DataTypes. We essentially give ourselves a
   way to manipulate to the PhoneBookEntry and give ourselves a way to maipulate the data. We also overload all of the
   operators here. This way we can compare the PhoneBookEntry types.
 */

#ifndef ASSIGNMENT3_PHONEBOOKENTRY_H
#define ASSIGNMENT3_PHONEBOOKENTRY_H
#include "OrderedDoubleLinkedList.h"
#include <iostream>
#include <iostream>
#include <iomanip>
#include <cstddef>

class PhoneBookEntry
{
public:
    std::string nname;
    std::string eemail;
    std::string nnumber;
    PhoneBookEntry();
    PhoneBookEntry(const std::string &name, const std::string &number);
    PhoneBookEntry(const std::string &name, const std::string &number, const std::string &email);
    PhoneBookEntry(const PhoneBookEntry &copyFrom);
    std::string name() const;
    std::string phoneNumber() const;
    std::string email() const;
    void phoneNumber(const std::string &newNumber);
    void email(const std::string &newEmail);
    bool operator==(const PhoneBookEntry &other);
    bool operator!=(const PhoneBookEntry &other);
    bool operator>=(const PhoneBookEntry &other);
    bool operator>(const PhoneBookEntry &other);
    bool operator<=(const PhoneBookEntry &other);
    bool operator<(const PhoneBookEntry &other);
};

inline std::ostream& operator<<(std::ostream &out, const PhoneBookEntry &entry)
{
    return out<< entry.name() << entry.email() << entry.phoneNumber();
};

#endif //ASSIGNMENT3_PHONEBOOKENTRY_H
