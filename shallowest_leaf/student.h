#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

//you can use this function
template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT,MappedT,CompareT>::shallowest_leaf(node* n) {
  //write your code here
  if(n == nullptr) return -1;
  if(n->left == nullptr && n->right == nullptr) return 0;
  int left_depth = shallowest_leaf(n->left);
  int right_depth = shallowest_leaf(n->right);
  if(left_depth == -1) return right_depth + 1;
  if(right_depth == -1) return left_depth + 1;
  return std::min(left_depth, right_depth) + 1;
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT,MappedT,CompareT>::shallowest_leaf() {
  //write your code here
  if(mSize==0) return -1;
  if(mSize==1) return 0;
  return shallowest_leaf(mRoot);
}


#endif
