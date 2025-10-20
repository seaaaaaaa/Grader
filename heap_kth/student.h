#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "priority_queue.h"
#include <math.h>

template <typename T,typename Comp >
T CP::priority_queue<T,Comp>::get_kth(size_t k) const {
  //write your code here
  //can include anything
  size_t vSize = std::min(size_t(pow(2,k)-1), mSize);
  std::vector<T> vec;
  for(size_t i = 0; i < vSize; i++){
    vec.push_back(mData[i]);
  }
  std::sort(vec.begin(), vec.end(), mLess);
  return vec[vSize-k];
}

#endif
