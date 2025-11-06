// Assuming this is a member function of a list-like class
void replace(const T& x,list<T>& y) { // Made y const, as you probably don't want to modify it
  
  auto it = begin();
  while (it != end()) {
    if (*it == x) {
      // Erase 'x'. 'it' now points to the element *after* 'x'.
      it = erase(it); 
      
      // Insert all elements from 'y' *before* the new 'it'
      for (auto yit = y.begin(); yit != y.end(); ++yit) {
        it = insert(it, *yit); // 'it' points to the newly inserted element
        ++it;                 // Manually advance 'it' past the element we just inserted
      }
      // After this, 'it' points to the correct next element to check.
      // We do *not* increment it again, hence the 'while' loop.
    } else {
      // No match? *Then* we increment.
      ++it; 
    }
  }
}