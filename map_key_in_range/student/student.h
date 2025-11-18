#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include "map_bst_lite.h"

template <typename KeyT,
          typename MappedT,
          typename CompareT>
void CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node* n, const KeyT &a, const KeyT &b, std::vector<MappedT> &result) const {
    // you MAY need to use this function
    if(n == nullptr) return;
     // --- 1. Go Left? ---
    // We only need to visit the left subtree if 'a' (the start of our range)
    // is LESS THAN the current node's key.
    // If a >= n->data.first, no key in the left subtree can be in the range.
    if (mLess(a, n->data.first)) {
        my_recur(n->left, a, b, result);
    }

    // --- 2. Process Current Node ---
    // Check if the current node's key is within the range [a, b].
    // We check: (key >= a) AND (key <= b)
    // Using mLess, this is: (!mLess(key, a)) AND (!mLess(b, key))
    if (!mLess(n->data.first, a) && !mLess(b, n->data.first)) {
        result.push_back(n->data.second);
    }

    // --- 3. Go Right? ---
    // We only need to visit the right subtree if 'b' (the end of our range)
    // is GREATER THAN the current node's key.
    // If b <= n->data.first, no key in the right subtree can be in the range.
    if (mLess(n->data.first, b)) {
        my_recur(n->right, a, b, result);
    }
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
std::vector<MappedT> CP::map_bst<KeyT, MappedT, CompareT>::value_in_key_range(const KeyT &a, const KeyT &b) const {
	/* write your code here */
    std::vector<MappedT> result;
    my_recur(mRoot, a, b, result);
    return result;
}

#endif
