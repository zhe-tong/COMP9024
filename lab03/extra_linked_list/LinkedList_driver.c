#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "LinkedList.h"

int main(int argc, char **argv)
{
    int num, count = 0;
    ll list = LLCreate();

    printf("list has %lu items\n", LLlength(list));
    printf("list %s empty\n", LLisempty(list) ? "is" : "is not");
    printf("list %s in order\n", LLisordered(list) ? "is" : "is not");

    while (scanf("%d", &num)) {
        if (argc > 1 && atoi(argv[1]) & 1) {
            LLPrepend(list, num);
        } else {
            LLAppend(list, num);
        }
        count++;
    }

    printf("list has %lu items\n", LLlength(list));
    printf("list %s empty\n", LLisempty(list) ? "is" : "is not");
    printf("list %s in order\n", LLisordered(list) ? "is" : "is not");

    LLsort(list);
    LLprint(list);

    printf("list has %lu items\n", LLlength(list));
    printf("list %s empty\n", LLisempty(list) ? "is" : "is not");
    printf("list %s in order\n", LLisordered(list) ? "is" : "is not");

    LLDestroy(list);
    return 0;
}
