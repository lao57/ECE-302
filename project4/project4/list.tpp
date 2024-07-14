
#include "list.hpp"

template <typename T>
List<T>::List()
{
  length = 0;
  items = new T[length];
}

template <typename T>
List<T>::~List()
{
  delete [] items;
}

template <typename T>
List<T>::List(const List<T>& x)
{
  length = x.length;
  items = new T[x.length];
  for (std::size_t i=0; i<x.length; i++) {
    items[i] = x.items[i];
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
  std::swap(items, x.items);
  std::swap(length, x.length);
}

template <typename T>
bool List<T>::isEmpty() const noexcept
{
  return length == 0;
}

template <typename T>
std::size_t List<T>::getLength() const noexcept
{
  return length;
}

template <typename T>
void List<T>::insert(std::size_t position, const T& item)
{
  if (position > length || position < 0) {
    throw std::range_error("Out of range - Insert");
  }
  
  T* new_items = new T[length+1];
  for (std::size_t i=0; i<position; i++) {
    new_items[i] = items[i];
  }

  new_items[position] = item;
  for (std::size_t i=position; i<length; i++) {
    new_items[i+1] = items[i];
  }

  delete [] items;
  items = new_items;
  length++;
}

template <typename T>
void List<T>::remove(std::size_t position)
{
  if (isEmpty()) {
    throw std::range_error("List is Empty - remove");
  }
  if (position >= length || position < 0) {
    throw std::range_error("Out of range - remove");
  }

  T* new_items = new T[length-1];
  for (std::size_t i=0; i<position; i++) {
    new_items[i] = items[i];
  }

  for (std::size_t i=position+1; i<length; i++) {
    new_items[i-1] = items[i];
  }

  delete [] items;
  items = new_items;
  length--;
}

template <typename T>
void List<T>::clear()
{
  delete [] items;
  items = nullptr;
  length = 0;
}

template <typename T>
T List<T>::getEntry(std::size_t position) const
{
  if (isEmpty()) {
    throw std::range_error("List is Empty - getEntry");
  }
  if (position >= length) {
    throw std::range_error("Out of range - getEntry.");
  }
  return items[position];
}

template <typename T>
void List<T>::setEntry(std::size_t position, const T& newValue)
{
  if (isEmpty()) {
    throw std::range_error("List is Empty - setEntry");
  }
  if (position >= length || position < 0) {
    throw std::range_error("Out of range - setEntry.");
  }
  items[position] = newValue;
}

template <typename T>
bool List<T>::contains(T val){
  bool cont = false;
  for (int i = 0; i < length; i++){
    if(val == items[i]){
      cont = true;
    }
  }
  return cont;
}