#ifndef LINKED_LIST
#define LINKED_LIST

#include <stdbool.h>
#include <stddef.h>

typedef struct linkedlist *ll;

ll LLCreate(void);
void LLDestroy(ll);
ll LLAppend(ll, int);
ll LLPrepend(ll, int);
int LLShrink(ll);
int LLShift(ll);

bool LLisempty(ll);
size_t LLlength(ll);
bool LLisordered(ll);
void LLsort(ll);
void LLprint(ll list);

#endif // LINKED_LIST
