#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

#include "LinkedList.h"

typedef struct linkedlist {
    struct linkedlistnode *head;
} linkedlist;

typedef struct linkedlistnode {
    int data;
    struct linkedlistnode *next;
} linkedlistnode;

ll LLCreate(void)
{
    // TODO: replace this with your code
    // make the compiler happy
    return NULL;
}

void LLDestroy(ll list)
{
    // TODO: replace this with your code
    // make the compiler happy
    (void) list;
}

/**
 * Add an element to the end of the link-list
 */
ll LLAppend(ll list, int item)
{
    // TODO: replace this with your code
    // make the compiler happy
    (void) list;
    (void) item;
    return NULL;
}

/**
 * Add an element to the start of the link-list
 */
ll LLPrepend(ll list, int item)
{
    // TODO: replace this with your code
    // make the compiler happy
    (void) list;
    (void) item;
    return NULL;
}

/**
 * Remove and return the last element from the link-list
 * Or 0 if the list is empty
 */
int LLShrink(ll list)
{
    // TODO: replace this with your code
    // make the compiler happy
    (void) list;
    return 0;
}

/**
 * Remove and return the first element from the link-list
 * Or 0 if the list is empty
 */
int LLShift(ll list)
{
    // TODO: replace this with your code
    // make the compiler happy
    (void) list;
    return 0;
}

/**
 * return `true` if there are no items in the linked-list
 * return `false` otherwise
 */
bool LLisempty(ll list)
{
    // TODO: replace this with your code
    // make the compiler happy
    (void) list;
    return flase;
}

/**
 * return the number of items in the linked-list
 */
size_t LLlength(ll list)
{
    // TODO: replace this with your code
    // make the compiler happy
    (void) list;
    return 0;
}

/**
 * return `true` if the items in the linked-list are in sorted order (accending order)
 * return `false` otherwise
 */
bool LLisordered(ll list)
{
    // TODO: replace this with your code
    // make the compiler happy
    (void) list;
    return false;
}

/**
 * sort the items in the linked-list (inplace, ie. do not create a new list).
 * you can use any sorting algorithm that you like
 */
void LLsort(ll list)
{
    // TODO: replace this with your code
    // make the compiler happy
    (void) list;
}

/**
 * print the items in the linked-list, one per line.
 */
void LLprint(ll list)
{
    // TODO: replace this with your code
    // make the compiler happy
    (void) list;
}
