#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm> // For std::max

template <typename KeyT, typename MappedT, typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node* n, int &aux) {
    // This function calculates the "height" of the subtree rooted at 'n'
    // and simultaneously updates 'aux' to store the maximum distance
    // (diameter) found so far.

    // We define "height" as the maximum number of *edges* from 'n'
    // to a leaf.
    // - A nullptr node has a height of -1.
    // - A leaf node (with no children) has a height of 0.

    // 1. Base Case: A null node has no path and height -1.
    if (n == nullptr) {
        return -1;
    }

    // 2. Recursively find the height of the left and right subtrees.
    //    'aux' will be updated by these calls if a larger diameter
    //    is found *entirely within* the left or right subtree.
    int left_height = my_recur(n->left, aux);
    int right_height = my_recur(n->right, aux);

    // 3. Calculate the longest path that *passes through* this node 'n'.
    //    This is (1 + height of left subtree) + (1 + height of right subtree).
    //    This simplifies to: left_height + right_height + 2
    int distance_through_n = left_height + right_height + 2;

    // 4. Update the maximum distance ('aux')
    //    The diameter is the largest value seen so far, which is
    //    either the existing 'aux' (from a subtree) or the
    //    newly calculated path that passes through 'n'.
    aux = std::max(aux, distance_through_n);

    // 5. Return the height of the current node 'n'.
    //    The height is 1 (for the edge to its furthest child) plus the
    //    maximum of its children's heights.
    return 1 + std::max(left_height, right_height);
}

template <typename KeyT, typename MappedT, typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::furthest_distance() {
    // Handle the constraint for an empty tree.
    if (mRoot == nullptr || mSize == 0) {
        return -1;
    }

    // Handle the constraint for a single-node tree.
    // NOTE: Our recursive function actually handles this case
    // correctly if we initialize max_distance to 0, but
    // checking it here is also fine and very clear.
    if (mSize == 1) {
        return 0;
    }

    // 'max_distance' will be passed by reference to the recursive
    // function and will be updated to hold the diameter.
    // We initialize it to 0, which correctly handles the
    // single-node case (left_h = -1, right_h = -1, dist = -1 + -1 + 2 = 0).
    int max_distance = 0;
    
    // Call the recursive helper, starting at the root.
    my_recur(mRoot, max_distance);

    // Return the final result stored in max_distance.
    return max_distance;
}

#endif