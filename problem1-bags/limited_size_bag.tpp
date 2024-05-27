#include "limited_size_bag.hpp"

template<typename T>
LimitedSizeBag<T>::LimitedSizeBag() {
  count = 0;
}
  
template<typename T>
bool LimitedSizeBag<T>::add(const T& item)
{
  if (count == 100){
    return false;
  }else{
    bagarray[count] = item;
    count += 1;
    return true;
  }

}

template<typename T>
bool LimitedSizeBag<T>::remove(const T& item)
{
  int index = -4;
  int checker = 0;
  for (int i = 0; i< count; i++){
    if(bagarray[i]==item){
      index = i;
      checker = 1;
    }
  }
  if (checker == 1){
    for (int i = index+1; i<count+1; i++){
      bagarray[i-1] = bagarray[i];
    }
    count -= 1;
    return true;
  }else{
    return false;
  }
}

template<typename T>
bool LimitedSizeBag<T>::isEmpty() const
{
  if (count == 0){
    return true;
  }else{
    return false;
  }
}

template<typename T>
std::size_t LimitedSizeBag<T>::getCurrentSize() const
{
  return count;
}

template<typename T>
bool LimitedSizeBag<T>::contains(const T& item) const
{  
  int checker = 0;
  for (int i = 0; i< count; i++){
    if(bagarray[i]==item){
      checker = 1;
    }
  }
  if (checker == 1){
    return true;
  }else{
    return false;
  }
}

template<typename T>
void LimitedSizeBag<T>::clear(){
  count = 0;
}

template<typename T>
std::size_t LimitedSizeBag<T>::getFrequencyOf(const T & item) const
{
  int checker = 0;
  for (int i = 0; i< count; i++){
    if(bagarray[i]==item){
      checker += 1;
    }
  }
  return checker;
};
