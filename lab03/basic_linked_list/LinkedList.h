#ifndef LINKED_LIST
#define LINKED_LIST

typedef struct linkedlist *ll;

ll LLCreate(void);
void LLDestroy(ll);
ll LLAppend(ll, int);
ll LLPrepend(ll, int);
int LLShrink(ll);
int LLShift(ll);

#endif // LINKED_LIST
