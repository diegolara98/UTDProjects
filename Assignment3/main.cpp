/* Assignment 4 for CS 2336.002
   Programmer: Diego Lara
   Description:
   <Comments here to describe what the application does>
*/
/*
 * main.cpp
 *
 * The main function calls three other functions. testList, testStack, and testQueue
 *
 * The testList function tests the DoubleLinkedList class.
 * The testStack function tests the Stack class
 * The testQueue function tests the Queue class
 */

#include <iostream>
#include <string>

#include "PhoneBook.h"
#include "DoubleLinkedList.h"
#include "Stack.h"
#include "Queue.h"

//void testPhoneBook();
void testList();
void testStack();
void testQueue();

int main()
{
    //std::cout << "Testing the Phone Book" << std::endl;
    //testPhoneBook();

    std::cout << std::endl;
    std::cout << "Testing the DoubleLinkedList class" << std::endl;
    testList();

    std::cout << std::endl;
    std::cout << "Testing the Stack class" << std::endl;
    testStack();

    std::cout << std::endl;
    std::cout << "Testing the Queue class" << std::endl;
    testQueue();

    return 0;
}

//This will test the DoubleLinkedList
void testList()
{
    std::cout << "DoubleLinkedList" << std::endl;
    DoubleLinkedList<int> list;
    std::cout << std::endl;
    std::cout << "First add items 1, 2, 3, 4 and 5 using push_front()" << std::endl;
    for (auto value: {1, 2, 3, 4, 5})
    {
        std::cout << "push_front()" << std::endl;
        list.push_front(value);// odds are that means that this is is the problem. Need to know why.
    }

    list.debug(std::cout);
    std::cout << std::endl;
    std::cout << "Remove items 5, 4, and 3 using pop_front()" << std::endl;
    for (auto value: {5, 4, 3})
    {
        std::cout << "pop_front() # " << value << std::endl;
        list.pop_front();
    }

    std::cout << "First add items 6, 7, 8 and 9 using push_back()" << std::endl;
    for (auto value: {6, 7, 8, 9})
    {
        std::cout << "push_back()" << std::endl;
        list.push_back(value);
    }


    list.debug(std::cout);

    std::cout << "Try to find entries 2, 4, 6 and 9. Item 4 will not be found." << std::endl;
    for (auto entry: {2, 4, 6, 9})
    {
        auto foundEntry = list.find(entry);
        if (foundEntry == nullptr)
        {
            // entry not found
            std::cout << "Entry " << entry << " was not found" << std::endl;
        }
        else
        {
            // entry found
            std::cout << "Entry " << foundEntry->data() << " was found" << std::endl;
        }
    }

    std::cout << "Remove items 9, and 8 using pop_back()" << std::endl;
    for (auto value: {9, 8})
    {
        std::cout << "pop_back() # " << value << std::endl;
        list.pop_back();
    }

    list.debug(std::cout);

    std::cout << "Use the print() function" << std::endl;
    list.print();

    std::cout << "Add new nodes before existing nodes." << std::endl;
    for (auto value: {6, 2, 7, 3})
    {
        auto findNode = list.find(value);
        if (findNode != nullptr)
        {
            std::cout << "add new node (" << value+10 << ") before " << value << std::endl;
            list.insert_before(findNode, value+10);
        }
        else
        {
            std::cout << "node " << value << " not found" << std::endl;
        }
    }

    list.debug(std::cout);

    std::cout << "Add new nodes after existing nodes." << std::endl;
    for (auto value: {12, 8, 16, 7})
    {
        auto findNode = list.find(value);
        if (findNode != nullptr)
        {
            std::cout << "add new node (" << value+20 << ") after " << value << std::endl;
            list.insert_after(findNode, value+20);
        }
        else
        {
            std::cout << "node " << value << " not found" << std::endl;
        }
    }

    list.debug(std::cout);

    std::cout << "Try to delete nodes 12, 8, 16, and 27." << std::endl;
    for (auto value: {12, 8, 16, 27})
    {
        bool deleted = list.erase(value);
        if (deleted)
        {
            std::cout << "deleted node " << value << std::endl;
        }
        else
        {
            std::cout << "node " << value << " not found" << std::endl;
        }
    }

    list.debug(std::cout);

    std::cout << "make a copy of the list" << std::endl;
    {
        auto list2(list);
        std::cout << "Original list" << std::endl;
        list.debug(std::cout);
        std::cout << "Copy of list" << std::endl;
        list2.debug(std::cout);
    }

    std::cout << "remove all entries" << std::endl;
    while (!list.empty())
    {
        std::cout << "pop_front()" << std::endl;
        list.pop_front();
    }

    list.debug(std::cout);
}

void testStack()
{
    Stack <int>stack;
    std::cout<< "This is a Stack"<<std::endl;
    std::cout << "First add items 1, 2, 3, 4 and 5 using push_front()" << std::endl;
    for (auto value: {1, 2, 3, 4, 5})
    {
        std::cout << "push_front()" << std::endl;
        stack.push(value);// odds are that means that this is is the problem. Need to know why.
    }
    stack.debug(std::cout);

    //The empty member function will return true if the stack is empty.
    if(stack.empty())
    {
        std::cout<<"The Stack is empty"<<std::endl;
    }
    else
        std::cout<<"The Stack is not Empty"<<std::endl;

    //Returns the number of items in the stack.
    std::cout<< "In fact we have exactly: "<< stack.size()<<" entries in the Stack"<<std::endl;

    //Returns a modifiable reference to the top item in the stack. Note, your member function can assume the
    //stack has at least one item or you can throw an exception, the choice is yours.
    std::cout<<"The item is: "<<stack.top()<<std::endl;

    //Returns a const reference to the top item in the stack. Note, your member function can assume the
    //stack has at least one item or you can throw an exception, the choice is yours.
    std::cout<<"The item is: "<<stack.top()<<std::endl;

    //Add a new item to the stack.
    stack.push(50);

    //Remove the top item from the stack.
    stack.pop();
    stack.debug(std::cout);

    //Will make a copy of the satck
    std::cout << "make a copy of the Stack" << std::endl;
    {
        auto stack2(stack);
        std::cout << "Original Stack" << std::endl;
        stack.debug(std::cout);
        std::cout << "Copy of Stack" << std::endl;
        stack2.debug(std::cout);
    }

    //will check to see that I did not ruin this during the copy phase
    std::cout<<"Debug again after pop: "<<std::endl;
    stack.pop();
    stack.debug(std::cout);
    //Call to the destructor
    stack.~Stack();
    stack.debug(std::cout);
}

void testQueue()
{
    Queue<int> queue;
    std::cout<< "This is a Queue"<<std::endl;
    std::cout << "First add items 1, 2, 3, 4 and 5 using push " << std::endl;
    for (auto value: {1, 2, 3, 4, 5})
    {
        std::cout << "push " << std::endl;
        queue.push(value);// odds are that means that this is is the problem. Need to know why.
    }
    queue.debug(std::cout);

    //The empty member function will return true if the stack is empty.
    if(queue.empty())
    {
        std::cout<<"The Queue is empty"<<std::endl;
    }
    else
        std::cout<<"The Queue is not Empty"<<std::endl;

    //Returns the number of items in the queue.
    std::cout<< "In fact we have exactly: "<< queue.size()<<" entries in the Queue"<<std::endl;

    //Returns a modifiable reference to the front item in the queue. Note, your member function can assume the
    //queue has at least one item or you can throw an exception, the choice is yours.
    std::cout<<"The item at the front is: "<<queue.front()<<std::endl;

    //Returns a const reference to the front item in the queue. Note, your member function can assume the
    //queue has at least one item or you can throw an exception, the choice is yours.
    std::cout<<"The item at the front is: "<<queue.front()<<std::endl;

    //Returns a modifiable reference to the back item in the queue. Note, your member function can assume the
    //queue has at least one item or you can throw an exception, the choice is yours.
    std::cout<<"The item at the back is: "<<queue.back()<<std::endl;

    //Returns a const reference to the back item in the queue. Note, your member function can assume the
    //queue has at least one item or you can throw an exception, the choice is yours.
    std::cout<<"The item at the back is: "<<queue.back()<<std::endl;

    //Add a new item to the queue.
    queue.push(50);

    //Remove the front item from the queue.
    queue.pop();
    queue.debug(std::cout);

    std::cout << "make a copy of the Queue" << std::endl;
    {
        auto queue2(queue);
        std::cout << "Original Queue" << std::endl;
        queue.debug(std::cout);
        std::cout << "Copy of Queue" << std::endl;
        queue2.debug(std::cout);
    }

    //Check to see that the Queue is still functional after
    std::cout<<"debug again after pop: "<<std::endl;
    queue.pop();
    queue.debug(std::cout);
    //Call to the destructor
    queue.~Queue();
    queue.debug(std::cout);

}