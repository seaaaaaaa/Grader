#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename KeyT,
          typename MappedT,
          typename CompareT >
CP::map_bst<KeyT,MappedT,CompareT> CP::map_bst<KeyT,MappedT,CompareT>::split(KeyT val) {
  //your code here
  CP::map_bst<KeyT,MappedT,CompareT> result;
  node* n = mRoot;
  if(n->data.first < val){
    while(n->data.first < val){
      if(n->right == NULL) break;
      n = n->right;
      //std::cout << n->data.first << std::endl;
    }
    while(n->data.first >= val){
      if(n->left == NULL) break;
      n = n->left;
      //std::cout << n->data.first << std::endl;
    }
    while(n->data.first < val){
      if(n->right == NULL) break;
      n = n->right;
      //std::cout << n->data.first << std::endl;
    }
  } else {
    while(n->data.first >= val){
      if(n->left == NULL) break;
      n = n->left;
      //std::cout << n->data.first << std::endl;
    }
    while(n->data.first < val){
      if(n->right == NULL) break;
      n = n->right;
      //std::cout << n->data.first << std::endl;
    }
    while(n->data.first >= val){
      if(n->left == NULL) break;
      n = n->left;
      // std::cout << n->data.first << std::endl;
    }
  }
  iterator it(n);
  //std::cout << it->first << std::endl;
  if(it->first < val) it++;
  std::vector<KeyT> keys;
  for(auto i = it; i!= end(); i++){
    result[i->first] = i->second;
    keys.push_back(i->first);
  }
  for(auto k : keys){
    erase(k);
  }
  return result;
}

#endif
