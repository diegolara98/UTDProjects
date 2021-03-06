/*
* Author: Diego Lara  Due Date: 12/3/16   Name: Project 5
* This helps me create a word class that is later placed into the binary tree. We have a value that holds the name of the
* function(for the unscrambling) and the key(which is the sorted and lower case version of value). We will overload operators
* in order to compare the word functions in the different possible ways in order to organize the binary search tree. This
 * is just simply the header file for it.
*
*/

#ifndef PROJECT5EC_WORD_H
#define PROJECT5EC_WORD_H

//#include "BinarySearchTree.h"
#include <iostream>
#include <iostream>
#include <iomanip>
#include <cstddef>
#include <string>
#include <vector>

class Word
{
private:
    std::string skey;
    std::vector<std::string> value;
    //std::string value;
public:
    Word();
    Word(std::string binaryword);
    std::string name() const;
    std::string name1() const;
    std::string searchkey() const;
    bool operator==(const Word &other);
    bool operator<(const Word &other);
    bool operator>(const Word &other);
    bool operator>=(const Word &other);
    bool operator<=(const Word &other);
};


inline std::ostream& operator<<(std::ostream &out, const Word outputWord)
{
    return out<< "The words are: " << outputWord.name() << "  The key is:" <<outputWord.searchkey() << std::endl;
};

#endif //PROJECT5EC_WORD_H