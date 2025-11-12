#ifndef __STUDENT_H__
#define __STUDENT_H__


template <typename T>
bool CP::list<T>::check() {
  //your code here
  if(mSize==0) return mHeader->next==mHeader && mHeader->prev==mHeader;
  if(mHeader->next == NULL || mHeader->prev == NULL) return false;
  if(mHeader->next->prev != mHeader) return false;
  if(mHeader->prev->next != mHeader) return false;
  int count = 0;
  node* p = mHeader->next;
  while(p != mHeader) {
    if(p == NULL) return false;
    if(p->prev == NULL || p->next == NULL) return false;
    if(p->prev->next != p) return false;
    p = p->next;
    count++;
    if(count > mSize) return false;
  }
  return count == mSize;
}


#endif
