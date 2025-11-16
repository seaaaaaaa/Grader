
#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "map_bst.h"
#include <vector>


template <typename KeyT,
          typename MappedT,
          typename CompareT>
typename CP::map_bst<KeyT,MappedT,CompareT>::iterator CP::map_bst<KeyT,MappedT,CompareT>::recursive(node* n,CP::map_bst<KeyT,MappedT,CompareT>::iterator p, CP::map_bst<KeyT,MappedT,CompareT>::iterator q) const
{
    // You may need this function
     KeyT data = n->data.first;
    if (mLess(data, p->first) && mLess(data, q->first)){
        return recursive(n->right, p, q);
    }else if(mLess(p->first, data) && mLess(q->first, data)){
        return recursive(n->left, p, q);
    }else{
        return n;
    }
}


template <typename KeyT,
          typename MappedT,
          typename CompareT>
typename CP::map_bst<KeyT,MappedT,CompareT>::iterator CP::map_bst<KeyT,MappedT,CompareT>::lca(CP::map_bst<KeyT,MappedT,CompareT>::iterator p, CP::map_bst<KeyT,MappedT,CompareT>::iterator q) const
{
    // Write your code here
    if(p==q) return p;
    return recursive(mRoot, p, q);
}

#endif
