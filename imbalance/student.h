// Your code here
int my_recur(typename CP::map_bst<KeyT,MappedT,CompareT>::node* n, KeyT &result, int &max_imbalance) {
    if(n == nullptr) return 0;
    int left_height = my_recur(n->left, result, max_imbalance);
    int right_height = my_recur(n->right, result, max_imbalance);
    int imbalance = std::abs(left_height - right_height);
    if(imbalance > max_imbalance) {
        max_imbalance = imbalance;
        result = n->data.first;
    } else if(imbalance == max_imbalance) {
        if(n->data.first < result) {
            result = n->data.first;
        }
    }
    return std::max(left_height, right_height) + 1;
}

KeyT getValueOfMostImbalanceNode() {
    // Your code here
    KeyT result = mRoot -> data.first; // Default to root's key
    int max_imbalance = 0;
    my_recur(mRoot, result , max_imbalance);
    return result;
}
