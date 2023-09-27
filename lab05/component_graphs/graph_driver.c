#include <stdlib.h>  // for `malloc()` and `realloc()`
#include <stdio.h>   // for `printf()` and `getline()` and `fileno()`
#include <stdbool.h> // for `bool`
#include <stddef.h>  // for `size_t`
#include <unistd.h>  // for `isatty()`
#include <string.h>  // for `strtok()` and `strcasecmp()` and `strlen()`
#include <ctype.h>   // for `isupper()` and `islower()` and `isdigit()`

#include "graph.h"

bool action(graph[]);

int main(int argc, char **argv)
{
    bool cleanup = true;

    for (char **arg = argv; *arg; arg++) {
        if (strcmp(*arg, "--no-cleanup") == 0) {
            cleanup = false;
        }
    }

    // array of (possibly) 26 graphs, accessed via the letters A-Z
    graph graphs[26] = {NULL};

    while (action(graphs));

    // cleanup any dangling graphs just to be safe.
    if (cleanup) {
        for (size_t i = 0; i < 26; i++) {
            if (graphs[i]) {
                g_destroy(graphs[i]);
                graphs[i] = NULL;
            }
        }
    }

    return 0;
}

bool action(graph graphs[])
{
    char  *line = NULL;
    size_t size = 0;
    // print a prompt for the user to interact with
    printf("graph> ");
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
    if (strcasecmp(toks[0], "create") == 0 || strcasecmp(toks[0], "new") == 0) {
        if (tok != 3) {
            printf("Invalid arguments to \"%s\"\n", toks[0]);
            printf("Usage: DLL> %s <LETTER> <Size>\n", toks[0]);
        } else if (strlen(toks[1]) != 1) {
            printf("Invalid arguments to \"%s\"\n", toks[0]);
            printf("Argument 1: Expected a letter ie. \"[a-zA-Z]\", got \"%s\"\n", toks[1]);
        } else {
            char *endpt = NULL;
            long value = strtol(toks[2], &endpt, 10);
            if (*endpt == '\0') {
                if (isupper(toks[1][0])) {
                    if (!graphs[toks[1][0] - 'A']) {
                        graphs[toks[1][0] - 'A'] = g_create(value);
                    } else {
                        printf("Invalid arguments to \"%s\"\n", toks[0]);
                        printf("Argument 1: Graph '%c' is already allocated\n", toks[1][0]);
                    }
                } else if (islower(toks[1][0])) {
                    if (!graphs[toks[1][0] - 'a']) {
                        graphs[toks[1][0] - 'a'] = g_create(value);
                    } else {
                        printf("Invalid arguments to \"%s\"\n", toks[0]);
                        printf("Argument 1: Graph '%c' is already allocated\n", toks[1][0]);
                    }
                } else {
                    printf("Invalid arguments to \"%s\"\n", toks[0]);
                    printf("Argument 1: Expected a letter ie. \"[a-zA-Z]\", got \"%s\"\n", toks[1]);
                }
            } else {
                printf("Invalid arguments to \"%s\"\n", toks[0]);
                printf("Argument 2: Expected a size ie. \"[1-9][0-9]*\", got \"%s\"\n", toks[2]);
            }
        }
    } else if (strcasecmp(toks[0], "destroy") == 0 || strcasecmp(toks[0], "free") == 0) {
        if (tok != 2) {
            printf("Invalid arguments to \"%s\"\n", toks[0]);
            printf("Usage: DLL> %s <LETTER>\n", toks[0]);
        } else if (strlen(toks[1]) != 1) {
            printf("Invalid arguments to \"%s\"\n", toks[0]);
            printf("Argument 1: Expected a letter ie. \"[a-zA-Z]\", got \"%s\"\n", toks[1]);
        } else {
            if (isupper(toks[1][0])) {
                if (graphs[toks[1][0] - 'A']) {
                    g_destroy(graphs[toks[1][0] - 'A']);
                    graphs[toks[1][0] - 'A'] = NULL;
                } else {
                    printf("Invalid arguments to \"%s\"\n", toks[0]);
                    printf("Argument 1: Graph '%c' is already unallocated\n", toks[1][0]);
                }
            } else if (islower(toks[1][0])) {
                if (graphs[toks[1][0] - 'a']) {
                    g_destroy(graphs[toks[1][0] - 'a']);
                    graphs[toks[1][0] - 'a'] = NULL;
                } else {
                    printf("Invalid arguments to \"%s\"\n", toks[0]);
                    printf("Argument 1: Graph '%c' is already unallocated\n", toks[1][0]);
                }
            } else {
                printf("Invalid arguments to \"%s\"\n", toks[0]);
                printf("Argument 1: Expected a letter ie. \"[a-zA-Z]\", got \"%s\"\n", toks[1]);
            }
        }
    } else if (strcasecmp(toks[0], "show") == 0 || strcasecmp(toks[0], "print") == 0) {
        if (tok != 2) {
            printf("Invalid arguments to \"%s\"\n", toks[0]);
            printf("Usage: DLL> %s <LETTER>\n", toks[0]);
        } else if (strlen(toks[1]) != 1) {
            printf("Invalid arguments to \"%s\"\n", toks[0]);
            printf("Argument 1: Expected a letter ie. \"[a-zA-Z]\", got \"%s\"\n", toks[1]);
        } else {
            if (isupper(toks[1][0])) {
                g_show(graphs[toks[1][0] - 'A']);
            } else if (islower(toks[1][0])) {
                g_show(graphs[toks[1][0] - 'a']);
            } else {
                printf("Invalid arguments to \"%s\"\n", toks[0]);
                printf("Argument 1: Expected a letter ie. \"[a-zA-Z]\", got \"%s\"\n", toks[1]);
            }
        }
    } else if (strcasecmp(toks[0], "list") == 0 || strcasecmp(toks[0], "debug") == 0) {
        if (tok != 2) {
            printf("Invalid arguments to \"%s\"\n", toks[0]);
            printf("Usage: DLL> %s <LETTER>\n", toks[0]);
        } else if (strlen(toks[1]) != 1) {
            printf("Invalid arguments to \"%s\"\n", toks[0]);
            printf("Argument 1: Expected a letter ie. \"[a-zA-Z]\", got \"%s\"\n", toks[1]);
        } else {
            if (isupper(toks[1][0])) {
                g_list(graphs[toks[1][0] - 'A']);
            } else if (islower(toks[1][0])) {
                g_list(graphs[toks[1][0] - 'a']);
            } else {
                printf("Invalid arguments to \"%s\"\n", toks[0]);
                printf("Argument 1: Expected a letter ie. \"[a-zA-Z]\", got \"%s\"\n", toks[1]);
            }
        }
    } else if (strcasecmp(toks[0], "addVertex") == 0) {
        if (tok < 3) {
            printf("Invalid number of arguments to \"%s\"\n", toks[0]);
            printf("Usage: DLL> %s <LETTER> <VertexID> [...]\n", toks[0]);
        } else if (strlen(toks[1]) != 1) {
            printf("Invalid arguments to \"%s\"\n", toks[0]);
            printf("Argument 1: Expected a letter ie. \"[a-zA-Z]\", got \"%s\"\n", toks[1]);
        } else {
            for (size_t i = 2; i < tok; i++) {
                char *endpt = NULL;
                long vertex = strtol(toks[i], &endpt, 10);
                if (*endpt != '\0') {
                    printf("Invalid arguments to \"%s\"\n", toks[0]);
                    printf("Argument %zu: Expected a vertex index ie. \"[0-9]+\", got \"%s\"\n", i, toks[i]);
                } else if (isupper(toks[1][0])) {
                    g_addVertex(graphs[toks[1][0] - 'A'], vertex);
                } else if (islower(toks[1][0])) {
                    g_addVertex(graphs[toks[1][0] - 'a'], vertex);
                } else {
                    printf("Invalid arguments to \"%s\"\n", toks[0]);
                    printf("Argument 1: Expected a letter ie. \"[a-zA-Z]\", got \"%s\"\n", toks[1]);
                }
            }
        }
    } else if (strcasecmp(toks[0], "removeVertex") == 0) {
        if (tok < 3) {
            printf("Invalid number of arguments to \"%s\"\n", toks[0]);
            printf("Usage: DLL> %s <LETTER> <VertexID> [...]\n", toks[0]);
        } else if (strlen(toks[1]) != 1) {
            printf("Invalid arguments to \"%s\"\n", toks[0]);
            printf("Argument 1: Expected a letter ie. \"[a-zA-Z]\", got \"%s\"\n", toks[1]);
        } else {
            for (size_t i = 2; i < tok; i++) {
                char *endpt = NULL;
                long vertex = strtol(toks[i], &endpt, 10);
                if (*endpt != '\0') {
                    printf("Invalid arguments to \"%s\"\n", toks[0]);
                    printf("Argument %zu: Expected a vertex index ie. \"[0-9]+\", got \"%s\"\n", i, toks[i]);
                } else if (isupper(toks[1][0])) {
                    g_removeVertex(graphs[toks[1][0] - 'A'], vertex);
                } else if (islower(toks[1][0])) {
                    g_removeVertex(graphs[toks[1][0] - 'a'], vertex);
                } else {
                    printf("Invalid arguments to \"%s\"\n", toks[0]);
                    printf("Argument 1: Expected a letter ie. \"[a-zA-Z]\", got \"%s\"\n", toks[1]);
                }
            }
        }
    } else if (strcasecmp(toks[0], "setVertex") == 0) {
        if (tok < 3) {
            printf("Invalid number of arguments to \"%s\"\n", toks[0]);
            printf("Usage: DLL> %s <LETTER> <VertexID> [...] <DecimalNumber>\n", toks[0]);
        } else if (strlen(toks[1]) != 1) {
            printf("Invalid arguments to \"%s\"\n", toks[0]);
            printf("Argument 1: Expected a letter ie. \"[a-zA-Z]\", got \"%s\"\n", toks[1]);
        } else {
            char *endpt1 = NULL;
            double value = strtod(toks[tok - 1], &endpt1);
            if (*endpt1 != '\0') {
                printf("Invalid arguments to \"%s\"\n", toks[0]);
                printf("Argument %zu: Expected a decimal value ie. \"[0-9]*(\\.[0-9]*)?\", got \"%s\"\n", tok - 1, toks[tok - 1]);
            } else {
                for (size_t i = 2; i < tok - 1; i++) {
                    char *endpt2 = NULL;
                    long vertex = strtol(toks[i], &endpt2, 10);
                    if (*endpt2 != '\0') {
                        printf("Invalid arguments to \"%s\"\n", toks[0]);
                        printf("Argument %zu: Expected a vertex index ie. \"[0-9]+\", got \"%s\"\n", i, toks[i]);
                    } else if (isupper(toks[1][0])) {
                        g_setVertex(graphs[toks[1][0] - 'A'], vertex, value);
                    } else if (islower(toks[1][0])) {
                        g_setVertex(graphs[toks[1][0] - 'a'], vertex, value);
                    } else {
                        printf("Invalid arguments to \"%s\"\n", toks[0]);
                        printf("Argument 1: Expected a letter ie. \"[a-zA-Z]\", got \"%s\"\n", toks[1]);
                    }
                }
            }
        }
    } else if (strcasecmp(toks[0], "getVertex") == 0) {
        if (tok < 3) {
            printf("Invalid number of arguments to \"%s\"\n", toks[0]);
            printf("Usage: DLL> %s <LETTER> <VertexID> [...]\n", toks[0]);
        } else if (strlen(toks[1]) != 1) {
            printf("Invalid arguments to \"%s\"\n", toks[0]);
            printf("Argument 1: Expected a letter ie. \"[a-zA-Z]\", got \"%s\"\n", toks[1]);
        } else {
            for (size_t i = 2; i < tok; i++) {
                char *endpt = NULL;
                long vertex = strtol(toks[i], &endpt, 10);
                if (*endpt != '\0') {
                    printf("Invalid arguments to \"%s\"\n", toks[0]);
                    printf("Argument %zu: Expected a vertex index ie. \"[0-9]+\", got \"%s\"\n", i, toks[i]);
                } else if (isupper(toks[1][0])) {
                    printf("%lf\n", g_getVertex(graphs[toks[1][0] - 'A'], vertex));
                } else if (islower(toks[1][0])) {
                    printf("%lf\n", g_getVertex(graphs[toks[1][0] - 'a'], vertex));
                } else {
                    printf("Invalid arguments to \"%s\"\n", toks[0]);
                    printf("Argument 1: Expected a letter ie. \"[a-zA-Z]\", got \"%s\"\n", toks[1]);
                }
            }
        }
    } else if (strcasecmp(toks[0], "addEdge") == 0) {
        if (tok < 4) {
            printf("Invalid number of arguments to \"%s\"\n", toks[0]);
            printf("Usage: DLL> %s <LETTER> <FromVertexID> <ToVertexID> [...]\n", toks[0]);
        } else if (strlen(toks[1]) != 1) {
            printf("Invalid arguments to \"%s\"\n", toks[0]);
            printf("Argument 1: Expected a letter ie. \"[a-zA-Z]\", got \"%s\"\n", toks[1]);
        } else {
            char *endpt1 = NULL;
            long vertex1 = strtol(toks[2], &endpt1, 10);
            if (*endpt1 != '\0') {
                printf("Invalid arguments to \"%s\"\n", toks[0]);
                printf("Argument 2: Expected a vertex index ie. \"[0-9]+\", got \"%s\"\n", toks[2]);
            } else {
                for (size_t i = 3; i < tok; i++) {
                    char *endpt2 = NULL;
                    long vertex2 = strtol(toks[i], &endpt2, 10);
                    if (*endpt2 != '\0') {
                        printf("Invalid arguments to \"%s\"\n", toks[0]);
                        printf("Argument %zu: Expected a vertex index ie. \"[0-9]+\", got \"%s\"\n", i, toks[i]);
                    } else if (isupper(toks[1][0])) {
                        g_addEdge(graphs[toks[1][0] - 'A'], vertex1, vertex2);
                    } else if (islower(toks[1][0])) {
                        g_addEdge(graphs[toks[1][0] - 'a'], vertex1, vertex2);
                    } else {
                        printf("Invalid arguments to \"%s\"\n", toks[0]);
                        printf("Argument 1: Expected a letter ie. \"[a-zA-Z]\", got \"%s\"\n", toks[1]);
                    }
                }
            }
        }
    } else if (strcasecmp(toks[0], "removeEdge") == 0) {
        if (tok < 4) {
            printf("Invalid number of arguments to \"%s\"\n", toks[0]);
            printf("Usage: DLL> %s <LETTER> <FromVertexID> <ToVertexID> [...]\n", toks[0]);
        } else if (strlen(toks[1]) != 1) {
            printf("Invalid arguments to \"%s\"\n", toks[0]);
            printf("Argument 1: Expected a letter ie. \"[a-zA-Z]\", got \"%s\"\n", toks[1]);
        } else {
            char *endpt1 = NULL;
            long vertex1 = strtol(toks[2], &endpt1, 10);
            if (*endpt1 != '\0') {
                printf("Invalid arguments to \"%s\"\n", toks[0]);
                printf("Argument 2: Expected a vertex index ie. \"[0-9]+\", got \"%s\"\n", toks[2]);
            } else {
                for (size_t i = 3; i < tok; i++) {
                    char *endpt2 = NULL;
                    long vertex2 = strtol(toks[i], &endpt2, 10);
                    if (*endpt2 != '\0') {
                        printf("Invalid arguments to \"%s\"\n", toks[0]);
                        printf("Argument %zu: Expected a vertex index ie. \"[0-9]+\", got \"%s\"\n", i, toks[i]);
                    } else if (isupper(toks[1][0])) {
                        g_removeEdge(graphs[toks[1][0] - 'A'], vertex1, vertex2);
                    } else if (islower(toks[1][0])) {
                        g_removeEdge(graphs[toks[1][0] - 'a'], vertex1, vertex2);
                    } else {
                        printf("Invalid arguments to \"%s\"\n", toks[0]);
                        printf("Argument 1: Expected a letter ie. \"[a-zA-Z]\", got \"%s\"\n", toks[1]);
                    }
                }
            }
        }
    } else if (strcasecmp(toks[0], "setEdge") == 0) {
        if (tok < 5) {
            printf("Invalid number of arguments to \"%s\"\n", toks[0]);
            printf("Usage: DLL> %s <LETTER> <FromVertexID> <ToVertexID> [...] <DecimalNumber>\n", toks[0]);
        } else if (strlen(toks[1]) != 1) {
            printf("Invalid arguments to \"%s\"\n", toks[0]);
            printf("Argument 1: Expected a letter ie. \"[a-zA-Z]\", got \"%s\"\n", toks[1]);
        } else {
            char *endpt0 = NULL;
            double value = strtod(toks[tok - 1], &endpt0);
            char *endpt1 = NULL;
            long vertex1 = strtol(toks[2], &endpt1, 10);
            if (*endpt0 != '\0') {
                printf("Invalid arguments to \"%s\"\n", toks[0]);
                printf("Argument %zu: Expected a vertex index ie. \"[0-9]+\", got \"%s\"\n", tok - 1, toks[tok - 1]);
            } else if (*endpt1 != '\0') {
                printf("Invalid arguments to \"%s\"\n", toks[0]);
                printf("Argument 2: Expected a vertex index ie. \"[0-9]+\", got \"%s\"\n", toks[2]);
            } else {
                for (size_t i = 3; i < tok - 1; i++) {
                    char *endpt2 = NULL;
                    long vertex2 = strtol(toks[i], &endpt2, 10);
                    if (*endpt2 != '\0') {
                        printf("Invalid arguments to \"%s\"\n", toks[0]);
                        printf("Argument %zu: Expected a vertex index ie. \"[0-9]+\", got \"%s\"\n", i, toks[i]);
                    } else if (isupper(toks[1][0])) {
                        g_setEdge(graphs[toks[1][0] - 'A'], vertex1, vertex2, value);
                    } else if (islower(toks[1][0])) {
                        g_setEdge(graphs[toks[1][0] - 'a'], vertex1, vertex2, value);
                    } else {
                        printf("Invalid arguments to \"%s\"\n", toks[0]);
                        printf("Argument 1: Expected a letter ie. \"[a-zA-Z]\", got \"%s\"\n", toks[1]);
                    }
                }
            }
        }
    } else if (strcasecmp(toks[0], "getEdge") == 0) {
        if (tok < 4) {
            printf("Invalid number of arguments to \"%s\"\n", toks[0]);
            printf("Usage: DLL> %s <LETTER> <FromVertexID> <ToVertexID> [...]\n", toks[0]);
        } else if (strlen(toks[1]) != 1) {
            printf("Invalid arguments to \"%s\"\n", toks[0]);
            printf("Argument 1: Expected a letter ie. \"[a-zA-Z]\", got \"%s\"\n", toks[1]);
        } else {
            char *endpt1 = NULL;
            long vertex1 = strtol(toks[2], &endpt1, 10);
            if (*endpt1 != '\0') {
                printf("Invalid arguments to \"%s\"\n", toks[0]);
                printf("Argument 2: Expected a vertex index ie. \"[0-9]+\", got \"%s\"\n", toks[2]);
            } else {
                for (size_t i = 3; i < tok; i++) {
                    char *endpt2 = NULL;
                    long vertex2 = strtol(toks[i], &endpt2, 10);
                    if (*endpt2 != '\0') {
                        printf("Invalid arguments to \"%s\"\n", toks[0]);
                        printf("Argument %zu: Expected a vertex index ie. \"[0-9]+\", got \"%s\"\n", i, toks[i]);
                    } else if (isupper(toks[1][0])) {
                        printf("%lf\n", g_getEdge(graphs[toks[1][0] - 'A'], vertex1, vertex2));
                    } else if (islower(toks[1][0])) {
                        printf("%lf\n", g_getEdge(graphs[toks[1][0] - 'a'], vertex1, vertex2));
                    } else {
                        printf("Invalid arguments to \"%s\"\n", toks[0]);
                        printf("Argument 1: Expected a letter ie. \"[a-zA-Z]\", got \"%s\"\n", toks[1]);
                    }
                }
            }
        }
    } else if (strcasecmp(toks[0], "smallestComponent") == 0) {
        if (tok != 2) {
            printf("Invalid arguments to \"%s\"\n", toks[0]);
            printf("Usage: DLL> %s <LETTER>\n", toks[0]);
        } else if (strlen(toks[1]) != 1) {
            printf("Invalid arguments to \"%s\"\n", toks[0]);
            printf("Argument 1: Expected a letter ie. \"[a-zA-Z]\", got \"%s\"\n", toks[1]);
        } else {
            if (isupper(toks[1][0])) {
                printf("%zu\n", g_smallestComponent(graphs[toks[1][0] - 'A']));
            } else if (islower(toks[1][0])) {
                printf("%zu\n", g_smallestComponent(graphs[toks[1][0] - 'a']));
            } else {
                printf("Invalid arguments to \"%s\"\n", toks[0]);
                printf("Argument 1: Expected a letter ie. \"[a-zA-Z]\", got \"%s\"\n", toks[1]);
            }
        }
    } else if (strcasecmp(toks[0], "largestComponent") == 0) {
        if (tok != 2) {
            printf("Invalid arguments to \"%s\"\n", toks[0]);
            printf("Usage: DLL> %s <LETTER>\n", toks[0]);
        } else if (strlen(toks[1]) != 1) {
            printf("Invalid arguments to \"%s\"\n", toks[0]);
            printf("Argument 1: Expected a letter ie. \"[a-zA-Z]\", got \"%s\"\n", toks[1]);
        } else {
            if (isupper(toks[1][0])) {
                printf("%zu\n", g_largestComponent(graphs[toks[1][0] - 'A']));
            } else if (islower(toks[1][0])) {
                printf("%zu\n", g_largestComponent(graphs[toks[1][0] - 'a']));
            } else {
                printf("Invalid arguments to \"%s\"\n", toks[0]);
                printf("Argument 1: Expected a letter ie. \"[a-zA-Z]\", got \"%s\"\n", toks[1]);
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
