// Stephanie Keck
// CS 1412 003
// Project 1
// Implementation of linked list functionality.

#include "stdheader.h"
#include "framelist.h"

list newList() {
	list L = (list) malloc(sizeof(list_type));

	L->columns = 0;
	L-> rows = 0;
	L->head = NULL;
	L->tail = NULL;

	return L;
}

void append(list L, frame arr) {
	node n = (node) malloc(sizeof(node_type));

	n->f = arr;
	if (L->head == NULL) {
		L->head = n;
		L->tail = n;
	} else {
		L->tail->next = n;
		L->tail = n;
	}
}