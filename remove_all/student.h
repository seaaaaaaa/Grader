#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::list<T>::remove_all(const T& value) {
  //write your code here
  for(auto it = begin(); it != end(); ) {
      if (*it == value) {
          iterator tmp(it.ptr->next);
          it.ptr->prev->next = it.ptr->next;
          it.ptr->next->prev = it.ptr->prev;
          delete it.ptr;
          mSize--;
          it = tmp;
      } else {
          it++;
      }
  }
}

#endif
