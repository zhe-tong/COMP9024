/**
* return `true` if there are no items in the list
* return `false` otherwise
*/
bool DLLisEmpty(dll list)
{
    // TODO: replace this with your code
    // make the compiler happy
    struct Node *new = list;
    if (list->head != NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
    (void) list;

}

/**
 * return the number of items in the list
 */
size_t DLLlength(dll list)
{
    // TODO: replace this with your code
    // make the compiler happy
    struct Node *new = list;
    int count = 0;
    while(new != NULL)
    {
        count++;
        new = new->next;
    }
    (void) list;
    return count;
}

/**
 * create a new list, with the same content as an existing list
 *
 * note: apart from DLLcreate() this is the only function that should return a newly allocated DLL struct
 */
dll DLLcopy(dll list)
{
    // TODO: replace this with your code
    // make the compiler happy

}

/**
 * reverse the current list, i.e the last element of the given list become the first element of the returned list.
 */
dll DLLreverse(dll list)
{
    // TODO: replace this with your code
    // make the compiler happy
    (void) list;
    return NULL;
}

/**
 * return `true` if the list is cyclic (eg: https://static.javatpoint.com/ds/images/circular-singly-linked-list.png)
 * return `false` otherwise
 *
 * note: A double linked list can be cyclic in either the forward or backwards direction, you should check both.
 * note: This functions is checking for an invalid state, in all other functions you assume that the list IS NOT cyclic
 */
bool DLLisCyclic(dll list)
{
    // TODO: replace this with your code
    // make the compiler happy
    if(list->head->prev == list->tail && list->tail->next == list->head)
    {
        return true;
    }
    else
    {
        return false;
    }
    (void) list;

}

/**
 * return `true` if the list is mirrored both forwards and backwards
 * return `false` otherwise
 *
 * ie:
 *  for each node `A` the previous node `A->previous` should have `A` as its next node: `A == A->previous->next`
 * and likewise:
 *  for each node `A` the next node `A->next` should have `A` as its previous node: `A == A->next->previous`
 *
 * note: This functions is checking for an invalid state, in all other functions you assume that the list IS consistent
 */
bool DLLisConsistent(dll list)
{
    // TODO: replace this with your code
    // make the compiler happy
    (void) list;
    return false;
}

/**
 * return `true` if the items in the list are in sorted (alphabetically accending) order
 * return `false` otherwise
 */
bool DLLisOrdered(dll list)
{
    // TODO: replace this with your code
    // make the compiler happy
    (void) list;
    return false;
}

/**
 * sort the items in the list.
 * you can use any sorting algorithm that you like
 */
dll DLLsort(dll list)
{
    // TODO: replace this with your code
    // make the compiler happy
    (void) list;
}
