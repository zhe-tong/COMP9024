#include <stdbool.h> // for `bool`
#include <stddef.h>  // for `size_t`
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "DLL.h"

typedef struct DLL {
    struct Node *head;
    struct Node *tail;
} DLL;

typedef struct Node {
    struct Node *prev;
    string       data;
    struct Node *next;
} Node;

typedef struct Node *node;

node createNode(string new)
{
    node newdata = malloc(sizeof(Node));
    newdata->data = malloc(sizeof(char) * (strlen(new) + 1));
    strcpy(newdata->data, new);
    newdata->prev = NULL;
    newdata->next = NULL;

    return newdata;
}
/**
 * allocate memory for a new (empty) doubly linked-list
 */
dll DLLcreate(void)
{
    // TODO: replace this with your code
    // make the compiler happy
    DLL *L = (DLL *)malloc(sizeof(DLL));
    L->head = NULL;
    L->tail = NULL;
    return L;
}

/**
 * free all memory associated with a doubly linked-list
 */
void DLLdestroy(dll list)
{
    // TODO: replace this with your code
    // make the compiler happy
    node new, temp;
    temp = list->head;
    while (temp != NULL) 
    {
        new = temp->next;
        free(temp->data);
        temp = new;
    }
}

/**
 * print the items in the list, one per line.
 */
void DLLshow(dll list)
{
    // TODO: replace this with your code
    // make the compiler happy
    if (list != NULL && list->head != NULL)
    {
        node new;
        new = list->head;
        while (new != NULL)
        {
            printf("%s\n", new->data);
            new = new->next;
        }
    }
}

/**
 * Add an element to the end of the list
 */
dll DLLappend(dll list, string value)
{
    // TODO: replace this with your code
    // make the compiler happy
    if (list != NULL && list->head != NULL)
    {
        Node *new = createNode(value);
        list->tail->next = new;
        new->prev = list->tail;
        list->tail = new;
        return list;
    }
    else
    {
        Node *new = createNode(value);
        list->head = new;
        list->tail = new;
        return list;
    }
    return 0;
}

/**
 * Add an element to the start of the list
 */
dll DLLprepend(dll list, string value) {
    // TODO: replace this with your code
    // make the compiler happy
    if (list == NULL) {
        list = DLLcreate();
    } else {
        Node *new = createNode(value);
        if (list->head == NULL) {
            list->head = new;
            list->tail = new;
        } else {
            node temp = list->head;
            new->prev = temp->prev;
            new->next = temp;
            temp->prev = new;
            list->head = new;
        }
    }
    return 0;
}
/**
 * Remove and return the last element from the list
 * Or NULL if the list is empty
 */
string DLLshrink(dll list)
{
    if (list != NULL && list->head != NULL)
    {
        if (list->head != list->tail && list->tail != NULL)
        {
            Node *temp = list->tail;
            list->tail = temp->prev;
            temp->prev->next = temp->next;
            struct Node *temp1 = createNode(temp->data);
            free(temp);
            return temp1->data;
        }
        if (list->head == list->tail)
        {
            Node *temp = list->head;
            list->head = NULL;
            list->tail = NULL;
            struct Node *temp1 = createNode(temp->data);
            free(temp);
            return temp1->data;
        }
    }
    else
    {
        return NULL;
    }
    return 0;
}

/**
 * Remove and return the first element from the list
 * Or NULL if the list is empty
 */
string DLLshift(dll list)
{
    if (list != NULL && list->head != NULL) {
        if (list->head != list->tail)
        {
            Node *temp = list->head;
            list->head = temp->next;
            temp->next->prev = temp->prev;
            struct Node *temp1 = createNode(temp->data);
            free(temp);
            return temp1->data;
        }
        if (list->head == list->tail && list->head != NULL) {
            Node *temp = list->head;
            list->head = NULL;
            list->tail = NULL;
            struct Node *temp1 = createNode(temp->data);
            free(temp);
            return temp1->data;
        }
    } else
    {
        return NULL;
    }
    return 0;
}



