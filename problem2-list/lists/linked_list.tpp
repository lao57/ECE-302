#include "linked_list.hpp"
#include <stdexcept>

template <typename T>
LinkedList<T>::LinkedList()
{
  headptr = nullptr;
  size = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
  clear();
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& x)
{
  if (x.headptr == nullptr){
    size = 0;
    headptr = nullptr;
  }else{
  size = x.size;
  headptr = new Node<T>(x.headptr->getItem());
  Node<T> *nodeptr = headptr;
  Node<T> *nodeptr2 = x.headptr->getNext();
  while(nodeptr2 != nullptr){
    nodeptr->setNext(new Node<T>(nodeptr2->getItem()));
    nodeptr2 = nodeptr2->getNext();
    nodeptr = nodeptr->getNext();
  }
  }


}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T> x)
{
  swap(x);
  return *this;
}

template <typename T>
void LinkedList<T>::swap(LinkedList& x) 
{
  std::swap(headptr, x.headptr);
  std::swap(size,x.size);
}

template <typename T>
bool LinkedList<T>::isEmpty() const noexcept
{
  if(size ==0){
    return true;
  }else{
    return false;
  }
}

template <typename T>
std::size_t LinkedList<T>::getLength() const noexcept
{
  //TODO
  return size;
}

template <typename T>
bool LinkedList<T>::insert(std::size_t position, const T& item)
{
  if(position > size){
    return false;
  }else{
    Node<T> *nodeptr = new Node<T>(item);
    size += 1;
    if(position == 0){
      nodeptr->setNext(headptr);
      headptr = nodeptr;
    }else{
      Node<T> *nodetracker = headptr;
      for (int i = 0; i < position-1; i++){
        nodetracker = nodetracker->getNext();
      }
      Node<T> *next = nodetracker;
      next = next->getNext();
      nodetracker->setNext(nodeptr);
      nodeptr->setNext(next);
    }
    return true;
  }
}

template <typename T>
bool LinkedList<T>::remove(std::size_t position)
{
  if (position>= size){
    return false;
  }else{
    if (position == 0){
      Node<T> *hold = headptr->getNext();
      delete headptr;
      headptr = hold;
    }else{
      Node<T> *nodetracker = headptr;
      for (int i = 0; i < position -1; i++){
        nodetracker = nodetracker->getNext();
      }
      Node<T> *deleter = nodetracker->getNext();
      nodetracker->setNext(deleter->getNext());
      delete deleter;
    }
    size -= 1;
    return true;
  }
}

template <typename T>
void LinkedList<T>::clear()
{
  while (headptr != nullptr) {
    Node<T> *clearer = headptr;
    headptr = headptr->getNext();
    delete clearer;
  }
  size = 0;

}

template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const
{
  if (position >= size) {
    return T();
  }else{
  Node<T> *nodetracker = headptr;
  for (int i = 0; i < position; i++){
    nodetracker = nodetracker->getNext();
  }
  return nodetracker->getItem();
  }
}

template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T& newValue)
{
  if (position >= size) {
  }else{
  if (position == size){
    insert(position, newValue);
  }else{
  Node<T> *nodetracker = headptr;
  for (int i = 0; i < position; i++){
    nodetracker = nodetracker->getNext();
  }
  nodetracker->setItem(newValue);
  }
  }
}
