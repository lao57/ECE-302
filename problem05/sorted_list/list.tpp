#include "list.hpp"
#include <stdexcept>


template <typename T>
List<T>::List()
{
  headptr = nullptr;
  size = 0;
}

template <typename T>
List<T>::~List()
{
  clear();
}

template <typename T>
List<T>::List(const List<T>& x)
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
List<T>& List<T>::operator=(List<T> x)
{
  swap(x);
  return *this;
}

template <typename T>
void List<T>::swap(List& x) 
{
  std::swap(headptr, x.headptr);
  std::swap(size,x.size);
}

template <typename T>
bool List<T>::isEmpty() const noexcept
{
  if(size ==0){
    return true;
  }else{
    return false;
  }
}

template <typename T>
std::size_t List<T>::getLength() const noexcept
{
  //TODO
  return size;
}

template <typename T>
void List<T>::insert(std::size_t position, const T& item)
{
  if(position > size){
    throw std::range_error("2");
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
  }
}

template <typename T>
void List<T>::remove(std::size_t position)
{
  if (position>= size){
    throw std::range_error("1");
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
  }
}

template <typename T>
void List<T>::clear()
{
  while (headptr != nullptr) {
    Node<T> *clearer = headptr;
    headptr = headptr->getNext();
    delete clearer;
  }
  size = 0;

}

template <typename T>
T List<T>::getEntry(std::size_t position) const
{
  if (position >= size || position < 0) {
    throw std::range_error("out of range");
  }else{
  Node<T> *nodetracker = headptr;
  for (int i = 0; i < position; i++){
    nodetracker = nodetracker->getNext();
  }
  return nodetracker->getItem();
  }
}

template <typename T>
void List<T>::setEntry(std::size_t position, const T& newValue)
{
  if (position >= size || position < 0) {
    throw std::range_error("out of range");
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
