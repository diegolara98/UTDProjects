/* Project 4 for CS 2336.002
   Programmer: Diego Lara
   Description:
   This is the Queue class. A Queue is similar to a DoubleLinkedList if we were to essentially work on it going foward.
   It queue's up the most recent entries to the front of the list instead of at the back of it. So we implement a
   DoubleLinkedList and use the necessary classes from it to make it happen.
*/

#ifndef ASSIGNMENT3_QUEUE_H
#define ASSIGNMENT3_QUEUE_H

#include "DoubleLinkedList.h"
#include <iostream>
#include <iomanip>
#include <cstddef>
#include <assert.h>

template<class DataType>
class Queue
{
private:
    DoubleLinkedList<DataType> queue;
public:
    Queue();
    Queue(const DoubleLinkedList<DataType> &other);
    ~Queue();
    bool empty() const;
    DataType& front();
    const DataType& front() const;
    DataType& back();
    const DataType& back() const;
    void push(const DataType& value);
    void pop();
    std::size_t size() const;
    void debug(std::ostream &out) const;
};

template <class DataType>
Queue<DataType>::Queue()
{
    queue = DoubleLinkedList<DataType>();
}

template <class DataType>
Queue<DataType>::Queue(const DoubleLinkedList<DataType> &other)
{
    queue.DoubleLinkedList(other);
}
template <class DataType>
Queue<DataType>::~Queue()
{
    queue.~DoubleLinkedList();
}

//The empty member function will return true if the queue is empty.
template <class DataType>
bool Queue<DataType>::empty() const
{
    queue.empty();
}

//Returns the number of items in the queue.
template <class DataType>
DataType & Queue<DataType>::front()
{
    return queue.first()->data();
}

//Returns a modifiable reference to the first item in the queue. Note, your member function can assume
//the queue has at least one item or you can throw an exception, the choice is yours.
template <class DataType>
const DataType & Queue<DataType>::front() const
{
    return queue.first()->data();
}

//Returns a modifiable reference to the first item in the queue. Note, your member function can assume
//the queue has at least one item or you can throw an exception, the choice is yours.
template <class DataType>
DataType & Queue<DataType>::back()
{
    return queue.last()->data();
}

//Returns a modifiable reference to the last item in the queue. Note, your member function can assume
//the queue has at least one item or you can throw an exception, the choice is yours.

template <class DataType>
const DataType & Queue<DataType>::back() const
{
    return queue.last()->data();
}

//Add a new item to the back of the queue.
template <class DataType>
void Queue<DataType>::push(const DataType &value)
{
    queue.push_back(value);
}

//Remove the first item from the queue.
template <class DataType>
void Queue<DataType>::pop()
{
    queue.pop_front();
}

//Returns the number of items in the stack.
template <class DataType>
std::size_t Queue<DataType>::size() const
{
    return queue.size();
}

// note the code for the debug() function is included
// display a debug version of the list
template<class DataType>
void Queue<DataType>::debug(std::ostream &out) const
{
    const unsigned int ADDRWIDTH = 10;
    out << "START DEBUG" << std::endl;
    out << "first  =" << std::setw(ADDRWIDTH) << queue.first();
    out << ", last=" << std::setw(ADDRWIDTH) << queue.last();
    out << ", # nodes=" << size() << std::endl;
    unsigned int count = 1;

    for (auto current=queue.first(); current!= nullptr; current=current->next())
    {
        out << "node " << std::setw(2) << count << std::endl;
        out << "=" << std::setw(ADDRWIDTH) << current << std::endl;
        out << ", next=" << std::setw(ADDRWIDTH)
            << current->next() << std::endl;
        out << ", previous=" << std::setw(ADDRWIDTH)
            << current->previous() << std::endl;
        out << ", value=" << current->data() << std::endl;
        count++;
    }
    out << "END DEBUG" << std::endl;
}
#endif //ASSIGNMENT3_QUEUE_H
