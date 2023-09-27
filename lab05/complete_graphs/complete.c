#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

#include "lib_graph.h"
#include "graph.h"

/**
 *  g_isComplete
 *  return true if `g` is a "complete graph" otherwise return false
 *  a "complete graph" has an edge between every pair of vertices
 *  https://mathworld.wolfram.com/CompleteGraph.html
 */
bool g_isComplete(graph g)
{
    // TODO: replace this with your code
    // make the compiler happy

    int i;
    int j;
    for (i = 0; i < g->size; ++i)
    {
        if (g->V[i].exists == true)
        {
            for (j = 0; j < g->size; ++j)
            {
                if (i != j)
                {
                    if (g->V[j].exists == true)
                    {
                        if (g->E[i][j].exists == false)
                        {
                            return false;
                        }
                    }
                }
            }
        }

    }
    return true;
}

/**
 *  g_makeComplete
 *  return a "complete graph" of a particular size
 *  a "complete graph" has an edge between every pair of vertices
 *  https://mathworld.wolfram.com/CompleteGraph.html
 */
graph g_makeComplete(size_t size)
{
    // TODO: replace this with your code
    // make the compiler happy
    graph g = g_create(size);
    int i;
    for (i = 0; i < size; ++i)
    {
        g_addVertex(g, i);
    }
    int j;
    int k;
    for (j = 0; j < size; ++j)
    {
        for (k = 0; k < size; ++k)
        {
            if (j != k && g->E[j][k].exists == false)
            {
                g_addEdge(g, j, k);
            }
        }
    }
    return g;
}