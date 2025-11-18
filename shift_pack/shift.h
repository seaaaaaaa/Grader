void shift(int k) {
	// TODO: Add your code here
	
	if(k < 0){
		k = (-1*k)%mSize;
		for(int i = 0; i < k; i++) {
			node* head = mHeader->next;
			node* tail = mHeader->prev->prev;
			node* shifter = mHeader->prev;
			mHeader->prev = tail;
			tail->next = mHeader;
			head->prev = shifter;
			shifter->next = head;
			shifter->prev = mHeader;
			mHeader->next = shifter;
		}
	} else if(k > 0){
		k = k%mSize;
		for(int i = 0; i < k; i++) {
			node* head = mHeader->next->next;
			node* tail = mHeader->prev;
			node* shifter = mHeader->next;
			tail->next = shifter;
			shifter->prev = tail;
			shifter->next = mHeader;
			mHeader->prev = shifter;
			mHeader->next = head;
			head->prev = mHeader;
		}
	}
}
