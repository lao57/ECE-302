#include "add.hpp"

template <typename T> Add<T>::Add() {}

template <typename T> Add<T>::~Add() {}

template <typename T> T Add<T>::call(T a1, T a2) const { 
  return a1 + a2;
}
