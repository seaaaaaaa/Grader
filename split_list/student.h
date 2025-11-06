void splitList(list<T>& list1, list<T>& list2) {
    // Add your code here
    if (mSize == 0) return;
    node *last_half1 = mHeader;
    int size2 = mSize/2;
    int size1 = mSize - size2;
    for (int i = 0; i < size1; i++) {
        last_half1 = last_half1->next;
    }
    node *first_half2 = last_half1->next;
    node *first_half1 = mHeader->next;
    node *last_half2 = mHeader->prev;

    if(size1 > 0 ) {
        list1.mHeader->prev->next = first_half1;
        first_half1->prev = list1.mHeader->prev;
        list1.mHeader->prev = last_half1;
        last_half1->next = list1.mHeader;
        list1.mSize += size1;
    }

    if(size2>0){
        list2.mHeader->prev->next = first_half2;
        first_half2->prev = list2.mHeader->prev;
        list2.mHeader->prev = last_half2;
        last_half2->next = list2.mHeader;
        list2.mSize += size2;
    }

    mHeader->next = mHeader;
    mHeader->prev = mHeader;
    mSize = 0;
}
