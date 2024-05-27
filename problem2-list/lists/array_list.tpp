#include "array_list.hpp"

template <typename T>
ArrayList<T>::ArrayList() {
  size = 0;
  listptr = nullptr;
}

template <typename T>
ArrayList<T>::~ArrayList() {
  delete [] listptr;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList& rhs){
  size = rhs.size;
  listptr = new T[size];
  for (int i =0; i<size; i++){
    listptr[i] = rhs.listptr[i];
  }
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(ArrayList rhs){
  swap(rhs);
  return *this;
}

template <typename T>
void ArrayList<T>::swap(ArrayList& rhs) {
  std::swap(listptr,rhs.listptr);
  std::swap(size,rhs.size);
}

template <typename T>
bool ArrayList<T>::isEmpty() const noexcept {
  if(size == 0){
    return true;
  }else{
    return false;
  }
}

template <typename T>
std::size_t ArrayList<T>::getLength() const noexcept {
  return size;
}

template <typename T>
bool ArrayList<T>::insert(std::size_t position, const T& item){
  if (position > size){
    return false;
  }else{
    T *copier = listptr;
    size += 1;
    listptr = new T[size];
    for (int i = 0; i<position; i++){
      listptr[i] = copier[i];
    }
    listptr[position] = item;
    for (int i = position; i < size - 1; i++){
      listptr[i+1] = copier[i];
    }
    return true;
  }
}

template <typename T>
bool ArrayList<T>::remove(std::size_t position){
  if (position >= size){
    return false;
  }else{
    T *copier = listptr;
    size -= 1;
    listptr = new T[size];
    for (int i = 0; i<position; i++){
      listptr[i] = copier[i];
    }
    for (int i = position; i < size; i++){
      listptr[i] = copier[i+1];
    }
    return true;
  }
}

template <typename T>
void ArrayList<T>::clear() {
  T *copier = listptr;
  delete[] copier;
  size = 0;
  listptr = new T [size];
}

template <typename T>
T ArrayList<T>::getEntry(std::size_t position) const {
  return listptr[position];
}

template <typename T>
void ArrayList<T>::setEntry(std::size_t position, const T& newValue) {
  listptr[position] = newValue;
}
