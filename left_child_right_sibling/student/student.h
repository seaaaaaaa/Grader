// You may include library here

int depth(node *n)
{
  // Write Code Here
  if(n == nullptr) return -1;
  max_depth = -1;
  node* current_child = n->left_child;
  while(current_child != nullptr) {
    int child_depth = depth(current_child);
    max_depth = std::max(max_depth, child_depth);
    current_child = current_child->right_sibling;
  }
  return max_depth + 1;
}