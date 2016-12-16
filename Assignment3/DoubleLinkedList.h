/* Assignment 4 for CS 2336.002
   Programmer: Diego Lara
   Description:
   This is the meat of the project. This is where we create both the ListNode and the DoubleLinkedList.
 */
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

#ifndef DOUBLELINKEDLIST_H_
#define DOUBLELINKEDLIST_H_

#include <iostream>
#include <iomanip>
#include <cstddef>
#include <assert.h>


// forward declaration of the template class DoubleLinkedList
template<class DataType>
class DoubleLinkedList;

// ListNode class
template<class DataType>
class ListNode
{
    // make DoubleLinkedList<DataType> a friend class
    friend class DoubleLinkedList<DataType>;
private:
    // contains the actual data
    DataType dataType;
    // pointer to the next item in the list or nullptr
    // if at the end
    ListNode<DataType>* pNext;
    // pointer to the previous item in the list or nullptr
    // if at the start
    ListNode<DataType>* pPrevious;
public:
    // default constructor
    inline ListNode()
    {
        //dataType=NULL;
        pPrevious=nullptr;
        pNext=nullptr;
    }
    // copy constructor
    inline ListNode(const DataType &newItem)
    {
        dataType= newItem;
        pPrevious=nullptr;
        pNext=nullptr;
    }
    // get the next node
    inline ListNode* next() const
    {
        return pNext;
    }
    // get the previous node
    inline ListNode* previous() const
    {
        return pPrevious;
    }
    // return the data stored in the node as a const
    inline const DataType& data() const
    {
        return const_cast<DataType> (dataType);
    }
    // return the data stored in the node
    inline DataType& data()
    {
        return dataType;
    }
private:
    // update the next node
    inline void next(ListNode *nextNode)
    {
        pNext = nextNode;
    }

// update the previous node
    inline void previous(ListNode *previousNode)
    {
        pPrevious = previousNode;
    }
};

// DoubleLinkedList class
template<class DataType>
class DoubleLinkedList
{
private:
    // number of nodes in the list. Note that std::size_t
    // is defined in header file cstddef.
    std::size_t numberNodes;
    // point to the first node or nullptr for empty list
    ListNode<DataType>* firstNode;
    // point to the last node or nullptr for empty list
    ListNode<DataType>* lastNode;
public:
    // default constructor
    DoubleLinkedList();
    // copy constructor
    DoubleLinkedList(const DoubleLinkedList &other);
    // destructor
    virtual ~DoubleLinkedList();
    // return the number of nodes in the list
    std::size_t size() const;
    // return true if the list is empty
    bool empty() const;
    // display the contents of the list to std::cout
    void print() const;
    // dump the contends in debug format to passed in
    // ostream - usage to cout would be:
    //   list.debug(std::cout);
    void debug(std::ostream &out) const;
    // first node in the list (or nullptr for empty)
    virtual ListNode<DataType>* first() const;
    // last node in the list (or nullptr for empty)
    virtual ListNode<DataType>* last() const;
    // add an item to the front of the list
    virtual void push_front(const DataType &newItem);
    // add an item to the back of the list
    virtual void push_back(const DataType &newItem);
    // remove an item from the front of the list
    virtual void pop_front();
    // remove an item from the back of the list
    virtual void pop_back();
    // insert newItem before the existingNode
    virtual void insert_before (ListNode<DataType>* existingNode,
                                const DataType &newItem);
    // insert newItem after the existingNode
    virtual void insert_after (ListNode<DataType>* existingNode,
                               const DataType &newItem);
    // find the node and return the address to the node. Return
    // nullptr if not found
    virtual ListNode<DataType>* find(const DataType &existingItem);
    // remove the node equal to currentItem
    virtual bool erase(const DataType &currentItem);
    // remove the node by address existingNode
    virtual bool erase(ListNode<DataType> *existingNode);
};

// default constructor
template <class DataType>
DoubleLinkedList<DataType>::DoubleLinkedList()
{
    numberNodes=0;
    firstNode  = nullptr;
    lastNode = nullptr;
}

// copy constructor
template <class DataType>
DoubleLinkedList<DataType>::DoubleLinkedList(const DoubleLinkedList &other)
{
    numberNodes=0;
    ListNode<DataType> *temp=other.first();
    firstNode= nullptr;
    lastNode= nullptr;
    while(temp!=nullptr)
    {
        push_back(temp->data());
        temp=temp->pNext;
        numberNodes++;
    }

}

// destructor
template <class DataType>
DoubleLinkedList<DataType>::~DoubleLinkedList()
{
    ListNode<DataType> *temp; //pointer to delete the node
    if(firstNode==nullptr)
    {
        firstNode=nullptr;
        lastNode=nullptr;
    }
    else {
        while (firstNode != nullptr) {
            temp = firstNode;
            firstNode = firstNode->next();
            delete temp;
        }
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
        return firstNode ;//->DataType
    else
        return nullptr;
}

// last node in the list (or nullptr for empty)
template <class DataType>
ListNode<DataType>* DoubleLinkedList<DataType>::last() const
{
    if(lastNode != nullptr)
        return lastNode ;//-> dataType
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
    newNode = new ListNode<DataType>(); //create the node
    newNode->dataType = newItem; //store the new item in the node
    newNode->pNext = nullptr;
    newNode->pPrevious = nullptr;
    if (firstNode == nullptr) //if the list is empty, newNode is
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
        {
            if (current->dataType == newItem)
                found = true;
            else {
                trailCurrent = current;
                current = current->pNext;
                //numberNodes++;
            }
        }
        if (!found) //insert newNode before first
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
    if (firstNode == nullptr) //if the list is empty, newNode is
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
        {
            if (current->dataType == newItem)
                found = true;
            else {
                trailCurrent = current;
                current = current->pNext;
                //numberNodes++;
            }
        }
        if(!found)
        {
            trailCurrent->pNext = newNode;
            newNode->pPrevious = trailCurrent;
            lastNode = newNode;
            numberNodes++;
        }
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
    ListNode<DataType> *test;
    current = firstNode;
    test=firstNode;
    while(test!=nullptr)
    {
        //std::cout<< test << std::endl;
        test=test->pNext;
    }
        if(numberNodes==0)
        {
            return;
        }
        else if(numberNodes==1)
        {
            numberNodes--;
            delete current;
            firstNode=nullptr;
            lastNode=nullptr;
        }
        else
        {
            trailCurrent=current;
            current=current->next();
            firstNode=current;
            current->pPrevious=nullptr;
            delete trailCurrent;
            numberNodes--;
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
        if (current->data() == lastNode->data())
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
        ListNode<DataType> *trailCurrent;
        ListNode<DataType> *newNode; //pointer to create a node
        bool found;
        newNode = new ListNode<DataType>; //create the node
        newNode -> dataType = newItem; //store the new item in the node
        newNode -> pNext = nullptr;
        newNode -> pPrevious = nullptr;
        if (firstNode == nullptr) //if the list is empty, newNode is
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
            current = firstNode;

            while (current != nullptr)
            {
                if(current->data() == existingNode->data())
                {
                    ListNode<DataType> *temp=current->previous();

                    newNode->pNext=current;
                    newNode->pPrevious=temp;
                    if(temp != nullptr)
                        temp->pNext=newNode;
                    current->pPrevious=newNode;
                    if(current==firstNode)
                        firstNode=current->pPrevious;
                    numberNodes++;
                }
                current=current->pNext;

            }
        }

}

// insert newItem after the existingNode
template <class DataType>
void DoubleLinkedList<DataType>::insert_after (ListNode<DataType>* existingNode, const DataType &newItem)
{
    ListNode<DataType> *current; //pointer to traverse the list
    ListNode<DataType> *trailCurrent;
    ListNode<DataType> *newNode; //pointer to create a node
    bool found;
    newNode = new ListNode<DataType>; //create the node
    newNode -> dataType = newItem; //store the new item in the node
    newNode -> pNext = nullptr;
    newNode -> pPrevious = nullptr;
    if (firstNode == nullptr) //if the list is empty, newNode is
        //the only node
    {
        firstNode = newNode;
        lastNode = newNode;
        numberNodes++;
    }
    else {
        found = false;
        current = firstNode;
        while (current != nullptr && !found) //search the list
        {
            if (current->data() == newItem)//-> dataType
            {
                found = true;
                return;
            } else {
                trailCurrent = current;
                current = current->pNext;
            }
        }
        current = firstNode;

        while (current != nullptr)
        {
            if(current->data() == existingNode->data())
            {
                ListNode<DataType> *temp=current->next();

                newNode->pNext=temp;
                newNode->pPrevious=current;
                if(temp != nullptr)
                temp->pPrevious=newNode;
                current->pNext=newNode;
                numberNodes++;
            }
            current=current->pNext;

        }
    }
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
        if (current->data() == existingItem)// -> dataType
            found = true;
        else
        {
            current = current->next();
        }
    if (found)
        found = (current->dataType  == existingItem); //test for equality -> dataType
    if (found)
        return current;
    else
        return nullptr;
}

// remove the node equal to currentItem
template <class DataType>
bool DoubleLinkedList<DataType>::erase(const DataType &currentItem)
{
    ListNode<DataType> *temp=firstNode;
    while(temp!=nullptr)
    {
        std::cout<< temp->data()<<std::endl;
        temp=temp->pNext;
    }
    bool found = false;
    ListNode<DataType> *trailCurrent; //pointer just before current
    ListNode<DataType> *current; //pointer to traverse the list
    current = firstNode;
    while (current != nullptr && !found)
    {
        if (current->data() == currentItem)//->dataType
        {
            found = true;
            break;
        }
        else
        {
            trailCurrent= current;
            current = current->next();
        }
    }
    if(found)
    {
        if(current==firstNode)
        {
          firstNode=firstNode->pNext;
            delete current;
            numberNodes--;
        }
        else
        {
            trailCurrent = current->previous();
            trailCurrent->pNext = current->next();
            if (current->next() != nullptr)
                current->pNext = trailCurrent;
            if (current == lastNode)
                lastNode = trailCurrent;
            numberNodes--;
            delete current;
            return true;
        }
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
    if (firstNode == nullptr)
        std::cout << "Cannot delete from an empty list." << std::endl;
    else if (firstNode  == existingNode) //node to be deleted is -> dataType
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
            if (current == existingNode)//->dataType
                found = true;
            else
                current = current -> next();
        if (current == nullptr)
            std::cout << "The item to be deleted is not in " << "the list." << std::endl;
        else if (current -> data() == existingNode->data()) //check for
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


// note the code for the debug() function is included
// display a debug version of the list
template<class DataType>
void DoubleLinkedList<DataType>::debug(std::ostream &out) const
{
    const unsigned int ADDRWIDTH = 10;
    out << "START DEBUG" << std::endl;
    out << "first  =" << std::setw(ADDRWIDTH) << firstNode;
    out << ", last=" << std::setw(ADDRWIDTH) << lastNode;
    out << ", # nodes=" << size() << std::endl;
    unsigned int count = 1;

    for (auto current=firstNode; current!= nullptr; current=current->next())
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

#endif /* DOUBLELINKEDLIST_H_ */