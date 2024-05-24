#include "dynamic_bag.hpp"

template<typename T>
DynamicBag<T>::DynamicBag() {
  size = 0;
  bagptr = nullptr;
}
  

template<typename T>
DynamicBag<T>::DynamicBag(const DynamicBag<T>& x){
  size = x.size;
  bagptr = new T[size];
  for (int i =0; i<size; i++){
    bagptr[i] = x.bagptr[i];
  }
}
    
template<typename T>
DynamicBag<T>::~DynamicBag(){
  delete [] bagptr;
}
  
template<typename T>
DynamicBag<T>& DynamicBag<T>::operator=(DynamicBag<T> x)
{ 
  swap(x);
  return *this;
}

template<typename T>
void DynamicBag<T>::swap(DynamicBag<T>& x){
  std::swap(bagptr, x.bagptr);
  std::swap(size, x.size);
}

template<typename T>
bool DynamicBag<T>::add(const T& item)
{
  T *copier = bagptr;
  size += 1;
  bagptr = new T[size];
  for (int i =0; i<size-1; i++){
    bagptr[i] = copier[i];
  }
    bagptr[size-1] = item;
  return true;
}

template<typename T>
bool DynamicBag<T>::remove(const T& item)
{
  return false;
}

template<typename T>
bool DynamicBag<T>::isEmpty() const
{
  return false;
}

template<typename T>
std::size_t DynamicBag<T>::getCurrentSize() const
{
  return 0;
}

template<typename T>
bool DynamicBag<T>::contains(const T& item) const
{  
  return false;
}

template<typename T>
void DynamicBag<T>::clear(){}

template<typename T>
std::size_t DynamicBag<T>::getFrequencyOf(const T & item) const
{
  return 0;
};
