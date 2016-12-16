//
// Created by user on 10/25/2016.
//
/*
#include <cstddef>
#include "OrderedDoubleLinkedList.h"
#include "DoubleLinkedList.h"
#include <iostream>
#include <iomanip>
#include <cstddef>



// default constructor
template <class DataType>
OrderedDoubleLinkedList<DataType>::OrderedDoubleLinkedList()
{
    list = DoubleLinkedList<DataType>();
}

// destructor
template <class DataType>
OrderedDoubleLinkedList<DataType>::~OrderedDoubleLinkedList()
{
    list.~DoubleLinkedList();
}

// number of items in the list
template <class DataType>
std::size_t OrderedDoubleLinkedList<DataType>::size() const
{
    list.size();
}

// is the list empty (true) or does it have entries (false)
template <class DataType>
bool OrderedDoubleLinkedList<DataType>::empty() const
{
    list.empty();
}

// print the items in the list
template <class DataType>
void OrderedDoubleLinkedList<DataType>::print() const
{
    list.print();
}

// display debug information on the passed in ostream
template <class DataType>
void OrderedDoubleLinkedList<DataType>::debug(std::ostream &out) const
{
    list.debug(out);
}

// get first node in the list (or nullptr)
template <class DataType>
ListNode<DataType>* OrderedDoubleLinkedList<DataType>::first() const
{
    return list.first();
}

// get last node in the list (or nullptr)
template <class DataType>
ListNode<DataType>* OrderedDoubleLinkedList<DataType>::last() const
{
    return list.last();
}

// find the entry and return its address
// (nullptr if not found)
template <class DataType>
ListNode<DataType>* OrderedDoubleLinkedList<DataType>::find(const DataType &existingItem)
{
    list.find(existingItem);
}

// erase the item by DataType value
template <class DataType>
bool OrderedDoubleLinkedList<DataType>::erase(const DataType &currentItem)
{
    list.erase(currentItem);
}

// insert the new item into the list (in sorted order)
// a duplicate entry will be ignored
template <class DataType>
void OrderedDoubleLinkedList<DataType>::insert(const DataType &newItem)
{
    list.insert_after(newItem, list);
}
 */