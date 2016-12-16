/*
* Author: Diego Lara  Due Date: 12/3/16   Name: Project 5
*
* This helps me create a word class that is later placed into the binary tree. We have a value that holds the name of the
* function(for the unscrambling) and the key(which is the sorted and lower case version of value). We will overload operators
* in order to compare the word functions in the different possible ways in order to organize the binary search tree.
*/

#include "Word.h"
#include <algorithm>
Word::Word()
{
    value="";
    skey="";
}

Word::Word(std::string binaryword)
{
    value=binaryword;
    skey=binaryword;
    for(unsigned int i = 0; i < value.length(); ++i)
    {
        skey[i] = tolower(skey[i]);
    }
    std::sort(skey.begin(), skey.end());

}

std::string Word::name() const
{
    return value;
}
std::string Word::searchkey() const
{
    std::string skey1=value;
    for(unsigned int i = 0; i < value.length(); ++i)
    {
        skey1[i] = tolower(skey1[i]);
    }
    std::sort(skey1.begin(), skey1.end());
    return skey1;
}

bool Word::operator==(const Word &other)
{
    if(skey.compare(other.searchkey())==0)//nname==other.name()
        return true;
    else
        return false;
}

bool Word::operator>(const Word &other)
{
    if(skey.compare(other.searchkey())>0)
        return true;
    else
        return false;
}

bool Word::operator<(const Word &other)
{
    if(skey.compare(other.searchkey())<0)//nname<other.name()
        return true;
    else
        return false;
}

bool Word::operator>=(const Word &other)
{
    if(searchkey().compare(other.searchkey())==0)//nname==other.name()
        return true;
    else
        return false;
}

/*bool Word::operator=(const Word &other)
{
    value=other.name();
    return true;
}*/
