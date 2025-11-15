#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "list.h"

template <typename T>
void CP::list<T>::block_swap(iterator a1, iterator a2, iterator b1, iterator b2) {
	// write your code here
	if(a1 == a2 && b1 == b2) return;
	node* starta = a1.ptr->prev;
	node* enda = a2.ptr;
	node* lasta = a2.ptr->prev;
	node* startb = b1.ptr->prev;
	node* endb = b2.ptr;
	node* lastb = b2.ptr->prev;

	if(a2==b1){
		enda = a1.ptr;
		startb = a2.ptr->prev;
	} else if(b2==a1){
		endb = b1.ptr;
		starta = b2.ptr->prev;
	}

	if(a1!=a2){
		startb->next = a1.ptr;
		a1.ptr->prev = startb;
		endb->prev = lasta;
		lasta->next = endb;
	}
	if(b1!=b2){
		starta->next = b1.ptr;
		b1.ptr->prev = starta;
		enda->prev = lastb;
		lastb->next = enda;
	}
	
	
	

}

#endif
