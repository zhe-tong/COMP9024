#ifndef LIB_GRAPH_H
#define LIB_GRAPH_H

#include <stdbool.h>
#include <stddef.h>

typedef struct Vertex {
    bool   exists;
    double data;
} Vertex;

typedef Vertex *vertex;

typedef struct Edge {
    bool   exists;
    double data;
} Edge;

typedef Edge *edge;

typedef struct Graph {
    size_t  size;
    Vertex *V;
    Edge  **E;
} Graph;

#endif // LIB_GRAPH_H