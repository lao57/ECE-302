#include "bitarray.hpp"
#include <stdexcept>

BitArray::BitArray() {
    N = 8;
    arrPtr = new int8_t[N];
    for (int i = 0; i < N; i++){
        arrPtr[i] = 0;
    }
    valid = true;
}

BitArray::BitArray(intmax_t size) {
    if (size <= 0){
        throw std::out_of_range("The size of array must be greater than zero -- BitArray second contructor");
    }
    N = size;
    arrPtr = new int8_t[N];
    for (int i = 0; i < N; i++){
        arrPtr[i] = 0;
    }
    valid = true;
}

BitArray::BitArray(const std::string & value) {
    N = value.length();
    arrPtr = new int8_t[N];

    /* I BELIEVE THAT THIS IS RIGHT BUT SHOULD BE IN GOOD()
    for (int j = 0; j < N; j++){
        if(value[j] != 0 && value[j] != 1){
            throw std::out_of_range("the string initializer can only contain values 1 or 0 -- BitArray thrid constructor");
        }
    }
    */

    for (int i = 0; i < N; i++){
        arrPtr[i] = static_cast<int8_t>(value[i] - '0');
    }
    valid = true;
    valid = good();
}

BitArray::~BitArray() {
    delete[] arrPtr;
}

intmax_t BitArray::size() const
{
    return N;
}

bool BitArray::good() const
{
    if (valid == false){
        return false;
    }
    if(N <= 0){
        return false;
    }
    for (int j = 0; j < N; j++){
        if(arrPtr[j] != 0 && arrPtr[j] != 1){
            return false;
        }
    }
    return true;
}

void BitArray::set(intmax_t index)
{
    if (index < 0 || index > (N-1)){
        valid = false;
    }else{
        arrPtr[index] = 1;
    }

}

void BitArray::reset(intmax_t index)
{
    if (index < 0 || index > (N-1)){
        valid = false;
    }else{
        arrPtr[index] = 0;
    }
}

void BitArray::toggle(intmax_t index)
{
    if (index < 0 || index > (N-1)){
        valid = false;
    }else{
        if(arrPtr[index] = 0){
            arrPtr[index] = 1;
        }else if(arrPtr[index] = 1){
            arrPtr[index] = 0;
        }
    }
}

bool BitArray::test(intmax_t index)
{
    if (index < 0 || index > (N-1)){
        valid = false;
        return false;
    }
    if(arrPtr[index] == 1){
        return true;
    }else{
        return false;
    }
}

std::string BitArray::asString() const
{
    std::string outStr;
    outStr.resize(N);
    for (int i = 0; i < N; i++){
        int checker = arrPtr[i];
        if(checker == 0){
            outStr[i] = '0';
        }else if(checker == 1){
            outStr[i] = '1';
        }
        
    }
    return outStr;
}

// TODO: other methods
