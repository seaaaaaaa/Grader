#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::list<T>::extract(const T& value,iterator a, iterator b,CP::list<T>& output) {
    int n = 0;
    for (auto it = a; it != b; ) {
        if (*it == value) {
            iterator tmp(it.ptr->next);
            it.ptr->prev->next = it.ptr->next;
            it.ptr->next->prev = it.ptr->prev;
            delete it.ptr;
            mSize--;
            it = tmp;
            n++;
        } else {
            it++;
        }
    }
    for (int i = 0; i < n; i++) {
        node *tmp = new node(value, output.begin().ptr->prev, output.begin().ptr);
        output.begin().ptr->prev->next = tmp;
        output.begin().ptr->prev = tmp;
        output.mSize++;
    }
}

#endif
