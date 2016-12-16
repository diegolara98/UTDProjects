/* Project 4 for CS 2336.002
   Programmer: Diego Lara
   Description:
   This is the Stack class. A stack is similar to a DoubleLinkedList if we were to esseantially work on it backwards.
   It stacks the most recent entries to the top of the list instead of at the back of it. So we implement a DoubleLinkedList
   and use the necessary classes from it to make it happen.
*/

#ifndef ASSIGNMENT3_STACK_H
#define ASSIGNMENT3_STACK_H

#include "DoubleLinkedList.h"
#include <iostream>
#include <iomanip>
#include <cstddef>
#include <assert.h>

template<class DataType>
class Stack
{
private:
    // we are making use of the DoubleLinkedList class
    DoubleLinkedList<DataType> stack;
public:
    Stack();
    Stack(const DoubleLinkedList<DataType> &other);
    ~Stack();
    bool empty() const;
    std::size_t size() const;
    DataType& top();
    const DataType& top() const;
    void push(const DataType& value);
    void pop();
    void debug(std::ostream &out) const;
};
//default constructor
template <class DataType>
Stack<DataType>::Stack()
{
    stack= DoubleLinkedList<DataType>();
}

//copy constructor
template <class DataType>
Stack<DataType>::Stack(const DoubleLinkedList<DataType> &other)
{
    stack.DoubleLinkedList(other);
}

//destructor
template <class DataType>
Stack<DataType>::~Stack()
{
    stack.~DoubleLinkedList();
}

//The empty member function will return true if the stack is empty.
template <class DataType>
bool Stack<DataType>::empty() const
{
    return stack.empty();
}

//Returns the number of items in the stack.
template <class DataType>
std::size_t Stack<DataType>::size() const
{
    return stack.size();
}

//Returns a modifiable reference to the top item in the stack. Note, your member function can assume the
//stack has at least one item or you can throw an exception, the choice is yours.
template <class DataType>
DataType & Stack<DataType>::top()
{
    return stack.first()->data();
}

//Returns a const reference to the top item in the stack. Note, your member function can assume the
//stack has at least one item or you can throw an exception, the choice is yours.
template <class DataType>
const DataType & Stack<DataType>::top() const
{
    return stack.first()->data();
}

//Add a new item to the stack.
template <class DataType>
void Stack<DataType>::push(const DataType &value)
{
    stack.push_front(value);
}

//Remove the top item from the stack.
template <class DataType>
void Stack<DataType>::pop()
{
    stack.pop_front();
}

// note the code for the debug() function is included
// display a debug version of the list
template<class DataType>
void Stack<DataType>::debug(std::ostream &out) const
{
    const unsigned int ADDRWIDTH = 10;
    out << "START DEBUG" << std::endl;
    out << "first  =" << std::setw(ADDRWIDTH) << stack.first();
    out << ", last=" << std::setw(ADDRWIDTH) << stack.last();
    out << ", # nodes=" << size() << std::endl;
    unsigned int count = 1;

    for (auto current=stack.first(); current!= nullptr; current=current->next())
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
#endif //ASSIGNMENT3_STACK_H
