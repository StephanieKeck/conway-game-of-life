// Stephanie Keck
// CS 1412 003
// Project 1
// Header file for linked list logic.

#ifndef ___Framelist_H___
#define ___Framelist_H___

#include "stdheader.h"

typedef char** frame;

struct _node {
	frame f;
	struct _node * next;
};

typedef struct _node node_type;
typedef struct _node * node;

struct _frame_list {
	int columns;
	int rows;
	node head;
	node tail;
};

typedef struct _frame_list list_type;
typedef struct _frame_list * list;

list newList();
void append(list, frame);

#endif