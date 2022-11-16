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
    vector<vector<int>> List;
    int vertex;
    int edges;

    /*Función para añadir un arco desde el vertice a hasta el vertice b
    * entrada: dos enteros, a es el vertice de inicio y b el vertice final
    * salida: ninguna
    * complejidad: O(1)
    */
    void add_edges(vector<pairs> p) {
        for (int i = 0; i < p.size(); i++) 
            List[p[i].a].push_back(p[i].b); 
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
    * Complejidad: O(E)
    */
    void LoadGraph(int vert, int edg, vector<pairs> edge) {
        vertex = vert;
        edges = edg;
        List.resize(vertex);
        add_edges(edge);
    }


    /*Función para saber si el grafo es un arbol, utiliza un BFS modificado para enontrar ciclos o separaciones en el grafo, solo funciona para DAGs
    * Entrada: un nodo cabeza para iniciar el recorrido
    * Salida: un valor booleano indicando si el grafo es un arbol o no
    * Complejidad O(V+E)
    */
    bool isTree(int head) {
        queue<int> tempq;
        vector<bool> status(vertex, false);

        tempq.push(head);
        status[head] = true;

        while (!tempq.empty()) {
            int n_top = tempq.front();
            tempq.pop();

            for (int i = 0; i < List[n_top].size(); i++) {
                int nodos_v = List[n_top][i];
                if (!status[nodos_v]) {
                    tempq.push(nodos_v);
                    status[nodos_v] = true;
                }
                else
                    return false;
            }
        }
        for (int i = 0; i < vertex; i++) {
            if (!status[i])
                return false;
        }
        return true;


    }
    /*Función para imprimir el grafo de manera tologica utlizando el algoritmo de Khan
    * Entada: ninguna
    * Salida: ninguna
    * Complejidad: O(V+E) 
    */
    void topoligicalSort() {
        vector<int> tops(vertex, 0);
        for (int i = 0; i < vertex; i++)
            for (int i2 = 0; i2 < List[i].size(); i2++)
                tops[List[i][i2]]++;

        queue<int> q;
        for (int i = 0; i < vertex; i++)
            if (tops[i] == 0)
                q.push(i);

        int count = 0;
        vector<int> n_ordered;
        while (!q.empty()) {
            int n = q.front();
            q.pop();
            n_ordered.push_back(n);
            for (int i = 0; i < List[n].size(); i++)
                if (--tops[List[n][i]] == 0)
                    q.push(List[n][i]);
            count++;
        }
        if (count != vertex) {
            cout << "Existe un cyclo en el grafo, no es posible hacer un tological sort\n";
            return;
        }

        for (int i = 0; i < n_ordered.size(); cout << n_ordered[i] << " ", i++);
        cout << "\n\n";
    }
    /*Función para saber si un grafo puede ser reprensteado como grafo bipartita la cual utiliza una BFS modificada
    * Entrada: ninguna
    * Salida: un valor booleano representado si es posible representar el grafo bipartitamente
    * Complejidad: O(V+E)
    */
    bool bipartiteGraph() {
        vector<int> col(vertex, -1);
        queue<pairs>  tempq;
        for (int i = 0; i < vertex; i++) {
            if (col[i] == -1) {
                tempq.push({ i,0 });
                col[i] = 0;
                while (!tempq.empty()){
                    pairs p = tempq.front();
                    tempq.pop();
                    int vert = p.a;
                    int color = p.b;
                    for (int i2 : List[vert]) {
                        if (col[i2] == color)
                            return false;
                        if (col[i2] == -1) {
                            col[i2] = color ? 0 : 1;
                            tempq.push({ i2,col[i2] });
                        }
                    }
                }
            }
        }
        return true;
    }
    /*Función para imprimir la lista de adyacencia
    * Entrada: ninguna
    * Salida: ninguna
    * Complejidad: O(V+E)
    */
    void print_list() {
        for (int i = 0; i < List.size(); i++) {
            cout << "\n" << i << "->";
            for (int j = 0; j < List[i].size(); cout << List[i][j] << " ", j++);
        }
        cout << "\n\n";
    }

    /*Función para recorrer el grafo Breath first Search utilizando la lista de adyacencias
    * Entrada: entero igual al nodo inicial
    * Salida: ninguna
    * Complejidad O(V+E)
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
};

