#ifndef __STUDENT_H__
#define __STUDENT_H__

#include "list.h"
#include <stack>

template <typename T>
bool CP::list<T>::check() {
    //your code here

    int count = 0;
    auto node = mHeader;
    std::stack<T> vals;
    vals.push(mHeader->data);

    // forward check
    do {

        node = node->next;
        ++count;
        if (!node) return false;
        vals.push(node->data);
        
    } while (node != mHeader && count < mSize+1);

    if (count != mSize+1 || node != mHeader) return false;

    // reset
    count = 0;
    vals.pop();

    // backward check
    do {

        node = node->prev;
        ++count;
        if (!node || node->data != vals.top()) return false;
        vals.pop();

    } while (node != mHeader && count < mSize+1);

    if (count != mSize+1 || node != mHeader) return false;

    return true;

}

#endif