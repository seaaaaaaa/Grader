#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "segmented_vector.h"
template <typename T>
CP::SegmentedVector<T>::~SegmentedVector()
{
    // TODO: Write your code here
    for(size_t i = 0; i < mCap; i++) {
        delete[] mData[i];
    }
    delete[] mData;
}
template <typename T>
void CP::SegmentedVector<T>::expand(size_t capacity)
{
    // TODO: Write your code here
    T** arr = new T*[capacity]();
    for(size_t i = 0; i < capacity; i++) {
        arr[i] = new T[blockSize]();
    }
    for(size_t i = 0; i < mSize; i++) {
        arr[i / blockSize][i % blockSize] = mData[i / blockSize][i % blockSize];
    }
    
    
    for(size_t i = 0; i < mCap; i++) {
        delete[] mData[i];
    }
    delete[] mData;
    mData = arr;
    mCap = capacity;
}
template <typename T>
void CP::SegmentedVector<T>::insert(int index, const T& element)
{
    // TODO: Write your code here
    if(index<0||index>mSize){
        throw std::out_of_range("index of out range");
    }
    ensureCapacity((mSize + 1 + blockSize - 1) / blockSize);
    for(size_t i = mSize; i > index; i--) {
        size_t sblock = i/blockSize;
        size_t offset = i%blockSize;
        size_t tblock = (i-1)/blockSize;
        size_t toffset = (i-1)%blockSize;
        mData[sblock][offset] = mData[tblock][toffset];
    }
    mData[index/blockSize][index%blockSize] = element;
    mSize++;


}
template <typename T>
T& CP::SegmentedVector<T>::operator[](int index) const
{
    // TODO: Write your code here
    if(index<0||index>=mSize){
        throw std::out_of_range("index of out range");
    }
    return mData[index/blockSize][index%blockSize];
}


#endif