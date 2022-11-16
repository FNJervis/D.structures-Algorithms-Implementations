#pragma once
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//estructura simple para guardar los pares a conectar en el grafo
struct pairs {
    int a;
    int b;
};
//Clase graph

class graph {
private:
    bool** Matrix;
    vector<vector<int>> List;
    int vertex;
    int edges;

    /*Función para añadir un arco desde el vertice a hasta el vertice b
    * entrada: dos enteros, a es el vertice de inicio y b el vertice final
    * salida: ninguna
    * complejidad: O(1)
    */
    void add_edges(vector<pairs> p) {
        for (int i = 0; i < p.size(); i++) {
            Matrix[p[i].a][p[i].b] = true;
            List[p[i].a].push_back(p[i].b);
        }
    }

    /*Función para inicializar la matriz y la lista
    * Entrada: ninguna
    * Salida: ninguna
    * Complejidad O(n^2)
    */
    void in_mat_list() {
        List.resize(vertex);
        Matrix = new bool* [vertex];
        for (int i = 0; i < vertex; i++) {
            Matrix[i] = new bool[vertex];
            for (int j = 0; j < vertex; j++)
                Matrix[i][j] = false;
        }
    }


public:
    //Constructor
    graph() {
        vertex = 0;
        edges = 0;
    }

    /*Funcion para cargar los datos en el grafo e inicializarlo
    * Entrada: numero max de vertices, cantidad de arcos, vector con pares para arcos
    * Salida: ninguna
    * Complejidad: O(n^2)
    */
    void LoadGraph(int vert, int edg, vector<pairs> edge ) {
        vertex = vert;
        edges = edg;
        in_mat_list();
        add_edges(edge);
    }

    /*Funcion para imprimir la matriz de adyacencia
    * Entrada: ninguna
    * salida: ninguna
    * Complejidad: O(n^2)
    */
    void print_mat() {
        cout << "   ";
        for (int i = 0; i < vertex; cout << i << " ", i++ );
        for (int i = 0; i < vertex; i++) {
            cout << "\n" << i << "  ";
            for (int j = 0; j < vertex; Matrix[i][j] == true ? cout << "T" : cout << "F", cout << " ", j++);
        }
        cout << "\n\n";
    }

    /*Función para imprimir la lista de adyacencia
    * Entrada: ninguna
    * Salida: ninguna
    * Complejidad: O(n)
    */
    void print_list() {
        for (int i = 0 ; i < List.size(); i++, cout << "\n"<<i<< "->") {
            for (int j = 0; j < List[i].size(); cout << List[i][j]<<" ", j++);
        }
        cout << "\n\n";
    }

    /*Función para recorrer el grafo Breath first Search utilizando la lista de adyacencias
    * Entrada: entero igual al nodo inicial
    * Salida: ninguna
    * Complejidad O(n)
    */
    void BFS(int head) {
        queue<int> tempq;
        vector<bool> status(vertex, false);

        tempq.push(head);
        status[head] = true;

        while (!tempq.empty()) {
            int n_top = tempq.front();
            tempq.pop();
            cout << n_top << " ";
            
            for (int i = 0; i < List[n_top].size(); i++) {
                int nodos_v = List[n_top][i];
                if (!status[nodos_v]) {
                    tempq.push(nodos_v);
                    status[nodos_v] = true;
                }

            }
        }
        cout << "\n\n";
    }

    /*Función recursiva para recorrer el grafo Depthfirst search utilizando la matriz de adyacencia
    * Entrada: un vector con valores booleanos para saber si ya se prosesó los nodos y un valor del nodo inicial
    * Salida: ninguna
    * Complejidad O(n)
    */
    void DFSr(int head, vector<bool>& status) {
        status[head] = true;
        cout << head << " ";
        for (int i = 0; i < sizeof(Matrix[head]); i++) {
            if (Matrix[head][i] == true && (!status[i]))
                DFSr(i, status);
        }
    }
    void DFS(int head) {
        vector<bool> status(vertex, false);
        DFSr(head, status);
    }
};

