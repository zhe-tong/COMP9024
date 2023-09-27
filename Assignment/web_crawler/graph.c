#include "graph.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#define MaxVertices 100

typedef struct{
    string adjvex;
    struct node* next;
} EdgeNode;


typedef struct{
    string vertex;
    struct EdgeNode* edgenext;
}VertexNode;

typedef VertexNode Adjlist[MaxVertices];

typedef struct Graph_Repr{
    Adjlist adjlist;
    int n, e;
}Graph_Repr;

graph graph_create (void)
{
    graph new;
    new = (graph)malloc(sizeof(graph));
    new->n = 0;
    new->e = 0;
    return new;
}

void graph_destroy (graph G)
{
    free(G);
}

void graph_show (graph G, FILE *file)
{

}

void graph_add_vertex (graph G, string vertex)
{
    VertexNode *new = (VertexNode)malloc(sizeof(VertexNode));
    new->vertex = vertex;
    new->edgenext = G->adjlist->vertex
}

bool graph_has_vertex (graph G, string vertex)
{
    if (G->n>0){
        return true;
    } else{
        return false;
    }
}

void graph_remove_vertex (graph G, string vertex)
{

}
