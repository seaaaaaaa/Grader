#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <vector>
#include <climits>
template <typename T>
template <typename Comp>
T CP::queue<T>::min_element(std::vector<size_t> pos,Comp comp) const {
  //your code here
  std::vector<T> elements;

  for(auto &x : pos) {
    if(x >= this->size()) continue;
    elements.push_back(mData[(mFront + x) % mCap]);
  }
  std::sort(elements.begin(), elements.end(), comp);
  //should return something
  return elements[0];
}

#endif
