#ifndef __STUDENT_H_
#define __STUDENT_H_

using namespace std;
#include <algorithm>
#include <vector>

template <typename T,typename Comp>
size_t CP::priority_queue<T,Comp>::get_rank(size_t pos) const {
  //write your code here
  T target = mData[pos];
  size_t rank = 0;
  for(size_t i = 0; i < mSize; i++){
    if(mData[i] > target){
      rank++;
    }
  }
  return rank;
}

#endif
