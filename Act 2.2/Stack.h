#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::cin;

//Clase Node Stack NodeS la cual es un solo un nodo doble
template <class T>
class NodeS {
public:
	NodeS<T>* next;
	NodeS<T>* prev;
	T data;

	NodeS(T _data) {
		data = _data;
		next = NULL;
		prev = NULL;
	}	
};
//Clase Stack o Pila
template <class T>
class Stack {
private:
	NodeS<T>* top;
	int size;
public:
	Stack() {
		size = 0;
		top = NULL;
	}

	~Stack() {
		while (top) {
			NodeS<T>* ptrND = top->next;
			delete (top);
			top = ptrND;
		}
	}
	/*CREATE
	Función la cual añade un dato a la pila al ser esta una estructura FIFI los datos siempre son añadidos al inicio de la pila
	* Entrada: un dato
	* Salida: ninguna
	* Complejidad: O(1)
	*/
	void Push(T _data) {
		NodeS<T>* ptrND = new NodeS<T>(_data);
		if (!top) {
			top = ptrND;
			size++;
			return;
		}

		ptrND->next = top;
		top->prev = ptrND;
		top = ptrND;
		size++;
	}
	/*DELETE
	Funcion para borrar un dato de la pila, por su funcionalidad FIFO solo se puede borrar el primer dato de la pila
	* Entrada: ninguna
	* Salida: ninguna
	* Complejidad: O(1)
	*/
	void Pop() {
		if (!top) {
			cout << "Empty list";
			return;
		}
		NodeS<T>* n = top->next;
		delete(top);
		top = n;
		n->prev = NULL;
		size--;
	}
	//READ
	/*Funcion para ver el dato que se encuentra al inicio de la pila
	* Entrada: ninguna
	* Salida: un dato
	* Complejidad O(1)
	*/
	T Peek() {
		if (!top) 
			cout << "Empty list";
		else
			return top->data;
	}
	/*Funcion para imprimir verticalmente todos los datos de la pila
	* Entrada: ninguna
	* Salida: ninguna
	* Complejidad O(n)
	*/
	void PrintAll() {
		if (!top) {
			cout << "Empty List";
			return;
		}
		NodeS<T>* n = top;
		while (n) {
			cout << "\n" <<"*" << n->data;
			n = n->next;
		}
		cout << "\n\n";
	}
	//Funciones misceláneas para ayudar al funcionamiento
	/*Función para revisar si la pila está vacia
	*Entrada: ninguna
	* Salida: un valor boleano
	* Complejidad: O(1)
	*/
	bool isEmpty() {
		if (top)
			return false;
		else
			return true;
	}
	/*Función para encontrar el tamaño de la pila
	* Entrada: ninguna
	* Salida: un valor int
	* Complejidad: O(1)
	*/
	int getSize() {
		return size;
	}
};