//
// Created by x1 doa on 25.12.2019.
//

#ifndef ASSIGNMENT3_LINKED_LIST_H
#define ASSIGNMENT3_LINKED_LIST_H
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
//Creating a new type

typedef void * pVoid;


// Creating Node
struct Node_Structure
{
    /*void pointer*/
    pVoid iData;

    /*Node Pointer*/
    struct Node_Structure *pNextNode;
};


// Define the new type Node and Node pointer
typedef struct Node_Structure Node, * NodePointer;

// Sort the linked list via merge sort

void MergeSort(NodePointer * headRef, bool (*compare)(pVoid, pVoid));
/* Pass the reference of the head pointer of a list and
   an data. This function use to add the node at the front */
int insert_at_front(NodePointer *pHead, void *InputData, int SizeofData);

/* Pass the reference of the tail pointer of a list and
   an data. This function use to add the node at the end*/
int append_node(NodePointer *pHead, NodePointer *pTail, void *InputData, int SizeofData);


/* Pass the reference of the head pointer of a list. This function use
to free the all allocated memory*/
void free_allocated_memory(NodePointer  *pHead);

NodePointer return_node_pointer(NodePointer pHead, int place);
#endif //ASSIGNMENT3_LINKED_LIST_H
