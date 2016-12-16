/*
* Author: Diego Lara  Due Date: 12/3/16   Name: Project 5
*
* This is the program that tests the Binary Search Tree. We will test all the functionality in the Binary Search Tree.
* It will be a Binary Search Tree of the type Word. This will be a really long program to write tbh.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "Word.h"
#include "BinarySearchTree.h"

//This is called to perform the necessary tests on the Binary Search Tree
void testBinarysearchtree();

int main()
{
    testBinarysearchtree();
}

void testBinarysearchtree()
{
    BinarySearchTree<Word> english;
    std::string currentlined;
    std::ifstream dictionary;
    dictionary.open("english_words.txt");//going to be used to create the binary search tree


    // Runs the loop as many times as there are lines in the input.txt file
    while (getline(dictionary, currentlined))
    {
        Word nextinline(currentlined);
        english.insert(nextinline);//This should create a BinarySearchTree entry
    }


    //At this point I should have a fully qualified Binary Search Tree
    //Next I will begin to test all of the necessary functionality to ensure that the functions work as specified
    std::cout << "The size of the Binary Seach Tree is: " << english.size() << std::endl;
    english.debug(std::cout);

    //In this segment we will allow for the user to search for an entry by entering in what will become a key
    std:: string theirchoice;
    std::cout<<"If you want to search for some item by key enter y"<<std::endl;
    std::cin>>theirchoice;
    while(theirchoice=="y")
    {
        std::string uword;
        std::cout << "Enter in a key for the word you are looking for" << std::endl;
        std::cin >> uword;
        const Word userword(uword);
        english.find(userword, &english.processFound);
        std::cout<<"Search again? Enter y"<<std::endl;
        std::cin>>theirchoice;
    }


    //This will allow for you to search based on the scrambled_words.txt if you want
    std:: string scrambled;
    std::cout<<"If you want to search for items from scrambled enter y"<<std::endl;
    std::cin>>scrambled;
    while(scrambled=="y")
    {
        std::ifstream scrambledwords;
        scrambledwords.open("scrambled_words.txt");//going to be used to create the binary search tree
        while (getline(scrambledwords, scrambled))
        {
            Word fscrambled(scrambled);
            english.find(fscrambled, &english.processFound);
        }
        scrambled="n";
    }


    //This segment will allow for the user to insert something if they want to
    std::string winsert;
    std::cout<<"If you want to insert enter y"<<std::endl;
    std::cin >> winsert;
    while(winsert=="y")
    {
        std::string uinsert;
        std::cout << "Enter in a word you want added to the tree" << std::endl;
        std::cin >> uinsert;
        const Word userinsert(uinsert);
        english.insert(userinsert);
        std::cout<<"Insert again? Enter y"<<std::endl;
        std::cin>>winsert;
    }


    //This segment will allow for the user to remove something if they want to
    std::string werase;
    std::cout<<"If you want to erase enter y"<<std::endl;
    std::cin >> werase;
    while(werase=="y")
    {
        std::string uerase;
        std::cout << "Enter in a word you want erased from the tree" << std::endl;
        std::cin >> uerase;
        const Word usererase(uerase);
        english.erase(usererase);
        std::cout<<"Erase again? Enter y"<<std::endl;
        std::cin>>werase;
    }


    //This section prints the entire tree if you want to
    //It takes a while because it is really large binary search tree
    //This is showing that the traverse works through printing while traversing
    std::string wprint;
    std::cout<<"If you want to print enter y"<<std::endl;
    std::cin >> wprint;
    while(wprint=="y")
    {
        english.traverse(&english.processFound);
        wprint="no";
    }


    //When it finishes traversing we can test out print really quickly
    english.print();


    //Now we can erase absolutely everything
    english.~BinarySearchTree();

    //english.debug(std::cout);
    //This will prove that nothing is left
    english.print();
}

