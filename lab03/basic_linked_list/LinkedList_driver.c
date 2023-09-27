#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "LinkedList.h"

int main(int argc, char **argv)
{
    int num, count = 0;
    ll list = LLCreate();

    while (scanf("%d", &num)) {
        if (argc > 1 && atoi(argv[1]) & 1) {
            LLPrepend(list, num);
        } else {
            LLAppend(list, num);
        }
        count++;
    }

    while(count) {
        if (argc > 1 && atoi(argv[1]) & 2) {
            printf("%d\n", LLShift(list));
        } else {
            printf("%d\n", LLShrink(list));
        }
        count--;
    }

    LLDestroy(list);
    return 0;
}
