#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <malloc.h>
#include <string>

using std::cout;
using std::string;
using std::cin;


/*Clase SingleNode
* atrubutos: pointer al siguiente nodo, datos en el nodo
*/
template<class T>
class SingleNode
{
public:
	T data;
	SingleNode<T>* next;

	SingleNode(T _data) {
		data = _data;
		next = NULL;
	}

};
template<class T>
/*Clase LinkedList es una clase para una lista ligada simple la cual implenta varios metodos CRUD
* atributos:pointer hacia el primer nodo de la lista, tamaño de la lista
*/
class LinkedList
{
public:
	SingleNode<T>* head;
	SingleNode<T>* tail;
	int size;
	LinkedList() {
		tail = NULL;
		head = NULL;
		size = 0;
	}
	LinkedList(SingleNode<T> _head) {
		PushNode(_head);
	}
	/*Función que recurre por toda la lista imprimiedo los datos
	* entrada: ninguna, salida: ninguna
	* Complejidad de O(n)
	*/
	void PrintAll() {
		if (!head) {
			cout << "Empty List";
			return;
		}
		SingleNode<T>* n = head;
		while (n) {
			cout << " " << n->data;
			n = n->next;
		}
		cout << std::endl;
	}
	/*Función que imprime los datos de un nodo en indice especifico
	* entrada: indice, salida: ninguna
	* Complejidad de O(n)
	*/
	void PrintNode(int index) {
		if (!head) {
			cout << "Empty List";
			return;
		}
		if (index >= size) {
			cout << "No node at that index";
			return;
		}
		int count = 0;
		SingleNode<T>* n = head;
		while (count != index) {
			count++;
			n = n->next;
		}
		cout << "Data at index" << index << ": " << n->data << std::endl;
	}
	/*Función la cual añade un node ya creado al final de la lista
	* entrada: un node, salida: ninguna
	* Complejidad de O(n)
	*/
	void PushNode(SingleNode<T> NewNode) {
		SingleNode<T>* ptrND = &NewNode;
		if (!head) {
			head = ptrND;
			tail = head;
			size++;
		}
		else {
			tail->next = ptrND;
			tail = ptrND;
			size++;
		}
	}
	/*Función que añade un nuevo nodo al final de la lista con un dato proporcionado
	* entrada: un dato, salida: ninguna
	* Complejidad de O(n)
	*/
	void NewNode(T data) {
		SingleNode<T>* ptrND = new SingleNode<T>(data);
		if (!head) {
			head = ptrND;
			tail = head;
			size++;
		}
		else {
			tail->next = ptrND;
			tail = ptrND;
			size++;
		}
	}/*Función que añade un node nuevo con un dato en un indice de la lista proporcionado
	* entrada: un dato, un indice, salida: ninguna
	* Complejidad de O(n)
	 */
	void NewNodeAt(T data, int index) {
		SingleNode<T>* ptrND = new SingleNode<T>(data);
		if (index >= size && index != 0) {
			cout << "Index out of range";
			return;
		}
		if (!head) {
			head = ptrND;
			size++;
			return;
		}
		if (index == 0) {
			ptrND->next = head;
			head = ptrND;
			size++;
			return;
		}
		if (index==size-1){
			tail->next = ptrND;
			tail = ptrND;
			size++;
			return;
		}
		int count = 1;
		SingleNode<T>* prev = head->next;
		for (count; count < index - 1; count++) {
			prev = prev->next;
		}
		SingleNode<T>* nxt = prev->next;
		prev->next = ptrND;
		ptrND->next = nxt;
		size++;
	}
	/*Funcion que añade un node ya creado a un indice especifico de la lista sin eliminar nodes
	* 	* entrada: un node y un indice, salida: ninguna
	* Complejidad de O(n)
	*/
	void SetNodeAt(SingleNode<T> NewNode, int index) {
		SingleNode<T>* ptrND = &NewNode;
		if (index >= size && index != 0) {
			cout << "Index out of range";
			return;
		}
		if (!head) {
			head = ptrND;
			size++;
			return;
		}
		if (index == 0) {
			ptrND->next = head;
			head = ptrND;
			size++;
			return;
		}
		if (index == size - 1) {
			tail->next = ptrND;
			tail = ptrND;
			size++;
			return;
		}
		int count = 1;
		SingleNode<T>* prev = head->next;
		for (count; count < index - 1; count++) {
			prev = prev->next;
		}
		SingleNode<T>* nxt = prev->next;
		prev->next = ptrND;
		ptrND->next = nxt;
		size++;
	}
	/*Función que cambia el valor de un node en un indice especifico
	* 	* entrada: un dato y un indice, salida: ninguna
	* Complejidad de O(n)
	*/
	void UpadateNode(T data, int index) {
		if (!head) {
			cout << "Empty list";
			return;
		}
		if (index >= size && index != 0)
			cout << "Index out of range";
		else {
			int count = 0;
			SingleNode<T>* n = head;
			for (count; count < index; count++) {
				n = n->next;
			}
			n->data = data;
		}
	}
	/*Función que busca un dato especifico y al encontrarlo imprime el indice o indices en el cual fue encontrado
	* 	* entrada: un dato, salida: ninguna
	* Complejidad de O(n)
	*/
	void SearchData(T data) {
		if (!head) {
			cout << "Empty list";
			return;
		}
		SingleNode<T>* n = head;
		int count = 0, check = 0;
		while (n) {
			if (n->data == data) {
				cout << "Data: " << data << "\n Was found at index: " << count << std::endl;
				check++;
			}
			count++;
			n = n->next;
		}
		if (check != 0)
			cout << "Data not found in list" << std::endl;
	}/*Funcion que borra el ultimo node de la lista
		* entrada: ninguna, salida: ninguna
	* Complejidad de O(n)
	 */
	void DeleteLast() {
		if (!head) {
			cout << "Empty list";
			return;
		}			
		SingleNode<T>* prev = head;
		for (int i = 0; i < size - 2; i++) {
			prev = prev->next;	
		}
		delete(tail);
		prev->next = NULL;
		tail = prev;
		size--;

	}/*Función que borra el primer node de la lista
	 * entrada: ninguna, salida: ninguna
	* Complejidad de O(1)
	 */
	void DeleteHead() {
		if (!head) {
			cout << "Empty list";
			return;
		}
		SingleNode<T>* n = head->next;
		delete(head);
		head = n;
		size--;
	}
	/*Funcion que borra un nodo especifico
	* * entrada: un indice, salida: ninguna
	* Complejidad de O(n)
	*/
	void DeleteNodeAt(int index) {
		if (!head) {
			cout << "Empty list";
			return;
		}
		if (index >= size && index != 0) {
			cout << "Index out of range";
			return;
		}
		if (index == 0) {
			SingleNode<T>* n = head->next;
			delete(head);
			head = n;
			size--;
			return;
		}
		else {
			SingleNode<T>* prev = head;
			SingleNode<T>* nxt = head->next;
			for (int i = 0; i < index - 1; i++) {
				prev = nxt;
				nxt = nxt->next;
			}
			if (index == size - 1) {
				delete(prev->next);
				prev->next = NULL;
				tail = prev;
				size--;	
			}
			else {
				prev->next = nxt->next;
				delete(nxt);
				size--;
			}
		}
	}
};