#ifndef GRAPH_H
#define GRAPH_H

#include <stddef.h>

typedef struct Graph Graph;
typedef Graph *graph;

graph  g_create        (size_t);
void   g_destroy       (graph);

void   g_addVertex     (graph, size_t);
void   g_removeVertex  (graph, size_t);
void   g_setVertex     (graph, size_t, double);
double g_getVertex     (graph, size_t);

void   g_addEdge       (graph, size_t, size_t);
void   g_removeEdge    (graph, size_t, size_t);
void   g_setEdge       (graph, size_t, size_t, double);
double g_getEdge       (graph, size_t, size_t);

void   g_show          (graph);
void   g_list          (graph);

size_t g_smallestComponent (graph);
size_t g_largestComponent  (graph);

#endif // GRAPH_H