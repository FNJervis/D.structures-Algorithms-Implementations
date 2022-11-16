#pragma once
#include <iostream>
using std::cout;
using std::endl;

class Heap {
public:
    int heapArray[1000];
    int size = 0;


    Heap() {
    }

    /*Función para añadir un valor al heap
    * entrada: un valor tipo int que se añadira
    * salida: ninguna
    * complejidad: O(log n) ya que utiliza swift up que es una funcion con la misma complejidad
    */
    void push(int value) {
        heapArray[size] = value;
        size++;
        if (size > 1) {
            swiftUp((size / 2) - 1);
        }
    }

    /*Función para remover un valor del heap
   * entrada: ningunaa
   * salida: ninguna
   * complejidad: O(log n) ya que utiliza swift down que es una funcion con la misma complejidad
   */
    void pop() {
        int temp = heapArray[size - 1];
        heapArray[size - 1] = heapArray[0];
        heapArray[0] = temp;
        size--;
        if (size > 1) {
            swiftDown(0);
        }
    }

    /*Funcion que regresa el valor del dato con mayor prioridad
    * entrada: ninguna
    * salida: dato con mayor prioridad en el heap
    * complejidad: O(1) ya que el dato con mayor prioridad es el primer dato
    */
    int top() {
        if (size > 0)
            return heapArray[0];
        return NULL;
    }

    /*Funcion para verificar si el heap esta vacio o no
    * entrada: ninguna
    * salida: valor booleano dependiendo de si la estructura esta vacia o no
    * complejidad O(1)
    */
    bool empty() {
        if (size == 0)
            return true;
        return false;
    }

    /*Funcion que devuelve el tamaño del heap
    * entrada: ninguna
    * salida: entero igual al valor de el tamaño
    * complejidad: O(1)
    */
    int Size() {
        return size;
    }

    /*Funcion para intecambiar la posicion de valores dentro de la estructura utilizada en funciones de reorganizamiento
    * entrada: dos indices dentro del heap
    * salida: ninguna
    * complejidad: O(1)
    */
    void swap(int x, int y) {
        int temp = heapArray[x];
        heapArray[x] = heapArray[y];
        heapArray[y] = temp;

    }

    /*Funcion para reorganizar o ordenar el heap despues de añadir un valor nuevo
    * entrada: raiz del arbol o sub arbol
    * salida: ninguna
    * complejidad: O(log n)
    */
    void  swiftUp(int rootIndex) {
        int max = rootIndex;
        int left = (2 * rootIndex) + 1;
        int right = (2 * rootIndex) + 2;
        if (left < size && heapArray[max] < heapArray[left]) {
            max = left;
        }
        if (right < size && heapArray[max] < heapArray[right]) {
            max = right;
        }

        if (max != rootIndex) {

            swap(max, rootIndex);
            swiftUp((rootIndex - 1) / 2);
        }

    }

    /*Funcion para reorganizar o ordenar el heap despues de remover un valor
    * entrada: raiz del arbol o sub arbol
    * salida: ninguna
    * complejidad: O(log n)
    */
    void  swiftDown(int rootIndex) {
        int max = rootIndex;
        int left = (2 * rootIndex) + 1;
        int right = (2 * rootIndex) + 2;
        if (left < size && heapArray[max] < heapArray[left]) {
            max = left;
        }
        if (right < size && heapArray[max] < heapArray[right]) {
            max = right;
        }
        if (max != rootIndex) {

            swap(max, rootIndex);
            swiftDown(max);
        }
    }
    /*Para imprimir el heap completo en orden
    * entrada: ninguna
    * salida: ninuguna
    * complejidad: O(n)
    */
    void print() {
        for (int i = 0; i < size; i++) {
            cout << heapArray[i] << " ";
        }
        cout << endl;
    }
};

