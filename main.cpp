/*
 * File: main.cpp
 * Author: Felipe Lopes
 * Created on 27 de Junho de 2016, 19:00
 */

#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include "graph.cpp"

using namespace std;

int main(int argc, char **argv){
	int noc; // numero de conjuntos a ser testados
	int v; // numero de vertices
	int e; // numero de arestas

	if(argc !=2){ 
		cout << "\nForma de uso: c:\nome_programa nome_arquivo " << endl; 
        exit(1);          
    } 
	
	FILE *arq;
	// Opening of the file passed by parameter
	arq = fopen(argv[1], "r");
	if(arq == NULL)
			cout << "Erro, nao foi possivel abrir o arquivo" << endl;
	else{
		fscanf(arq,"%d\n",&noc);	// captura o numero total de conjuntos
		while(noc > 0){
			if((fscanf(arq,"%d %dn", &v, &e))!=EOF){ // captura total de galaxias e buracos de minhoca
				Graph graph;	
				graph.createGraph(v,e);	// Inicializa o grafo
				for(int i=0; i < graph.v; i++){ // Captura coordenadas de origem, destino e o peso
					if((fscanf(arq,"%d %d %dn", &graph.edges[i].source,&graph.edges[i].destiny ,&graph.edges[i].weight))!=EOF);
				}
				if(graph.BellmanFord())	// Executa o algoritmo de Bellman-Ford para verificar se existem ciclos negativos infinitos
					cout << "Possível!" << endl;
				else
					cout << "Impossível!" << endl;
			}
			noc--; // -1 conjunto a ser testado
		}
	}
	return 0;
}