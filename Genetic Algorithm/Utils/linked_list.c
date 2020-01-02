//
// Created by x1 doa on 25.12.2019.
//

#include "linked_list.h"
#include <stdio.h>


int insert_at_front(NodePointer *pHead, void *InputData, int SizeofData) {
    int iRetValue = -1;
    int iOffSet = 0;

    NodePointer pNewNode = NULL;

    // Call malloc to allocate memory in heap for the new node
    pNewNode = malloc(sizeof(Node));

    if (pNewNode != NULL) //Check allocated memory
    {

        pNewNode->iData = malloc(SizeofData); //put the desire Data

        //Copy the bytes of data as per the data types

        for (iOffSet = 0; iOffSet < SizeofData; iOffSet++)
            *((uint8_t *) (pNewNode->iData + iOffSet)) = *((uint8_t *) (InputData + iOffSet));


        pNewNode->pNextNode = NULL; //Give the Address of first Node

        iRetValue = 0; // Update the return value

    }

    pNewNode->pNextNode = *pHead;
    *pHead = pNewNode;
    return iRetValue;
}

int append_node(NodePointer *pHead, NodePointer *pTail, void *InputData, int SizeofData){
    int iRetValue = -1;
    int iOffSet = 0;

    NodePointer pNewNode = NULL;

    // Call malloc to allocate memory in heap for the new node
    pNewNode = malloc(sizeof(Node));

    if (pNewNode != NULL) //Check allocated memory
    {

        pNewNode->iData = malloc(SizeofData); //put the desire Data

        //Copy the bytes of data as per the data types

        for (iOffSet = 0; iOffSet < SizeofData; iOffSet++)
            *((uint8_t *) (pNewNode->iData + iOffSet)) = *((uint8_t *) (InputData + iOffSet));


        pNewNode->pNextNode = NULL; //Give the Address of first Node

        iRetValue = 0; // Update the return value

    }
    if (*pHead == NULL) {
        *pHead = pNewNode;
        *pTail = pNewNode;
    }
    else {
        (*pTail)->pNextNode = pNewNode;
        *pTail = pNewNode;
    }
    return iRetValue;
}


/*****************************************************************************************************************/


/* function prototypes */
NodePointer SortedMerge(NodePointer a, NodePointer b,  bool (*compare)(pVoid, pVoid));
void FrontBackSplit(NodePointer source,
                    NodePointer * frontRef, NodePointer * backRef);

/* sorts the linked list by changing next pointers (not data) */
void MergeSort(NodePointer * headRef, bool (*compare)(pVoid, pVoid))
{
    NodePointer head = *headRef;
    NodePointer a;
    NodePointer b;

    /* Base case -- length 0 or 1 */
    if ((head == NULL) || (head->pNextNode == NULL)) {
        return;
    }

    /* Split head into 'a' and 'b' sublists */
    FrontBackSplit(head, &a, &b);

    /* Recursively sort the sublists */
    MergeSort(&a, compare);
    MergeSort(&b, compare);

    /* answer = merge the two sorted lists together */
    *headRef = SortedMerge(a, b, compare);
}


NodePointer SortedMerge(NodePointer a, NodePointer b, bool (*compare)(pVoid, pVoid))
{
    NodePointer result = NULL;

    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    /* Pick either a or b, and recur */
    if (compare((pVoid)a, (pVoid)b)) {
        result = a;
        result->pNextNode = SortedMerge(a->pNextNode, b, compare);
    }
    else {
        result = b;
        result->pNextNode = SortedMerge(a, b->pNextNode, compare);
    }
    return (result);
}

/* UTILITY FUNCTIONS */
/* Split the nodes of the given list into front and back halves,
    and return the two lists using the reference parameters.
    If the length is odd, the extra node should go in the front list.
    Uses the fast/slow pointer strategy. */
void FrontBackSplit(NodePointer source,
                    NodePointer * frontRef, NodePointer * backRef)
{
    NodePointer fast;
    NodePointer slow;
    slow = source;
    fast = source->pNextNode;

    /* Advance 'fast' two nodes, and advance 'slow' one node */
    while (fast != NULL) {
        fast = fast->pNextNode;
        if (fast != NULL) {
            slow = slow->pNextNode;
            fast = fast->pNextNode;
        }
    }

    /* 'slow' is before the midpoint in the list, so split it in two
    at that point. */
    *frontRef = source;
    *backRef = slow->pNextNode;
    slow->pNextNode = NULL;
}

/********************************************************************************************/


void free_allocated_memory(NodePointer *pHead) {
    NodePointer pTmpNode = NULL;
    NodePointer pFirstNode = NULL;
    //Assign  the Address of first node
    pFirstNode = *pHead;

/*check if pFirstNode is NULL, then now list is empty,
so assign NULL to head and return.*/
    while (pFirstNode != NULL) {
        /*Save the pFirstNode in a pTmpNode node pointer*/

        pTmpNode = pFirstNode;

        /*Assign the address of next on your list*/
        pFirstNode = pFirstNode->pNextNode;

        //Free the data
        free(pTmpNode->iData);
        //Free the allocated memory
        free(pTmpNode);

    }
    //Assign NULL to the head pointer
    *pHead = NULL;

}

NodePointer return_node_pointer(NodePointer pHead, int place) {
    NodePointer current = pHead;
    for (int i = 0; i < place; i++)
        current = current->pNextNode;
    return current;
}






