#include <stdlib.h>

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
    ll new = malloc(sizeof(linkedlist));
    new->head = NULL;
    return new;
}


void LLDestroy(ll list)
{
    // TODO: replace this with your code
    // make the compiler happy 
    linkedlistnode *p = list->head;
    linkedlistnode *temp;
    while (p != NULL) {
        temp = p->next;
        free(p);
        p = temp;
    }
    free(list);
}


/**
 * Add an element to the end of the link-list
 */
ll LLAppend(ll list, int item)
{
    // TODO: replace this with your code
    // make the compiler happy
    linkedlistnode *new = malloc(sizeof(linkedlistnode));
    new->data = item;
    new->next = NULL;
    linkedlistnode *first = list->head;
    while (first != NULL)
    {
        first = first->next;
    }
    first = new;
    return list;
}

/**
 * Add an element to the start of the link-list
 */
ll LLPrepend(ll list, int item)
{
    // TODO: replace this with your code
    // make the compiler happy
    linkedlistnode *new = malloc(sizeof(linkedlistnode));
    new->data = item;
    new->next = NULL;
    linkedlistnode *first = list->head;
    new->next = first;
    list->head = new;
    return list;
}

/**
 * Remove and return the last element from the link-list
 * Or 0 if the list is empty
 */
int LLShrink(ll list)
{
    // TODO: replace this with your code
    // make the compiler happy
    linkedlistnode *p;
    p = list;
    while (p->next == NULL) {
        free(p);
    }
    return p;
}

/**
 * Remove and return the first element from the link-list
 * Or 0 if the list is empty
 */
int LLShift(ll list)
{
    // TODO: replace this with your code
    // make the compiler happy
    assert(list != NULL);
    linkedlistnode *head = list;
    list = head->next;
    free(head);
    return list;

}