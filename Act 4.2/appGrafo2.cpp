#include "graph.h"

/*Activid 4.2
* Autor: Francisco Jervis A00835131
* El proposito de esta actividad es representar un grafo y con aplicaciones avanzadas, tales como comprobar si el grafo es un arbol, es bipatrita, u ordenarlo de manera topologica 
* Fecha:11/14/2022
*/

int main() {
	graph G1, G2, G3, G4;
	vector<pairs> pair1 {{1,0},{0,2},{0,3},{3,4}}//tree
		, pair2{ {2,6},{6,0},{3,6},{3,4},{6,5},{6,7},{4,5},{1,4},{1,7} }//Khan
		, pair3 {{0,1},{0,2},{2,3},{3,1}}//Bipartite
		, pair4{{1,0},{0,2},{2,1},{0,3},{3,4}}//no tree
		;
	G1.LoadGraph(5, 4, pair1);
	G2.LoadGraph(8, 9, pair2);
	G3.LoadGraph(4, 4, pair3);
	G4.LoadGraph(5, 5, pair4);

	cout << "Grafos representados en listas de adyacencia:\n\n";
	cout << "Grafo 1:\n";
	G1.print_list();
	cout << "\nGrafo 2:\n";
	G2.print_list();
	cout << "\nGrafo 3:\n";
	G3.print_list();
	cout << "\nGrafo 4:\n";
	G4.print_list();
	
	// Comprobar que grafo puede ser un arbol
	cout << "Comprobacion de arbol:\n\n";
	G1.isTree(1) ? cout << "El grafo 1 es un arbol\n" : cout << "El grafo 1 no es un arbol\n";
	G2.isTree(5) ? cout << "El grafo 2 es un arbol\n" : cout << "El grafo 2 no es un arbol\n";
	G3.isTree(0) ? cout << "El grafo 3 es un arbol\n" : cout << "El grafo 3 no es un arbol\n";
	G4.isTree(0) ? cout << "El grafo 4 es un arbol\n" : cout << "El grafo 4 no es un arbol\n";
	
	//Comprobar que grafos son bipartitas
	cout << "\n\nComprobacion bipartita:\n";
	G1.bipartiteGraph() ? cout << "\nGrafo 1 es bipartita" : cout << "\nGrafo 1 no es bipartita";
	G2.bipartiteGraph() ? cout << "\nGrafo 2 es bipartita" : cout << "\nGrafo 2 no es bipartita";
	G3.bipartiteGraph() ? cout << "\nGrafo 3 es bipartita" : cout << "\nGrafo 3 no es bipartita";
	G4.bipartiteGraph() ? cout << "\nGrafo 4 es bipartita" : cout << "\nGrafo 4 no es bipartita";

	
	//Ordenamiento topoligico
	cout << "\n\n\nOrdenamiento topoligico:\n";
	cout << "\nGrafo 1:\n";
	G1.topoligicalSort();
	cout << "\nGrafo 2:\n";
	G2.topoligicalSort();
	cout << "\nGrafo 3:\n";
	G3.topoligicalSort();
	cout << "\nGrafo 4:\n";
	G4.topoligicalSort();
}