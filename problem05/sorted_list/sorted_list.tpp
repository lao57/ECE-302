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
  unsorted_list.sort();
  operator=(unsorted_list);
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
  while(check == false && i < getLength()){
    T comp = getEntry(i);
    if (item < comp || item == comp){
      List<T>::insert(i,item);
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
