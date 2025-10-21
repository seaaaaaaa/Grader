#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <vector>
#include "queue.h"

template <typename T>
void CP::queue<T>::v_split(std::vector<std::queue<T>> &output, size_t k) const
{
  // your code here
  std::vector<int> counts(k, 0);
  for (size_t i = 0; i < mSize; i++){
    counts[i % k]++;
  }
  CP::queue<T> temp = *this;
  for(auto &c : counts){
    std::queue<T> q;
    for(size_t i = 0; i < c; i++){
      q.push(temp.front());
      temp.pop();
    }
    output.push_back(q);
  }


}

#endif
