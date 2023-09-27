#include <stdbool.h>

#include "lib_graph.h"
#include "graph.h"

/**
 *  g_isCyclical
 *  return true if `g` contains at least one cycle otherwise return false
 *  https://mathworld.wolfram.com/CyclicGraph.html
 */
bool g_isCyclical(graph g)
{
    // TODO: replace this with your code
    // make the compiler happy
    graph new_g = g;
    int i = 0;
    int temp = 0;
    while (i < new_g->size)
    {
        if(new_g->V[i].exists == true)
        {
            for (int j = 0; j < new_g->size; ++j)
            {
                if(i != j && new_g->V[j].exists == true)
                {
                    if(new_g->E[i][j].exists == true)
                    {
                        temp++;
                    }
                }
            }
            if(temp <= 1)
            {
                for (int j = 0; j < new_g->size; ++j)
                {
                    if(i != j && new_g->V[j].exists == true && new_g->E[i][j].exists == true)
                    {
                        g_removeEdge(new_g, i, j);
                    }
                }
                g_removeVertex(new_g, i);
            }
            temp = 0;
        }
        i++;
    }
    i = 0;
    while (i < new_g->size)
    {
        if(new_g->V[i].exists == true)
        {
            for (int j = 0; j < new_g->size; ++j)
            {
                if(i != j && new_g->V[j].exists == true)
                {
                    if(new_g->E[i][j].exists == true)
                    {
                        temp++;
                    }
                }
            }
            if(temp <= 1)
            {
                for (int j = 0; j < new_g->size; ++j)
                {
                    if(i != j && new_g->V[j].exists == true && new_g->E[i][j].exists == true)
                    {
                        g_removeEdge(new_g, i, j);
                    }
                }
                g_removeVertex(new_g, i);
            }

        }
        temp = 0;
        i++;
    }
    i = 0;
    while (i < new_g->size)
    {
        if(new_g->V[i].exists == true)
        {
            for (int j = 0; j < new_g->size; ++j)
            {
                if(i != j && new_g->E[i][j].exists == true)
                {
                    temp++;
                }
            }
            if(temp <= 1)
            {
                for (int j = 0; j < new_g->size; ++j)
                {
                    if(i != j && new_g->E[i][j].exists == true)
                    {
                        g_removeEdge(new_g, i, j);
                    }
                    g_removeVertex(new_g, i);
                }
            }

        }
        temp = 0;
        i++;
    }
    int k = 0;
    while (k < new_g->size && new_g->V[k].exists != true)
    {
        k++;
    }
    if(k < new_g->size)
    {
        return true;
    } else
    {
        return false;
    }
}
