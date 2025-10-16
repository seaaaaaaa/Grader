#ifndef __STUDENT_H_
#define __STUDENT_H_


#include <vector>
#include <algorithm>
#include "queue.h"

template <typename T>
void CP::queue<T>::remove_many(std::vector<size_t> pos)
{
  // your code here
  CP::queue<T> temp;
  std::vector<bool> removed(mSize, false);
  for(auto &p : pos){
    removed[p] = true;
  }
  for(size_t i = 0; i < mSize; i++){
    if(!removed[i]){
      temp.push(mData[(mFront + i) % mCap]);
    }
  }
  delete[] mData;
  *this = temp;
}

#endif
