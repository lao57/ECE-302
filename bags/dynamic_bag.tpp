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
  delete[] copier;
  return true;
}

template<typename T>
bool DynamicBag<T>::remove(const T& item)
{
  int index = -4;
  for (int i=0; i<size; i++){
    if (bagptr[i]==item){
      index = i;
    }
  }
  if(index == -4){
    return false;
  }else{
    T *copier = bagptr;
    size -= 1;
    bagptr = new T[size];
    for (int i = 0; i < index; i++){
      bagptr[i] = copier[i];
    }
    for (int i = index + 1; i< size +1; i++){
      bagptr[i-1] = copier[i];
    }
    delete[] copier;
    return true;
  }

}

template<typename T>
bool DynamicBag<T>::isEmpty() const
{
  if (size == 0){
    return true;
  }else{
  return false;
  }
}

template<typename T>
std::size_t DynamicBag<T>::getCurrentSize() const
{
  return size;
}

template<typename T>
bool DynamicBag<T>::contains(const T& item) const
{  
  int index = -4;
  for (int i=0; i<size; i++){
    if (bagptr[i]==item){
      index = i;
    }
  }
  if(index == -4){
    return false;
  }else{
    return true;
  }
}

template<typename T>
void DynamicBag<T>::clear(){
  T *copier = bagptr;
  delete[] copier;
  size = 0;
  bagptr = new T[size];
}

template<typename T>
std::size_t DynamicBag<T>::getFrequencyOf(const T & item) const
{
  size_t index = 0;
  for (int i=0; i<size; i++){
    if (bagptr[i]==item){
      index += 1;
    }
  }
  return index;
};
