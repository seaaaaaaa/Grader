#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>
#include <vector>
#include "map_bst.h"

// you can modify and use this function
template <typename KeyT,
          typename MappedT,
          typename CompareT>
void CP::map_bst<KeyT,MappedT,CompareT>::my_recur(node* n,size_t level,size_t tmp,std::vector<KeyT> &v) {
  //you MAY need to use this function
  if(n == NULL) return;
  if(tmp == level) v.push_back(n->data.first);
  my_recur(n->left, level, tmp+1, v);
  my_recur(n->right, level, tmp+1, v);
  return;
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
std::vector<KeyT> CP::map_bst<KeyT,MappedT,CompareT>::at_level(size_t level) {
  //write your code here
  std::vector<KeyT> res;
  my_recur(mRoot, level, 0, res);
  std::reverse(res.begin(), res.end());
  return res;
}


#endif
