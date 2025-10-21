#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <cassert>
#include <algorithm>

template <typename T>
void CP::queue<T>::reverse(int a,int b) {
  //your code here
  for(int i = a,c=0; i<=(a+b)/2; i++,c++){
    std::swap(mData[(mFront+i)%mCap], mData[(mFront+b-c)%mCap]);
  }
}

#endif
