#include "graph.h"
/*Activid 4.1
* Autor: Francisco Jervis A00835131
* El proposito de esta actividad es representar un grafo y sus recorridos BFS y DFS
* Fecha:11/9/2022
*/


int main() {
    graph G1, G2;
    vector<pairs> pair1{ {6,7 }, {6, 5 } ,{6,2},{7,5},{7,3},{7,1},{3,5}, {5,1},{5,3},{2,3 } },
        pair2{ {3,6},{6,5},{6,1},{1,5}, {1,4},{1,2},{4,6} };

    //cargar listas y matrices a grafos
    G1.LoadGraph(8, 10, pair1);
    G2.LoadGraph(7, 7, pair2);

    //Imprimrir matrices y listas de ambos grafos
    cout << "Grafo 1:\n\nLista:\n";
    G1.print_list();
    cout << "Matriz:\n";
    G1.print_mat();
    cout << "\n\nGrafo 2:\n\nLista:\n";
    G2.print_list();
    cout << "Matriz:\n";
    G2.print_mat();

    //Imprimir recoridos
    //BFS
    cout << "Recoridos BFS:\n\nGrafo 1:\n";
    G1.BFS(6);
    cout << "Grafo 2:\n";
    G2.BFS(3);

    //DFS
    cout << "Recoridos DFS:\n\nGrafo 1:\n";
    G1.DFS(6);
    cout << "\n\nGrafo 2:\n";
    G2.DFS(3);
}