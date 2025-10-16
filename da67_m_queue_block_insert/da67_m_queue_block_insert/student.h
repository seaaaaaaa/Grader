#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "queue.h"

template <typename T>
void CP::queue<T>::block_insert(size_t p, size_t m, const T &element)
{
	T *arr = new T[mSize+m]();
	for(size_t i=0;i<p;i++){
		arr[i] = mData[(mFront+i)%mCap];
	}
	for(size_t i=0;i<m;i++){
		arr[p+i] = element;
	}
	for(size_t i=p;i<mSize;i++){
		arr[i+m] = mData[(mFront+i)%mCap];
	}
	delete[] mData;
	mData = arr;
	mFront = 0;
	mSize = mSize + m;
	mCap = mSize;
}

#endif
