#include <stdlib.h>  // for `malloc()` and `realloc()`
#include <stdio.h>   // for `printf()` and `getline()` and `fileno()`
#include <stdbool.h> // for `bool`
#include <stddef.h>  // for `size_t`
#include <unistd.h>  // for `isatty()`
#include <string.h>  // for `strtok()` and `strcasecmp()` and `strlen()`
#include <ctype.h>   // for `isupper()` and `islower()` and `isdigit()`

#include "DLL.h"

bool action(dll[]);

int main(int argc, char **argv)
{
    bool cleanup = true;

    for (char **arg = argv; *arg; arg++) {
        if (strcmp(*arg, "--no-cleanup") == 0) {
            cleanup = false;
        }
    }

    // array of (possibly) 26 lists, accessed via the letters A-Z
    dll lists[26] = {NULL};

    while (action(lists));

    // cleanup any dangling lists just to be safe.
    if (cleanup) {
        for (size_t i = 0; i < 26; i++) {
            if (lists[i]) {
                DLLdestroy(lists[i]);
                lists[i] = NULL;
            }
        }
    }

    return 0;
}

bool action(dll lists[])
{
    char  *line = NULL;
    size_t size = 0;
    // print a prompt for the user to interact with
    printf("DLL> ");
    // getline() will allocate and return a string from stdin up until the first newline.
    ssize_t length = getline(&line, &size, stdin);
    // Do fun stuff to make autotest look more logical
    if (!isatty(fileno(stdin))) printf("%s", line);

    if (length == -1) {
        // EOF or error, either way lets just abort
        free(line);
        return false;
    } else if (length == 0 || length == 1) {
        // empty line without or with a newline, either way ignore it and try again
        free(line);
        return true;
    }

    // split the line into an array of words
    size_t  tok = 1;
    char **toks = malloc(tok * sizeof(*toks));
    toks[tok-1] = strtok(line, " \t\n");
    char *t = NULL;
    while ((t = strtok(NULL, " \t\n"))) {
        tok++;
        toks = realloc(toks, tok * sizeof(*toks));
        toks[tok-1] = t;
    }

    // case-insensitive comparisons to find the command we want to run
    // my kingdom for a lambda
    if (strcasecmp(toks[0], "create") == 0 || strcasecmp(toks[0], "new") == 0) {
        if (tok != 2 || strlen(toks[1]) != 1) {
            printf("Invalid arguments to \"%s\"\n", toks[0]);
            printf("Usage: DLL> %s <LETTER>\n", toks[0]);
        } else {
            if (isupper(toks[1][0])) {
                if (!lists[toks[1][0] - 'A']) {
                    lists[toks[1][0] - 'A'] = DLLcreate();
                } else {
                    printf("Invalid arguments to \"%s\"\n", toks[0]);
                    printf("LETTER '%c' already allocated\n", toks[1][0]);
                }
            } else if (islower(toks[1][0])) {
                if (!lists[toks[1][0] - 'a']) {
                    lists[toks[1][0] - 'a'] = DLLcreate();
                } else {
                    printf("Invalid arguments to \"%s\"\n", toks[0]);
                    printf("LETTER '%c' already allocated\n", toks[1][0]);
                }
            } else if (isdigit(toks[1][0])) {
                if (!lists[toks[1][0] - '0']) {
                    lists[toks[1][0] - '0'] = DLLcreate();
                } else {
                    printf("Invalid arguments to \"%s\"\n", toks[0]);
                    printf("LETTER '%c' already allocated\n", toks[1][0]);
                }
            } else {
                printf("Invalid arguments to \"%s\"\n", toks[0]);
                printf("Usage: DLL> %s <LETTER>\n", toks[0]);
            }
        }
    } else if (strcasecmp(toks[0], "destroy") == 0 || strcasecmp(toks[0], "free") == 0) {
        if (tok != 2 || strlen(toks[1]) != 1) {
            printf("Invalid arguments to \"%s\"\n", toks[0]);
            printf("Usage: DLL> %s <LETTER>\n", toks[0]);
        } else {
            if (isupper(toks[1][0])) {
                if (lists[toks[1][0] - 'A']) {
                    DLLdestroy(lists[toks[1][0] - 'A']);
                    lists[toks[1][0] - 'A'] = NULL;
                } else {
                    printf("Invalid arguments to \"%s\"\n", toks[0]);
                    printf("LETTER '%c' already unallocated\n", toks[1][0]);
                }
            } else if (islower(toks[1][0])) {
                if (lists[toks[1][0] - 'a']) {
                    DLLdestroy(lists[toks[1][0] - 'a']);
                    lists[toks[1][0] - 'a'] = NULL;
                } else {
                    printf("Invalid arguments to \"%s\"\n", toks[0]);
                    printf("LETTER '%c' already unallocated\n", toks[1][0]);
                }
            } else if (isdigit(toks[1][0])) {
                if (lists[toks[1][0] - '0']) {
                    DLLdestroy(lists[toks[1][0] - '0']);
                    lists[toks[1][0] - '0'] = NULL;
                } else {
                    printf("Invalid arguments to \"%s\"\n", toks[0]);
                    printf("LETTER '%c' already unallocated\n", toks[1][0]);
                }
            } else {
                printf("Invalid arguments to \"%s\"\n", toks[0]);
                printf("Usage: DLL> %s <LETTER>\n", toks[0]);
            }
        }
    } else if (strcasecmp(toks[0], "show") == 0 || strcasecmp(toks[0], "print") == 0) {
        if (tok != 2 || strlen(toks[1]) != 1) {
            printf("Invalid arguments to \"%s\"\n", toks[0]);
            printf("Usage: DLL> %s <LETTER>\n", toks[0]);
        } else {
            if (isupper(toks[1][0])) {
                DLLshow(lists[toks[1][0] - 'A']);
            } else if (islower(toks[1][0])) {
                DLLshow(lists[toks[1][0] - 'a']);
            } else if (isdigit(toks[1][0])) {
                DLLshow(lists[toks[1][0] - '0']);
            } else {
                printf("Invalid arguments to \"%s\"\n", toks[0]);
                printf("Usage: DLL> %s <LETTER>\n", toks[0]);
            }
        }
    } else if (strcasecmp(toks[0], "prepend") == 0) {
        if (tok < 3 || strlen(toks[1]) != 1) {
            printf("Invalid arguments to \"%s\"\n", toks[0]);
            printf("Usage: DLL> %s <LETTER> <string>\n", toks[0]);
        } else {
            for (size_t i = 3; i < tok; i++) *(toks[i]-1) = ' ';
            if (isupper(toks[1][0])) {
                DLLprepend(lists[toks[1][0] - 'A'], toks[2]);
            } else if (islower(toks[1][0])) {
                DLLprepend(lists[toks[1][0] - 'a'], toks[2]);
            } else if (isdigit(toks[1][0])) {
                DLLprepend(lists[toks[1][0] - '0'], toks[2]);
            } else {
                printf("Invalid arguments to \"%s\"\n", toks[0]);
                printf("Usage: DLL> %s <LETTER> <string>\n", toks[0]);
            }
        }
    } else if (strcasecmp(toks[0], "append") == 0) {
        if (tok < 3 || strlen(toks[1]) != 1) {
            printf("Invalid arguments to \"%s\"\n", toks[0]);
            printf("Usage: DLL> %s <LETTER> <string>\n", toks[0]);
        } else {
            for (size_t i = 3; i < tok; i++) *(toks[i]-1) = ' ';
            if (isupper(toks[1][0])) {
                DLLappend(lists[toks[1][0] - 'A'], toks[2]);
            } else if (islower(toks[1][0])) {
                DLLappend(lists[toks[1][0] - 'a'], toks[2]);
            } else if (isdigit(toks[1][0])) {
                DLLappend(lists[toks[1][0] - '0'], toks[2]);
            } else {
                printf("Invalid arguments to \"%s\"\n", toks[0]);
                printf("Usage: DLL> %s <LETTER> <string>\n", toks[0]);
            }
        }
    } else if (strcasecmp(toks[0], "shift") == 0) {
        if (tok != 2 || strlen(toks[1]) != 1) {
            printf("Invalid arguments to \"%s\"\n", toks[0]);
            printf("Usage: DLL> %s <LETTER>\n", toks[0]);
        } else {
            if (isupper(toks[1][0])) {
                char *str = DLLshift(lists[toks[1][0] - 'A']);
                printf("%s\n", str);
                free(str);
            } else if (islower(toks[1][0])) {
                char *str = DLLshift(lists[toks[1][0] - 'a']);
                printf("%s\n", str);
                free(str);
            } else if (isdigit(toks[1][0])) {
                char *str = DLLshift(lists[toks[1][0] - '0']);
                printf("%s\n", str);
                free(str);
            } else {
                printf("Invalid arguments to \"%s\"\n", toks[0]);
                printf("Usage: DLL> %s <LETTER>\n", toks[0]);
            }
        }
    } else if (strcasecmp(toks[0], "shrink") == 0) {
        if (tok != 2 || strlen(toks[1]) != 1) {
            printf("Invalid arguments to \"%s\"\n", toks[0]);
            printf("Usage: DLL> %s <LETTER>\n", toks[0]);
        } else {
            if (isupper(toks[1][0])) {
                char *str = DLLshrink(lists[toks[1][0] - 'A']);
                printf("%s\n", str);
                free(str);
            } else if (islower(toks[1][0])) {
                char *str = DLLshrink(lists[toks[1][0] - 'a']);
                printf("%s\n", str);
                free(str);
            } else if (isdigit(toks[1][0])) {
                char *str = DLLshrink(lists[toks[1][0] - '0']);
                printf("%s\n", str);
                free(str);
            } else {
                printf("Invalid arguments to \"%s\"\n", toks[0]);
                printf("Usage: DLL> %s <LETTER>\n", toks[0]);
            }
        }
    } else if (strcasecmp(toks[0], "empty?") == 0) {
        if (tok != 2 || strlen(toks[1]) != 1) {
            printf("Invalid arguments to \"%s\"\n", toks[0]);
            printf("Usage: DLL> %s <LETTER>\n", toks[0]);
        } else {
            if (isupper(toks[1][0])) {
                printf("%s\n", DLLisEmpty(lists[toks[1][0] - 'A']) ? "True" : "False");
            } else if (islower(toks[1][0])) {
                printf("%s\n", DLLisEmpty(lists[toks[1][0] - 'a']) ? "True" : "False");
            } else if (isdigit(toks[1][0])) {
                printf("%s\n", DLLisEmpty(lists[toks[1][0] - '0']) ? "True" : "False");
            } else {
                printf("Invalid arguments to \"%s\"\n", toks[0]);
                printf("Usage: DLL> %s <LETTER>\n", toks[0]);
            }
        }
    } else if (strcasecmp(toks[0], "cyclic?") == 0) {
        if (tok != 2 || strlen(toks[1]) != 1) {
            printf("Invalid arguments to \"%s\"\n", toks[0]);
            printf("Usage: DLL> %s <LETTER>\n", toks[0]);
        } else {
            if (isupper(toks[1][0])) {
                printf("%s\n", DLLisCyclic(lists[toks[1][0] - 'A']) ? "True" : "False");
            } else if (islower(toks[1][0])) {
                printf("%s\n", DLLisCyclic(lists[toks[1][0] - 'a']) ? "True" : "False");
            } else if (isdigit(toks[1][0])) {
                printf("%s\n", DLLisCyclic(lists[toks[1][0] - '0']) ? "True" : "False");
            } else {
                printf("Invalid arguments to \"%s\"\n", toks[0]);
                printf("Usage: DLL> %s <LETTER>\n", toks[0]);
            }
        }
    } else if (strcasecmp(toks[0], "consistent?") == 0) {
        if (tok != 2 || strlen(toks[1]) != 1) {
            printf("Invalid arguments to \"%s\"\n", toks[0]);
            printf("Usage: DLL> %s <LETTER>\n", toks[0]);
        } else {
            if (isupper(toks[1][0])) {
                printf("%s\n", DLLisConsistent(lists[toks[1][0] - 'A']) ? "True" : "False");
            } else if (islower(toks[1][0])) {
                printf("%s\n", DLLisConsistent(lists[toks[1][0] - 'a']) ? "True" : "False");
            } else if (isdigit(toks[1][0])) {
                printf("%s\n", DLLisConsistent(lists[toks[1][0] - '0']) ? "True" : "False");
            } else {
                printf("Invalid arguments to \"%s\"\n", toks[0]);
                printf("Usage: DLL> %s <LETTER>\n", toks[0]);
            }
        }
    } else if (strcasecmp(toks[0], "ordered?") == 0 || strcasecmp(toks[0], "sorted?") == 0) {
        if (tok != 2 || strlen(toks[1]) != 1) {
            printf("Invalid arguments to \"%s\"\n", toks[0]);
            printf("Usage: DLL> %s <LETTER>\n", toks[0]);
        } else {
            if (isupper(toks[1][0])) {
                printf("%s\n", DLLisOrdered(lists[toks[1][0] - 'A']) ? "True" : "False");
            } else if (islower(toks[1][0])) {
                printf("%s\n", DLLisOrdered(lists[toks[1][0] - 'a']) ? "True" : "False");
            } else if (isdigit(toks[1][0])) {
                printf("%s\n", DLLisOrdered(lists[toks[1][0] - '0']) ? "True" : "False");
            } else {
                printf("Invalid arguments to \"%s\"\n", toks[0]);
                printf("Usage: DLL> %s <LETTER>\n", toks[0]);
            }
        }
    } else if (strcasecmp(toks[0], "length") == 0) {
        if (tok != 2 || strlen(toks[1]) != 1) {
            printf("Invalid arguments to \"%s\"\n", toks[0]);
            printf("Usage: DLL> %s <LETTER>\n", toks[0]);
        } else {
            if (isupper(toks[1][0])) {
                printf("%zu\n", DLLlength(lists[toks[1][0] - 'A']));
            } else if (islower(toks[1][0])) {
                printf("%zu\n", DLLlength(lists[toks[1][0] - 'a']));
            } else if (isdigit(toks[1][0])) {
                printf("%zu\n", DLLlength(lists[toks[1][0] - '0']));
            } else {
                printf("Invalid arguments to \"%s\"\n", toks[0]);
                printf("Usage: DLL> %s <LETTER>\n", toks[0]);
            }
        }
    } else if (strcasecmp(toks[0], "sort") == 0) {
        if (tok != 2 || strlen(toks[1]) != 1) {
            printf("Invalid arguments to \"%s\"\n", toks[0]);
            printf("Usage: DLL> %s <LETTER>\n", toks[0]);
        } else {
            if (isupper(toks[1][0])) {
                lists[toks[1][0] - 'A'] = DLLsort(lists[toks[1][0] - 'A']);
            } else if (islower(toks[1][0])) {
                lists[toks[1][0] - 'a'] = DLLsort(lists[toks[1][0] - 'a']);
            } else if (isdigit(toks[1][0])) {
                lists[toks[1][0] - '0'] = DLLsort(lists[toks[1][0] - '0']);
            } else {
                printf("Invalid arguments to \"%s\"\n", toks[0]);
                printf("Usage: DLL> %s <LETTER>\n", toks[0]);
            }
        }
    } else if (strcasecmp(toks[0], "reverse") == 0) {
        if (tok != 2 || strlen(toks[1]) != 1) {
            printf("Invalid arguments to \"%s\"\n", toks[0]);
            printf("Usage: DLL> %s <LETTER>\n", toks[0]);
        } else {
            if (isupper(toks[1][0])) {
                lists[toks[1][0] - 'A'] = DLLreverse(lists[toks[1][0] - 'A']);
            } else if (islower(toks[1][0])) {
                lists[toks[1][0] - 'a'] = DLLreverse(lists[toks[1][0] - 'a']);
            } else if (isdigit(toks[1][0])) {
                lists[toks[1][0] - '0'] = DLLreverse(lists[toks[1][0] - '0']);
            } else {
                printf("Invalid arguments to \"%s\"\n", toks[0]);
                printf("Usage: DLL> %s <LETTER>\n", toks[0]);
            }
        }
    } else if (strcasecmp(toks[0], "copy") == 0) {
        if (tok != 3 || strlen(toks[1]) != 1 || strlen(toks[2]) != 1 || toks[1][0] == toks[2][0]) {
            printf("Invalid arguments to \"%s\"\n", toks[0]);
            printf("Usage: DLL> %s <LETTER> <LETTER>\n", toks[0]);
        } else {
            if (isupper(toks[1][0])) {
                if (isupper(toks[2][0])) {
                    lists[toks[2][0] - 'A'] = DLLcopy(lists[toks[1][0] - 'A']);
                } else if (islower(toks[2][0])) {
                    lists[toks[2][0] - 'a'] = DLLcopy(lists[toks[1][0] - 'A']);
                } else if (isdigit(toks[2][0])) {
                    lists[toks[2][0] - '0'] = DLLcopy(lists[toks[1][0] - 'A']);
                } else {
                    printf("Invalid arguments to \"%s\"\n", toks[0]);
                    printf("Usage: DLL> %s <LETTER>\n", toks[0]);
                }
            } else if (islower(toks[1][0])) {
                if (isupper(toks[2][0])) {
                    lists[toks[2][0] - 'A'] = DLLcopy(lists[toks[1][0] - 'a']);
                } else if (islower(toks[2][0])) {
                    lists[toks[2][0] - 'a'] = DLLcopy(lists[toks[1][0] - 'a']);
                } else if (isdigit(toks[2][0])) {
                    lists[toks[2][0] - '0'] = DLLcopy(lists[toks[1][0] - 'a']);
                } else {
                    printf("Invalid arguments to \"%s\"\n", toks[0]);
                    printf("Usage: DLL> %s <LETTER>\n", toks[0]);
                }
            } else if (isdigit(toks[1][0])) {
                if (isupper(toks[2][0])) {
                    lists[toks[2][0] - 'A'] = DLLreverse(lists[toks[1][0] - '0']);
                } else if (islower(toks[2][0])) {
                    lists[toks[2][0] - 'a'] = DLLreverse(lists[toks[1][0] - '0']);
                } else if (isdigit(toks[2][0])) {
                    lists[toks[2][0] - '0'] = DLLreverse(lists[toks[1][0] - '0']);
                } else {
                    printf("Invalid arguments to \"%s\"\n", toks[0]);
                    printf("Usage: DLL> %s <LETTER> <LETTER>\n", toks[0]);
                }
            } else {
                printf("Invalid arguments to \"%s\"\n", toks[0]);
                printf("Usage: DLL> %s <LETTER> <LETTER>\n", toks[0]);
            }
        }
    } else if (strcasecmp(toks[0], "CreateCycle") == 0) {
        if (tok != 4 || strlen(toks[1]) != 1) {
            printf("Invalid arguments to \"%s\"\n", toks[0]);
            printf("Usage: DLL> %s <LETTER> <INDEX> <INDEX>\n", toks[0]);
        } else {
            size_t index1;
            {
                char *endpt = NULL;
                index1 = strtol(toks[2], &endpt, 10);
                if (*endpt != '\0') {
                    printf("Invalid arguments to \"%s\"\n", toks[0]);
                    printf("Usage: DLL> %s <LETTER> <INDEX> <INDEX>\n", toks[0]);
                    free(toks);
                    free(line);
                    return true;
                }
            }
            size_t index2;
            {
                char *endpt = NULL;
                index2 = strtol(toks[3], &endpt, 10);
                if (*endpt != '\0') {
                    printf("Invalid arguments to \"%s\"\n", toks[0]);
                    printf("Usage: DLL> %s <LETTER> <INDEX> <INDEX>\n", toks[0]);
                    free(toks);
                    free(line);
                    return true;
                }
            }
            if (isupper(toks[1][0])) {
                DLLcreateCycle(lists[toks[1][0] - 'A'], index1, index2);
            } else if (islower(toks[1][0])) {
                DLLcreateCycle(lists[toks[1][0] - 'a'], index1, index2);
            } else if (isdigit(toks[1][0])) {
                DLLcreateCycle(lists[toks[1][0] - '0'], index1, index2);
            } else {
                printf("Invalid arguments to \"%s\"\n", toks[0]);
                printf("Usage: DLL> %s <LETTER> <INDEX> <INDEX>\n", toks[0]);
            }
        }
    } else if (strcasecmp(toks[0], "CreateForwardInconsistency") == 0) {
        if (tok != 4 || strlen(toks[1]) != 1) {
            printf("Invalid arguments to \"%s\"\n", toks[0]);
            printf("Usage: DLL> %s <LETTER> <INDEX> <INDEX>\n", toks[0]);
        } else {
            size_t index1;
            {
                char *endpt = NULL;
                index1 = strtol(toks[2], &endpt, 10);
                if (*endpt != '\0') {
                    printf("Invalid arguments to \"%s\"\n", toks[0]);
                    printf("Usage: DLL> %s <LETTER> <INDEX> <INDEX>\n", toks[0]);
                    free(toks);
                    free(line);
                    return true;
                }
            }
            size_t index2;
            {
                char *endpt = NULL;
                index2 = strtol(toks[3], &endpt, 10);
                if (*endpt != '\0') {
                    printf("Invalid arguments to \"%s\"\n", toks[0]);
                    printf("Usage: DLL> %s <LETTER> <INDEX> <INDEX>\n", toks[0]);
                    free(toks);
                    free(line);
                    return true;
                }
            }
            if (isupper(toks[1][0])) {
                DLLcreateForwardInconsistency(lists[toks[1][0] - 'A'], index1, index2);
            } else if (islower(toks[1][0])) {
                DLLcreateForwardInconsistency(lists[toks[1][0] - 'a'], index1, index2);
            } else if (isdigit(toks[1][0])) {
                DLLcreateForwardInconsistency(lists[toks[1][0] - '0'], index1, index2);
            } else {
                printf("Invalid arguments to \"%s\"\n", toks[0]);
                printf("Usage: DLL> %s <LETTER> <INDEX> <INDEX>\n", toks[0]);
            }
        }
    } else if (strcasecmp(toks[0], "CreateBackwardsInconsistency") == 0) {
        if (tok != 4 || strlen(toks[1]) != 1) {
            printf("Invalid arguments to \"%s\"\n", toks[0]);
            printf("Usage: DLL> %s <LETTER> <INDEX> <INDEX>\n", toks[0]);
        } else {
            size_t index1;
            {
                char *endpt = NULL;
                index1 = strtol(toks[2], &endpt, 10);
                if (*endpt != '\0') {
                    printf("Invalid arguments to \"%s\"\n", toks[0]);
                    printf("Usage: DLL> %s <LETTER> <INDEX> <INDEX>\n", toks[0]);
                    free(toks);
                    free(line);
                    return true;
                }
            }
            size_t index2;
            {
                char *endpt = NULL;
                index2 = strtol(toks[3], &endpt, 10);
                if (*endpt != '\0') {
                    printf("Invalid arguments to \"%s\"\n", toks[0]);
                    printf("Usage: DLL> %s <LETTER> <INDEX> <INDEX>\n", toks[0]);
                    free(toks);
                    free(line);
                    return true;
                }
            }
            if (isupper(toks[1][0])) {
                DLLcreateBackwardsInconsistency(lists[toks[1][0] - 'A'], index1, index2);
            } else if (islower(toks[1][0])) {
                DLLcreateBackwardsInconsistency(lists[toks[1][0] - 'a'], index1, index2);
            } else if (isdigit(toks[1][0])) {
                DLLcreateBackwardsInconsistency(lists[toks[1][0] - '0'], index1, index2);
            } else {
                printf("Invalid arguments to \"%s\"\n", toks[0]);
                printf("Usage: DLL> %s <LETTER> <INDEX> <INDEX>\n", toks[0]);
            }
        }
    } else if (strcasecmp(toks[0], "quit") == 0 || strcasecmp(toks[0], "exit") == 0) {
        free(toks);
        free(line);
        return false;
    } else {
        printf("Unknown command: \"%s\"\n", toks[0]);
    }

    free(toks);
    free(line);
    return true;
}
