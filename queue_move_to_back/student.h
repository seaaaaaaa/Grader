#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>


template <typename T>
void CP::queue<T>::move_to_back(size_t pos) {
  //write your code here
  T b = mData[(mFront + pos) % mCap];
  for(size_t i = pos; i < this->size()-1; i++) {
    mData[(mFront + i) % mCap] = mData[(mFront + i + 1) % mCap];
  }
  mData[(mFront + this->size() - 1) % mCap] = b;
}

#endif
