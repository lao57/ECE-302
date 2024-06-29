#include "sorted_list.hpp"
#include <stdexcept>

template <typename T>
SortedList<T>::SortedList(): List<T>()
{
  List<T>();
}

template <typename T>
SortedList<T>::SortedList(List<T> unsorted_list) 
{
  List<T>();
  unsorted_list.sort();
  int len = unsorted_list.getLength();
  for (int i = 0; i < len; i++){
    insert(unsorted_list.getEntry(i));
  }
}

template <typename T>
SortedList<T>::SortedList(const SortedList<T> & x):
  List<T>(x)
{
}

template <typename T>
SortedList<T>& SortedList<T>::operator=(SortedList<T> x)
{
  List<T>::operator=(x);
  return *this;
}

template <typename T>
SortedList<T>::~SortedList()
{
  // base destructor gets called automatically
}

template <typename T>
bool SortedList<T>::isEmpty() const noexcept
{
  return List<T>::isEmpty();
}

template <typename T>
std::size_t SortedList<T>::getLength() const noexcept
{
  return List<T>::getLength();
}

template <typename T>
void SortedList<T>::insert(const T& item)
{
  bool check = false;
  if(getLength() > 0){
    int i = 0;
    int len = getLength();
  while(check == false && i < len){
    T comp = getEntry(i);
    if (item < comp || item == comp){
      List<T>::insert(i,item);
      check = true;
    }else if(i == getLength()-1){
      List<T>::insert(i+1,item);
      check = true;
    }
    i++;
  }
  }else{
    List<T>::insert(0,item);
  }
}

template <typename T>
void SortedList<T>::remove(const T& item)
{  
  bool check = false;
  for (int i = 0; i < getLength(); i++){
    T value = getEntry(i);
    if (value == item){
      List<T>::remove(i);
      check = true;
    }
  }
  if (check == false){
    List<T>::remove(-23);
  }
}

template <typename T>
void SortedList<T>::removeAt(std::size_t position)
{  
  List<T>::remove(position);
}

template <typename T>
void SortedList<T>::clear()
{
  List<T>::clear();
}

template <typename T>
T SortedList<T>::getEntry(std::size_t position) const
{
  if (position < 0 || position >= getLength()){
    throw std::range_error("out of range");
  }
  return List<T>::getEntry(position);
}

template <typename T>
long int SortedList<T>::getPosition(const T& item)
{
  int index = -1;
  for (int i = 0; i < getLength(); i++){
    T value = getEntry(i);
    if (value == item){
      index = i;
    }
  }
  return index;
}
