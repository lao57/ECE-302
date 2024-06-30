//  Adapated from Frank M. Carrano and Timothy M. Henry.

/** ADT Stack implementation.
    @file Stack.cpp */

#include <iostream>
#include <cstddef>
#include <stdexcept>
#include "Stack.hpp"
#include "Node.hpp"

// TODO: Implement the constructor here
template<class ItemType>
Stack<ItemType>::Stack() : headPtr(nullptr), currentSize(0)
{
}  // end default constructor

// TODO: Implement the destructor here
template<class ItemType>
Stack<ItemType>::~Stack()
{
	clear();
}  // end destructor

// TODO: Implement the isEmpty method here
template<class ItemType>
bool Stack<ItemType>::isEmpty() const
{
	if (currentSize == 0){
		return true;
	}else{
		return false;
	}
}  // end isEmpty

// TODO: Implement the size method here
template<class ItemType>
int Stack<ItemType>::size() const
{
	return currentSize;
}  // end size

// TODO: Implement the push method here
template<class ItemType>
bool Stack<ItemType>::push(const ItemType& newItem)
{
	// Add to beginning of chain: new node references rest of chain;
	// (headPtr is null if chain is empty)
	Node<ItemType>* nextNodePtr = new Node<ItemType>(newItem, headPtr); // alternate code

	headPtr = nextNodePtr;          // New node is now first node
	currentSize++;

	return true;   
}  // end push

// TODO: Implement the peek method here
template<class ItemType>
ItemType Stack<ItemType>::peek() const
{
	if(currentSize > 0){
	return headPtr->getItem();
	}else{
		throw std::range_error("range error1");
	}
}  // end peek

// TODO: Implement the pop method here
template<class ItemType>
bool Stack<ItemType>::pop() 
{
	if(currentSize > 0){
		Node<ItemType>* nextNodePtr = headPtr->getNext();
		delete headPtr;
		headPtr = nextNodePtr;
		currentSize--;
		return true;

	}else{
		return false;
	}
}  // end pop

// TODO: Implement the clear method here
template<class ItemType>
void Stack<ItemType>::clear()
{
	Node<ItemType>* nodeToDeletePtr = headPtr;
	while (headPtr != nullptr)
	{
		headPtr = headPtr->getNext();
		// Return node to the system
		nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
		nodeToDeletePtr = headPtr;
	}  // end while
	// headPtr is nullptr; nodeToDeletePtr is nullptr

	currentSize = 0;
}  // end clear

