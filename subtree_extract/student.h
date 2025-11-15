#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "map_bst.h"

template <typename KeyT,typename MappedT, typename CompareT >
size_t CP::map_bst<KeyT,MappedT,CompareT>::process(node* n) {
  //write your code here
  if(n == NULL) return 0;
  return process(n->left) + process(n->right) + 1;
}

template <typename KeyT,typename MappedT, typename CompareT >
std::pair<KeyT,MappedT> CP::map_bst<KeyT,MappedT,CompareT>::subtree(map_bst<KeyT,MappedT,CompareT> &left, map_bst<KeyT,MappedT,CompareT> &right) {
  //write your code here
  if(mSize == 0) {
    left.clear();
    right.clear();
    return std::pair<KeyT,MappedT>(KeyT(), MappedT());
  }
  left.clear();
  right.clear();
  left.mSize = process(mRoot->left);
  right.mSize = process(mRoot->right);
  left.mRoot = mRoot->left;
  right.mRoot = mRoot->right;
  if(left.mRoot != NULL) left.mRoot->parent = NULL;
  if(right.mRoot != NULL) right.mRoot->parent = NULL;
  mRoot->left = NULL;
  mRoot->right = NULL;
  mSize = 1;
  return std::pair<KeyT,MappedT>(mRoot->data.first, mRoot->data.second);
}

#endif

