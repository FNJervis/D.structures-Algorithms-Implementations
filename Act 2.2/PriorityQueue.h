#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using std::cout;
using std::string;
using std::cin;

/*
Clase Priority node(PNode)
Clase de nodo doble para utilizar en la cola de prioridad la cual tiene un atributo espesifico de prioridad
*/
template <class T>
class PNode
{
public:
    T data;
    int priority;
    PNode<T>* next;
    PNode<T>* prev;

    PNode(T _data, int p) {
        data = _data;
        priority = p;
        next = NULL;
        prev = NULL;
    }
};
//Clase PriorityQueue, cola de prioridad
template <class T>
class PriorityQueue {
private:

    PNode<T>* head;
    PNode<T>* tail;
    int size;

public:
    PriorityQueue() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    //Destructor con complejidad O(n) ya que debe iterar por toda la cola
    ~PriorityQueue() {
        while (head) {
            PNode<T>* PtrND = head->next;
            delete (head);
            head = PtrND;
        }
        tail = NULL;
    }
    /*CREATE
    Funcion para añadir un nodo a la lista
    * Entrada: un dato y su prioridad
    * Salida: ninguna
    * Funcionalidad: Crear un nodo con los datos y prioridad proporcionadas,
    * Si la lista esta vacia añade el nodo como head y tail
    * de lo contrario, compara la prioridad que existe en la lista y lo añade acordemente:
    * si la prioridad es menor o igual  que un nodo lo pone antes y si la prioridad es mayor que un nodo lo pone despues.
    * Complejidad de O(n) en el peor de los casos;
    */
    void add(T data, int p) {
        PNode<T>* PtrND = new PNode<T>(data, p);
        if (!head) {
            head = PtrND;
            tail = PtrND;
        }
        else {
            PNode<T>* n = head;
            for (; (n->priority < PtrND->priority) && (n->next); n = n->next){}

            if ((!n->prev)&&(n->priority >= PtrND->priority)) {
                n->prev = PtrND;
                PtrND->next = n;
                head = PtrND;
            }
            else if ((!n->next) && (n->priority < PtrND->priority)) {
                n->next = PtrND;
                PtrND->prev = n;
                tail = PtrND;
            }
            else {
                PNode<T>* prev = n->prev;
                prev->next = PtrND;
                PtrND->next = n;
                PtrND->prev = prev;
                n->prev = PtrND;
            }
        }
        size++;
    }
    /*DELETE
    Funcion para quitar un elemento de la cola
    * entrada: ninguna
    * salida: ninguna
    * Funcionamiento: La cola de prioridad al ser una estructura FILO, los elemntos se añaden desde el inicio y salen por el final
    * por lo que la funcion remove quita el ultimo elemnto de la cola
    * Complejidad O(1)
    */
    void remove(){
        if (!head) {
            cout << "Empty list";
            return;
        }
        PNode<T>* prev = tail->prev;
        delete(tail);
        prev->next = NULL;
        tail = prev;
        size--;
    }
    //READ
    /*Funciones peak
    * Entaradas: ninguna
    * salidas: un dato de tipo T es decir el tipo de dato que sea declarado con la cola
    * Funcionalidad: regresan el dato en la cabeza o en la cola de la estructura
    * Complejidad O(1)
    */
    T Peek() {
        if (!head)
            cout << "Empty list";
        else
            return tail->data;
    }
    /*Funcion para imprimir todos los elemntos de la cola y su complejidad la cual es impresa al lado del dato en parentesis
    * Entrada: ninguna
    * Salida: ninguna
    * Complejidad O(n)
    */
    void PrintAll() {
        if (!head) {
            cout << "Empty List";
            return;
        }
        PNode<T>* n = head;
        while (n) {
            cout << " " << n->data<<" p("<<n->priority<<")";
            n = n->next;
        }
        cout << std::endl;
    }
};

