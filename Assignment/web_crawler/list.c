#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

typedef struct node {
    string data;
    struct node *next;
} Node;

typedef struct List_Repr {
    int   length;
    Node *head;
    Node *tail;
} List_Repr;

list list_create(void)
{
    list new = malloc(sizeof(List_Repr));
    new->head = NULL;
    return new;
}


void list_destroy(list L)
{
    Node *new = L->head;
    while (new != NULL)
    {
        Node *temp = new->next;
        free(new);
        new = temp;
    }
    free(L);
}

bool list_is_empty (list n)
{
    return n->length == 0;
}

size_t list_length (list n)
{
    return n->length;
}

void list_push (list S, string T)
{
    Node *new = malloc(sizeof(Node));
    assert(new != NULL);
    new->data = T;
    new->next = S->head;
    S->head = new;
    S->length++;
}

string list_pop (list S)
{
    assert(S->length > 0);
    Node *head = S->head;
    S->head = S->head->next;
    S->length--;
    string d = head->data;
    free(head);
    return d;
}

void list_enqueue (list Q, string v)
{
    Node *new = malloc(sizeof(Node));
    assert(new != NULL);
    new->data = v;
    new->next = NULL;
    if (Q->tail != NULL) {
        Q->tail->next = new;
        Q->tail = new;
    } else {
        Q->head = new;
        Q->tail = new;
    }
    Q->length++;
}

string list_dequeue (list Q)
{
    assert(Q->length > 0);
    Node *p = Q->head;
    Q->head = Q->head->next;
    if (Q->head == NULL) {
        Q->tail = NULL;
    }
    Q->length--;
    string d = p->data;
    free(p);
    return d;
}

Node *makeNode(string n) {
    Node *new = malloc(sizeof(Node));
    assert(new != NULL);
    new->next->data = n;
    new->next = NULL;
    return new;
}

void list_add (list L, string n)
{
    if (list_contains(L, n) == false)
    {
        Node *new = makeNode(n);
        new->next = L->head;
    }
}

void list_remove (list L, string n)
{
    Node *new = L->head;
    int i;
    Node *temp = new;
    for (i = 0; i < L->length ; ++i)
    {
        if (new->data == n)
        {
            temp = new;
            free(temp);
            new = new->next;
        } else
        {
            new = new->next;
        }
    }

}

bool list_contains (list L, string n)
{
    Node *new = L->head;
    int i;
    for (i = 0; i < L->length; ++i)
    {
        if (new->data == n)
            return true;
    }
    return false;
}

