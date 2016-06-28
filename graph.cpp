/*
 * File: graph.cpp
 * Author: Felipe Lopes
 * Created on 27 de Junho de 2016, 19:46
 */

 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "graph.hpp"
#include "edge.hpp"
 

Graph::Graph(){ 
    // Constructor
}

// Define number of vertices, number of edges and resize array edges
void Graph::createGraph( int nV, int nE){
    this->v = nV;
    this->e = nE;
    this->edges.resize(nE);
}
 
// Bellman-Ford algorithm, search path with minimum weight between a source and a destination, detects negative cycles.
int Graph::BellmanFord(){

    int distance[this->v];
    int source=0;
    int u=0;
    int v=0;
    int weight=0;
 
    // Inicaliza all vertices with infinite weight, except the starting vertex .
    for (int i = 0; i < this->v; i++)
        distance[i] = INT_MAX;
    distance[source] = 0;
 
    // Relax all edges |v|-1 times. A simple shortest 
    // path from source to any other vertex can have at most |v|-1 edges.
    for (int i = 0; i < this->v-1; i++)
    {
        for (int j = 0; j < this->e; j++)
        {
            u = this->edges[j].source;
            v = this->edges[j].destiny;
            weight = this->edges[j].weight;
            if (distance[u] != INT_MAX && distance[v] > distance[u] + weight)
                distance[v] = distance[u] + weight;
        }
    }
 
    // Check for negative-weight cycles.
    for (int i = 0; i < this->e; i++)
    {
        u = this->edges[i].source;
        v = this->edges[i].destiny;
        weight = this->edges[i].weight;

        if (distance[u] != INT_MAX && distance[u] + weight < distance[v]){
            return 1;
        }
    }
    return 0;
}