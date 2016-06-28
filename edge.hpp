
/*
 * File: edge.hpp
 * Author: Felipe Lopes
 * Created on 22 de Junho de 2016, 16:27
 */

/*
* Author: Felipe Lopes
* Adicionada coordenada de origem 
* Modified on 27 de junho de 2016, 19:45  
*/

#ifndef EDGE_HPP
#define EDGE_HPP

#include <iostream>

using namespace std;

class Edge{

public:
	int source;	// Coordinate of source
	int weight;	// Weight this edge
	int destiny;// Coordinate of destiny

};

#endif