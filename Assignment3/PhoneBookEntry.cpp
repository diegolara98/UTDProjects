/* Assignment 3 for CS 2336.002
   Programmer: Diego Lara
   Description:
   This is the PhoneBookEntry class that is a type of DataType in theory. It is used to create the PhoneBook class later.
   We overload operators here in order to be able to compare different PhoneBookEntry's.
 */

#include "PhoneBookEntry.h"
#include <iostream>
#include <iomanip>
#include <cstddef>


PhoneBookEntry::PhoneBookEntry()//construct PhoneBookEntry
{
     nname="";
     eemail="";
     nnumber="";
}


PhoneBookEntry::PhoneBookEntry(const std::string &name, const std::string &number)//construct PhoneBookEntry given name,number
{
    nname=name;
    nnumber=number;
    eemail="";
}


PhoneBookEntry::PhoneBookEntry(const std::string &name, const std::string &number, const std::string &email)//construct PhoneBookEntry name,number,email
{
    nname=name;
    eemail=email;
    nnumber=number;
}


PhoneBookEntry::PhoneBookEntry(const PhoneBookEntry &copyFrom)//construct PhoneBookEntry copyFrom
{
    nname=copyFrom.name();
    eemail=copyFrom.email();
    nnumber=copyFrom.phoneNumber();
}

std::string PhoneBookEntry::name() const//return name
{
    return nname;
}

std::string PhoneBookEntry::phoneNumber() const//return number
{
    return nnumber;
}


std::string PhoneBookEntry::email() const//return email
{
    return eemail;
}


void PhoneBookEntry::phoneNumber(const std::string &newNumber)//set number
{
    nnumber=newNumber;
}


void PhoneBookEntry::email(const std::string &newEmail)//set email
{
    eemail=newEmail;
}
//Finally you need to overload the operators ==, !=, <, <=, > and >= for the PhoneBookEntry class
bool PhoneBookEntry::operator==(const PhoneBookEntry &other)
{
    if(nname.compare(other.name())==0)//nname==other.name()
        return true;
    else
        return false;
}

bool PhoneBookEntry::operator!=(const PhoneBookEntry &other)
{
    if(nname.compare(other.name())!=0)//nname!=other.name()
        return true;
    else
        return false;
}

bool PhoneBookEntry::operator<(const PhoneBookEntry &other)
{
    if(nname.compare(other.name())<0)//nname<other.name()
        return true;
    else
        return false;
}

bool PhoneBookEntry::operator<=(const PhoneBookEntry &other)
{
    if(nname.compare(other.name())<=0)//nname<=other.name()
        return true;
    else
        return false;
}

bool PhoneBookEntry::operator>(const PhoneBookEntry &other)
{
    if(nname.compare(other.name())>0)//nname>other.name()
        return true;
    else
        return false;
}

bool PhoneBookEntry::operator>=(const PhoneBookEntry &other)
{
    if(nname.compare(other.name())>=0)//nname>=other.name()
        return true;
    else
        return false;
}
