#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "queue.h"
template <typename T>
void CP::queue<T>::block_remove(size_t from, size_t to) {
    // Write your code here
    size_t target = (to + from)/2;
    size_t dSize = to - from + 1;
    if(target >= mSize/2){
        for(size_t i = from; i <mSize-dSize; i++){
            mData[(mFront + i) % mCap] = mData[(mFront + i + dSize) % mCap];
        }
    } else {
        for(size_t i = to; i > dSize-1; i--){
            mData[(mFront + i) % mCap] = mData[(mFront + i - dSize ) % mCap];
        }
        mFront = (mFront + dSize) % mCap;
    }
    mSize -= dSize;
}
#endif