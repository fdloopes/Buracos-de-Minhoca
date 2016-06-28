/*
 * File: graph.hpp
 * Author: Felipe Lopes
 * Created on 27 de Junho de 2016, 19:46
 */

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include "edge.hpp"

using namespace std;

class Graph{

public:
    int v; // Number of vertices
    int e; // Number of edges
    vector<Edge> edges; // Array of edges

    Graph(); // Constructor this class
    int BellmanFord(); // Bellman-Ford algorithm , search path with minimum weight between a source and a destination, detects negative cycles.
    void createGraph( int nV, int nE); //Initializes the graph.
};

#endif
 