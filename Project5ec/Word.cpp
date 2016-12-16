/*
* Author: Diego Lara  Due Date: 12/3/16   Name: Project 5
* This helps me create a word class that is later placed into the binary tree. We have a value that holds the name of the
* function(for the unscrambling) and the key(which is the sorted and lower case version of value). We will overload operators
* in order to compare the word functions in the different possible ways in order to organize the binary search tree. This
 * version has a modification in the form of a type vector that in some cases allows for us to hold multiple words if they have
 * the same key.
*
*/
#include "Word.h"
#include <algorithm>
Word::Word()//default constructor
{
    value.push_back("");
    skey="";
}

Word::Word(std::string binaryword)//copy constructor
{
    value.push_back(binaryword);
    skey=binaryword;
    for(unsigned int i = 0; i < value[0].length(); ++i)
    {
        skey[i] = tolower(skey[i]);
    }
    std::sort(skey.begin(), skey.end());

}

std::string Word::name() const//gets the type name for the word
{
    int count=0;
    std::string name1="";
    while(count<value.size())
    {
        name1 = name1+" " + value[count];
        count++;
    }
    return name1;
}

std::string Word::name1() const//gets nothing
{
    return "";
}

std::string Word::searchkey() const//gets the key for the word
{
    std::string skey1=value[0];
    for(unsigned int i = 0; i < value[0].length(); ++i)
    {
        skey1[i] = tolower(skey1[i]);
    }
    std::sort(skey1.begin(), skey1.end());
    return skey1;
}

bool Word::operator==(const Word &other)//compares to see if the keys are equal
{
    if(skey.compare(other.searchkey())==0)//nname==other.name()
        return true;
    else
        return false;
}

bool Word::operator>(const Word &other)//checks to see if this key is greater
{
    if(skey.compare(other.searchkey())>0)
        return true;
    else
        return false;
}

bool Word::operator<(const Word &other)//checks to see if other key is larger
{
    if(skey.compare(other.searchkey())<0)//nname<other.name()
        return true;
    else
        return false;
}

bool Word::operator>=(const Word &other)//checks to see if the keys are the same
{
    if(searchkey().compare(other.searchkey())==0)//nname==other.name()
        return true;
    else
        return false;
}

bool Word::operator<=(const Word &other)//add to, used to update
{
    value.push_back(other.name());
}


