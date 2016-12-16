/*
 * OrderedDoubleLinkedList.h
 *
 * Store the DataType values in sorted order. This ordering
 * is determined by the comparison operators of the DataType
 * class.
 *
 */

/* Assignment 3 for CS 2336.002
   Programmer: Diego Lara
   Description:
   This is almost the same as the DoubleLinkedList except for the insert method. The insert method required for me to
   check the many different ways in which we can organize the list.
 */

#ifndef ORDEREDDOUBLELINKEDLIST_H_
#define ORDEREDDOUBLELINKEDLIST_H_

#include <cstddef>
#include "DoubleLinkedList.h"

template<class DataType>
class OrderedDoubleLinkedList
{
private:
    // we are making use of the DoubleLinkedList class
    DoubleLinkedList<DataType> list;
public:
    // default constructor
    OrderedDoubleLinkedList();

    // destructor
    virtual ~OrderedDoubleLinkedList();

    // number of items in the list
    std::size_t size() const;

    // is the list empty (true) or does it have entries (false)
    bool empty() const;

    // print the items in the list
    void print() const;

    // display debug information on the passed in ostream
    void debug(std::ostream &out) const;

    // get first node in the list (or nullptr)
    ListNode<DataType>* first() const;

    // get last node in the list (or nullptr)
    ListNode<DataType>* last() const;

    // find the entry and return its address
    // (nullptr if not found)
    ListNode<DataType>* find(const DataType &existingItem);

    // erase the item by DataType value
    bool erase(const DataType &currentItem);

    // insert the new item into the list (in sorted order)
    // a duplicate entry will be ignored
    void insert(const DataType &newItem);
};

// Your implementation code goes here
// default constructor
template <class DataType>
OrderedDoubleLinkedList<DataType>::OrderedDoubleLinkedList()//make a list of DataTypes
{
    list = DoubleLinkedList<DataType>();
}

// destructor
template <class DataType>
OrderedDoubleLinkedList<DataType>::~OrderedDoubleLinkedList()//delete said list
{
    list.~DoubleLinkedList();
}

// number of items in the list
template <class DataType>
std::size_t OrderedDoubleLinkedList<DataType>::size() const//Returns the size of the list
{
    list.size();
}

// is the list empty (true) or does it have entries (false)
template <class DataType>
bool OrderedDoubleLinkedList<DataType>::empty() const//Tells me whether or not the list is empty
{
    list.empty();
}

// print the items in the list
template <class DataType>
void OrderedDoubleLinkedList<DataType>::print() const//prints the list
{
    list.print();
}

// display debug information on the passed in ostream
template <class DataType>
void OrderedDoubleLinkedList<DataType>::debug(std::ostream &out) const//Debugs the list
{
    list.debug(out);
}

// get first node in the list (or nullptr)
template <class DataType>
ListNode<DataType>* OrderedDoubleLinkedList<DataType>::first() const//return the first(pointer)
{
    return list.first();
}

// get last node in the list (or nullptr)
template <class DataType>
ListNode<DataType>* OrderedDoubleLinkedList<DataType>::last() const//return the last(pointer)
{
    return list.last();
}

// find the entry and return its address
// (nullptr if not found)
template <class DataType>
ListNode<DataType>* OrderedDoubleLinkedList<DataType>::find(const DataType &existingItem)//finds the entry that is equal exisitng item
{
    list.find(existingItem);
}

// erase the item by DataType value
template <class DataType>
bool OrderedDoubleLinkedList<DataType>::erase(const DataType &currentItem)//erase the currentItem in list
{
    list.erase(currentItem);
}

// insert the new item into the list (in sorted order)
// a duplicate entry will be ignored
template <class DataType>
void OrderedDoubleLinkedList<DataType>::insert(const DataType &newItem)//insert item in the specified way
{
    bool found=false;
    bool traversedlist=false;
    if(list.empty() && found==false)
    {
        list.push_front(newItem);
        found=true;
        return;
    }
    ListNode<DataType> *current=list.first();; //pointer to traverse the list
    ListNode<DataType> *trailCurrent;
    ListNode<DataType> *newNode;
    newNode=new ListNode<DataType>();
    newNode->data()=newItem;

    while(current!=nullptr && traversedlist==false)
    {
        /*
         * newNode->pNext=current;
                    newNode->pPrevious=temp;
                    if(temp != nullptr)
                        temp->pNext=newNode;
                    current->pPrevious=newNode;
                    if(current==firstNode)
                        firstNode=current->pPrevious;
         */
        ListNode<DataType> *temp= list.first();
        if(newNode->data() == current->data())//if we need to replacre an entry do so
        {
          list.insert_before(current, newItem);
            temp=current;
            current=trailCurrent;
            trailCurrent=trailCurrent->previous();
          list.erase(temp);
           // std::cout<<"here 3"<<std::endl;
            traversedlist=true;
        }
        else if(newNode->data() <= current->data())//works in organizing the list
        {
            list.insert_before(current, newItem);
            traversedlist=true;
        }
        else if(current->next()== nullptr)// works in organizing the list
        {
            list.insert_after(current, newItem);
            traversedlist=true;
        }

           // std::cout<<"also here";
            trailCurrent=current;
            current=current->next();
    }
}
#endif /* ORDEREDDOUBLELINKEDLIST_H_ */