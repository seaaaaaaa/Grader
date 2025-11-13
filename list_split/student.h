#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
CP::list<T> CP::list<T>::split(iterator it,size_t pos) {
  //write your code here
  CP::list<T> result;
  if(pos >= mSize) {
      return result;
  }
  node* end_half1 = it.ptr->prev;
  node* end_half2 = mHeader->prev;
  mHeader->prev = end_half1;
  end_half1->next = mHeader;
  node* start_half2 = it.ptr;
  result.mHeader->next = start_half2;
  start_half2->prev = result.mHeader;
  end_half2->next = result.mHeader;
  result.mHeader->prev = end_half2;
  result.mSize = mSize - pos;
  mSize = pos;
  return result;
}

#endif
