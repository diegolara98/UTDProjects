/*
 * BaseDoubleLinkedList.h
 *
 * Implementation of a double linked list.
 *
 * We have the ability to get the first and last entries and navigate
 * through the entries in the linked list.
 *
 * There are actually two classes here:
 *
 * ListNode<DataType>
 *
 * and
 *
 * DoubleLinkedList<DataType>
 *
 */

/*
#include <iostream>
#include <iomanip>
#include <cstddef>
#include <assert.h>
#include "DoubleLinkedList.h"

// default constructor
template<class DataType>
ListNode<DataType>::ListNode()
{
    dataType=NULL;
    pPrevious=nullptr;
    pNext=nullptr;
}

// copy constructor
template<class DataType>
ListNode<DataType>::ListNode(const DataType &newItem)
{
    dataType= newItem;
    pPrevious=nullptr;
    pNext=nullptr;
}

// get the next node
template<class DataType>
ListNode<DataType>* ListNode<DataType>:: next() const
{
    return pNext;
}

// get the previous node
template<class DataType>
ListNode<DataType>* ListNode<DataType>::previous() const
{
    return pPrevious;
}

// return the data stored in the node as a const
template<class DataType>
const DataType& ListNode<DataType>:: data() const
{
    return dataType;
}

// return the data stored in the node
template<class DataType>
DataType& ListNode<DataType>::data()
{
    return dataType;
}




    // default constructor
    template <class DataType>
    DoubleLinkedList<DataType>::DoubleLinkedList()
    {
        numberNodes=0;
        firstNode  = new ListNode<DataType>();
        lastNode = new ListNode<DataType>();
    }

    // copy constructor
    template <class DataType>
    DoubleLinkedList<DataType>::DoubleLinkedList(const DoubleLinkedList &other)
    {
        firstNode= new ListNode<DataType>();
        lastNode= new ListNode<DataType>();
    }

    // destructor
    template <class DataType>
    DoubleLinkedList<DataType>::~DoubleLinkedList()
    {
        ListNode<DataType> *temp; //pointer to delete the node
        while (firstNode != nullptr)
        {
            temp = firstNode;
            firstNode = firstNode->next();
            delete temp;
        }
        lastNode = nullptr;
        numberNodes = 0;
    }

    // return the number of nodes in the list
    template <class DataType>
    std::size_t DoubleLinkedList<DataType>::size() const
    {
        return numberNodes;
    }

    // return true if the list is empty
    template <class DataType>
    bool DoubleLinkedList<DataType>::empty() const
    {
        if(numberNodes==0)
            return true;
        else
            return false;
    }

    // display the contents of the list to std::cout
    template <class DataType>
    void DoubleLinkedList<DataType>::print() const
    {
        ListNode<DataType> *current; //pointer to traverse the list
        current = firstNode; //set current to point to the first node
        while (current != nullptr)
        {
            std::cout << current -> dataType << " "; //output info
            current = current-> pNext;
        }//end while
    }

    // first node in the list (or nullptr for empty)
    template <class DataType>
    ListNode<DataType>* DoubleLinkedList<DataType>::first() const
    {
        if(firstNode != nullptr)
            return firstNode -> dataType;
        else
            return nullptr;
    }

    // last node in the list (or nullptr for empty)
    template <class DataType>
    ListNode<DataType>* DoubleLinkedList<DataType>::last() const
    {
        if(lastNode != nullptr)
            return lastNode -> dataType;
        else
            return nullptr;
    }








    // add an item to the front of the list
    template <class DataType>
    void DoubleLinkedList<DataType>::push_front(const DataType &newItem)
    {
        ListNode<DataType> *current; //pointer to traverse the list
        ListNode<DataType> *trailCurrent; //pointer just before current
        ListNode<DataType> *newNode; //pointer to create a node
        bool found;
        newNode = new ListNode<DataType>; //create the node
        newNode->dataType = newItem; //store the new item in the node
        newNode->pNext = nullptr;
        newNode->pPrevious = nullptr;
        if (first == nullptr) //if the list is empty, newNode is
            //the only node
        {
            firstNode = newNode;
            lastNode = newNode;
            numberNodes++;
        }
        else
        {
            found = false;
            current = firstNode;
            while (current != nullptr && !found) //search the list
                if (current->dataType >= newItem)
                    found = true;
                else
                {
                    trailCurrent = current;
                    current = current->pNext;
                }
            if (current == first) //insert newNode before first
            {
                firstNode->pPrevious = newNode;
                newNode->pNext = firstNode;
                firstNode = newNode;
                numberNodes++;
            }
        }
    }

    // add an item to the back of the list
    template <class DataType>
    void DoubleLinkedList<DataType>::push_back(const DataType &newItem)
    {
        ListNode<DataType> *current; //pointer to traverse the list
        ListNode<DataType> *trailCurrent; //pointer just before current
        ListNode<DataType> *newNode; //pointer to create a node
        bool found;
        newNode = new ListNode<DataType>; //create the node
        newNode -> dataType = newItem; //store the new item in the node
        newNode -> pNext = nullptr;
        newNode -> pPrevious = nullptr;
        if (first == nullptr) //if the list is empty, newNode is
            //the only node
        {
            firstNode = newNode;
            lastNode = newNode;
            numberNodes++;
        }
        else
        {
            found = false;
            current = firstNode;
            while (current != nullptr && !found) //search the list
                if (current->dataType >= newItem)
                    found = true;
                else
                {
                    trailCurrent = current;
                    current = current->pNext;
                }
            trailCurrent -> pNext = newNode;
            newNode -> pPrevious = trailCurrent;
            lastNode = newNode;
            numberNodes++;
        }
    }//end


    // remove an item from the front of the list
    template <class DataType>
    void DoubleLinkedList<DataType>::pop_front()
    {
        assert(firstNode != nullptr);
        bool found = false;
        ListNode<DataType> *trailCurrent; //pointer just before current
        ListNode<DataType> *current; //pointer to traverse the list
        current = firstNode;
        while (current != nullptr && !found)
        {
            if (current->dataType >= firstNode)
                found = true;
            else
            {
                trailCurrent= current;
                current = current->next();
            }
        }
        if(found)
        {
            trailCurrent = current->previous();
            trailCurrent -> pNext = current -> next();
            if (current -> next() != nullptr)
                current -> pNext = trailCurrent;
            if (current == lastNode)
                lastNode = trailCurrent;
            numberNodes--;
            delete current;
        }
    }

    // remove an item from the back of the list
    template <class DataType>
    void DoubleLinkedList<DataType>::pop_back()
    {
        assert(lastNode != nullptr);
        bool found = false;
        ListNode<DataType> *trailCurrent; //pointer just before current
        ListNode<DataType> *current; //pointer to traverse the list
        current = lastNode;
        while (current != nullptr && !found)
        {
            if (current->dataType >= lastNode)
                found = true;
            else
            {
                trailCurrent= current;
                current = current->next();
            }
        }
        if(found)
        {
            trailCurrent = current->previous();
            trailCurrent -> pNext = current -> next();
            if (current -> next() != nullptr)
                current -> pNext = trailCurrent;
            if (current == lastNode)
                lastNode = trailCurrent;
            numberNodes--;
            delete current;
        }
    }

    // insert newItem before the existingNode
    template <class DataType>
    void DoubleLinkedList<DataType>::insert_before (ListNode<DataType>* existingNode, const DataType &newItem)
    {
        ListNode<DataType> *current; //pointer to traverse the list
        ListNode<DataType> *trailCurrent; //pointer just before current
        ListNode<DataType> *newNode; //pointer to create a node
        bool found;
        newNode = new ListNode<DataType>; //create the node
        newNode -> dataType = newItem; //store the new item in the node
        newNode -> pNext = nullptr;
        newNode -> pPrevious = nullptr;
        if (first == nullptr) //if the list is empty, newNode is
            //the only node
        {
            firstNode = newNode;
            lastNode = newNode;
            numberNodes++;
        }
        else
        {
            found = false;
            current = firstNode;
            while (current != nullptr && !found) //search the list
                if (current->dataType >= newItem)
                    found = true;
                else
                {
                    trailCurrent = current;
                    current = current -> pNext;
                }
            if (current == firstNode) //insert newNode before first
            {
                firstNode -> pPrevious = newNode;
                newNode -> pNext = firstNode;
                firstNode = newNode;
                numberNodes++;
            }
            else
            {
                //insert newNode between trailCurrent and current
                if (current != nullptr)
                {
                    trailCurrent -> pNext = newNode;
                    newNode -> pPrevious = trailCurrent;
                    newNode -> pNext = current;
                    current -> pPrevious = newNode;
                }
                else
                {
                    trailCurrent -> pNext = newNode;
                    newNode -> pPrevious = trailCurrent;
                    lastNode = newNode;
                }
                numberNodes++;
            }//end else
        }//end else
    }

    // insert newItem after the existingNode
    template <class DataType>
    void DoubleLinkedList<DataType>::insert_after (ListNode<DataType>* existingNode, const DataType &newItem)
    {
        ListNode<DataType> *current; //pointer to traverse the list
        ListNode<DataType> *trailCurrent; //pointer just before current
        ListNode<DataType> *newNode; //pointer to create a node
        bool found;
        newNode = new ListNode<DataType>; //create the node
        newNode -> dataType = newItem; //store the new item in the node
        newNode -> pNext = nullptr;
        newNode -> pPrevious = nullptr;
        if (first == nullptr) //if the list is empty, newNode is
            //the only node
        {
            firstNode = newNode;
            lastNode = newNode;
            numberNodes++;
        }
        else
        {
            found = false;
            current = firstNode;
            while (current != nullptr && !found) //search the list
                if (current -> dataType >= newItem)
                    found = true;
                else
                {
                    trailCurrent = current;
                    current = current -> pNext;
                }
            if (current == first) //insert newNode before first
            {
                firstNode -> pPrevious = newNode;
                newNode -> pNext = firstNode;
                firstNode = newNode;
                numberNodes++;
            }
            else
            {
                //insert newNode between trailCurrent and current
                if (current != nullptr)
                {
                    trailCurrent -> pNext = newNode;
                    newNode -> pPrevious = trailCurrent;
                    newNode -> pNext = current;
                    current -> pPrevious = newNode;
                }
                else
                {
                    trailCurrent -> pNext = newNode;
                    newNode -> pPrevious = trailCurrent;
                    lastNode = newNode;
                }
                numberNodes++;
            }//end else
        }//end else
    }

    // find the node and return the address to the node. Return
    // nullptr if not found
    template <class DataType>
    ListNode<DataType>* DoubleLinkedList<DataType>::find(const DataType &existingItem)
    {
        bool found = false;
        ListNode<DataType> *current; //pointer to traverse the list
        current = firstNode;
        while (current != nullptr && !found)
            if (current -> dataType >= existingItem)
                found = true;
            else
            {
                current = current->next();
            }
        if (found)
            found = (current -> dataType == existingItem); //test for equality
        if (found)
            return current;
        else
            return nullptr;
    }

    // remove the node equal to currentItem
    template <class DataType>
    bool DoubleLinkedList<DataType>::erase(const DataType &currentItem)
    {
        bool found = false;
            ListNode<DataType> *trailCurrent; //pointer just before current
            ListNode<DataType> *current; //pointer to traverse the list
            current = firstNode;
            while (current != nullptr && !found)
            {
                if (current->dataType >= currentItem)
                    found = true;
                else
                {
                    trailCurrent= current;
                    current = current->next();
                }
            }
            if(found)
            {
                trailCurrent = current->previous();
            trailCurrent -> pNext = current -> next();
            if (current -> next() != nullptr)
                current -> pNext = trailCurrent;
            if (current == lastNode)
                lastNode = trailCurrent;
            numberNodes--;
            delete current;
            return true;
        }
        else
        {
            return false;
        }
    }

    // remove the node by address existingNode
    template <class DataType>
    bool DoubleLinkedList<DataType>::erase(ListNode<DataType> *existingNode)
    {
        ListNode<DataType> *current; //pointer to traverse the list
        ListNode<DataType> *trailCurrent; //pointer just before current
        bool found;
        if (first == nullptr)
            std::cout << "Cannot delete from an empty list." << std::endl;
        else if (firstNode -> dataType == existingNode) //node to be deleted is
        //the first node
        {
            current = firstNode;
            firstNode = firstNode -> next();
            if (firstNode != nullptr)
                firstNode -> pPrevious = nullptr;
            else
                lastNode = nullptr;
            numberNodes--;
            delete current;
        }
        else
        {
            found = false;
            current = firstNode;
            while (current != nullptr && !found) //search the list
                if (current->dataType >= existingNode)
                    found = true;
                else
                    current = current -> next();
            if (current == nullptr)
                std::cout << "The item to be deleted is not in " << "the list." << std::endl;
            else if (current -> dataType == existingNode) //check for
            {
                trailCurrent = current->previous();
                trailCurrent -> pNext = current -> next();
                if (current -> next() != nullptr)
                    current -> pNext = trailCurrent;
                if (current == lastNode)
                    lastNode = trailCurrent;
                numberNodes--;
                delete current;
            }
            else
                std::cout << "The item to be deleted is not in list." << std::endl;
        }//end else
    }


// your implementation code goes here for DoubleLinkedList

// note the code for the debug() function is included
// display a debug version of the list
//void DoubleLinkedList<DataType>::debug(std::ostream &out) const
*/