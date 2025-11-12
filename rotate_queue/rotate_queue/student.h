#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "queue.h"

template <typename T>
void CP::queue<T>::rotate(int k) {
  // your code here
  if(mSize==0) return;
  if(k>0){
    k = k%mSize;
  } else if(k<0){
    k = -1*((-1*k)%mSize);
  }
  if(k==0) return;
  if(k>0){
    for(int i = 0; i < k; i++){
      mData[(mFront + mSize+mCap)%mCap] = front();
      mFront = (mFront + 1+mCap) % mCap;
    }
  } else{
    for(int i = 0; i < -1*k; i++){
      mData[(mFront-1+mCap)%mCap] = back();
      mFront = (mFront - 1 + mCap) % mCap;
    }
  }
}

#endif
