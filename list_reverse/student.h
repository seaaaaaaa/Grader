#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
typename CP::list<T>::iterator CP::list<T>::reverse(iterator a, iterator b) {
  //write your code here
  if(mSize == 0 || a == b) return a;
  auto start = a.ptr->prev;
  auto end = b.ptr;
  for(CP::list<T>::iterator it = a; it != b; --it) {
    std::swap(it.ptr->next, it.ptr->prev);
  }
  start->next = b.ptr->prev;
  b.ptr->prev->prev = start;
  end->prev = a.ptr;
  a.ptr->next = end;
  return list_iterator(start->next);
}

#endif
