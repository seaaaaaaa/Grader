#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>

template <typename T>
void CP::list<T>::merge(CP::list<CP::list<T>> &ls) {
  //write your code here
  for(auto &sublist : ls) {
    if(sublist.mSize == 0) continue;
    node *sub_first = sublist.mHeader->next;
    node *sub_last = sublist.mHeader->prev;

    if(mSize == 0) {
      mHeader->next = sub_first;
      sub_first->prev = mHeader;
      mHeader->prev = sub_last;
      sub_last->next = mHeader;
      mSize = sublist.mSize;

      sublist.mHeader->next = sublist.mHeader;
      sublist.mHeader->prev = sublist.mHeader;
      sublist.mSize = 0;
    } else {
      node *my_last = mHeader->prev;
      my_last->next = sub_first;
      sub_first->prev = my_last;
      mHeader->prev = sub_last;
      sub_last->next = mHeader;
      mSize += sublist.mSize;

      sublist.mHeader->next = sublist.mHeader;
      sublist.mHeader->prev = sublist.mHeader;
      sublist.mSize = 0;
    }
  }
}

#endif
