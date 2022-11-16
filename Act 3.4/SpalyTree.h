#pragma once
#include <stack>
#include <iostream>
#include "Bitacora.h"
using namespace std;

//CLase Nodo con pointers hacia papa e hijos
template <class T>
class Node {
public:
	T data;
	int  access;
	Node<T>* parent;
	Node<T>* left;
	Node<T>* right;
	Node(T _data) {
		data = _data;
		access = 0;
		parent = NULL;
		left = NULL;
		right = NULL;
	}
	Node() {}
};


template <class T>
class SplayTree {
private:
	Node<T>* root;
	int size = 0;

	/*Función search la cual regresa un puntero hacia el nodo el cual tiene el valor que se deseaba buscar
	* entrada: un nodo raiz y un dato a buscar
	* salida: puntero hacia el nodo encontrado o el lugar donde el nodo debira posicionarse de estar en el arbol
	* complejidad: O(log n)
	*/
	Node<T>* search(Node<T>* node, T data) {
		if (!node || data.ipvalue == node->data.ipvalue)
			return node;
		if (data.ipvalue < node->data.ipvalue)
			return search(node->left, data);
		else
			return search(node->right, data);
	}

	/*Funciones las cuales serán utilizadas por la función splay para reordenar el arbol, ambas tienen funcionalidad similar pero hacia lados diferentes
	* Entradas: un nodo raiz de un sub arbol a mover
	* salidas: ninguna
	* complejidades: ambas tienen complejidad de O(1)
	*/
	void rot_left(Node<T>* node) {
		Node<T>* y = node->right;
		node->right = y->left;
		if (y->left)
			y->left->parent = node;
		y->parent = node->parent;
		if (!node->parent)
			this->root = y;
		else if (node == node->parent->left)
			node->parent->left = y;
		else
			node->parent->right = y;
		y->left = node;
		node->parent = y;
	}
	void rot_right(Node<T>* node) {
		Node<T>* y = node->left;
		node->left = y->right;
		if (y->right)
			y->right->parent = node;
		y->parent = node->parent;
		if (!node->parent)
			this->root = y;
		else if (node == node->parent->right)
			node->parent->right = y;
		else
			node->parent->left = y;
		y->right = node;
		node->parent = y;
	}

	/*Función caracteristica de esta estructura de datos, mueve un nodo a la raiz del arbol y lo reordena
	* entrada: un puntero de un nodo para mover hacia la raiz
	* salida: ninguna
	* complejidad: O(log n)
	*/
	void splay(Node<T>* node) {
		while (node->parent) {
			if (!node->parent->parent) {
				if (node == node->parent->left)
					rot_right(node->parent);
				else
					rot_left(node->parent);
			}
			else if (node == node->parent->left && node->parent == node->parent->parent->left) {
				rot_right(node->parent->parent);
				rot_right(node->parent);
			}
			else if (node == node->parent->right && node->parent == node->parent->parent->right) {
				rot_left(node->parent->parent);
				rot_left(node->parent);
			}
			else if (node == node->parent->right && node->parent == node->parent->parent->left) {
				rot_left(node->parent);
				rot_right(node->parent);
			}
			else {
				rot_right(node->parent);
				rot_left(node->parent);
			}
		}
	}

	/*Función la cual utiliza dos subarboles y los une en un solo arbol ordenado biselando el nodo con mayor valor a la raiz
	* entrada: dos punteros a dos nodos los cuales son dos raices de diferentes alrboles
	* salida: ninguna
	*/
	Node<T>* join(Node<T>* s, Node<T>* t) {
		if (!s)
			return t;
		if (!t)
			return s;
		Node<T>* x = Max(s);
		splay(x);
		x->right = t;
		t->parent = x;
		return x;
	}

	/*Función la cual se utilizara para borrar un nodo del arbol la cual divide el arbol en dos sub arboles con los hijos de los nodos a borrar
	* entrada: tres punteros de nodos los cuales son el nodo a borrar y las dos raices de los sub arboles
	* salida: ninguna
	* complejidad: O(1)
	*/
	void divide(Node<T>*& x, Node<T>*& s, Node<T>*& t) {
		splay(x);
		if (x->right) {
			t = x->right;
			t->parent = NULL;
		}
		else {
			t = NULL;
		}
		s = x;
		s->right = NULL;
		x = NULL;
	}

	/*Función la cual borra un dato del arbol
	* entrada: un nodo raiz del arbol y un dato a borrar
	* salida: ninguna
	* complejidad: O(log n)
	*/
	void del(Node<T>* node, T data) {
		Node<T>* deleted = NULL;
		Node<T>* t, * s;
		while (node) {
			if (node->data.ipvalue == data.ipvalue)
				deleted = node;
			if (node->data.ipvalue < data.ipvalue)
				node = node->right;
			else
				node = node->left;
		}
		if (!deleted) {
			cout << "No data to delete\n";
			return;
		}
		divide(deleted, s, t);
		if (s->left)
			s->left->parent = NULL;
		root = join(s->left, t);
		delete(s);
		s = NULL;
	}

	/*Función para imprimir todo el arbol en forma asendiente utilizando el recorido inorden
	* entrada: un nodo raiz de un arbol
	* salida: ninguna
	* complejidad: O(n)
	*/
	void print(Node<T>* r) {
		if (r) {
			print(r->left);
			r->data.print();
			print(r->right);
		}
	}

public:
	//Constuctor
	SplayTree() {
		root = NULL;
	}

	/*Función find la cual regresa un valor booleano dependiendo si se encontro el valor en el arbol
	* entrada: un dato a buscar
	* salida: un boolaneo representando la existencia del dato en la estructura
	* complejidad: O(log n)
	*/
	bool find(T data) {
		Node<T>* n = root;
		while (n) {
			if (data.ipvalue == n->data.ipvalue)
				return true;
			if (data.ipvalue < n->data.ipvalue)
				n = n->left;
			else
				n = n->right;
		}
		return false;
	}

	/*Función redefinida de busqueda la cual define la raiz del arbol como paramentro y tambien bisela el nodo de busqueda hacia la raiz
	* entrada: un dato
	* salida: un puntero a el nodo el cual se buscaba
	* complejidad: O(log n)
	*/
	void search(T data) {
		Node<T>* x = search(this->root, data);
		if (x) {
			x->access++;
			splay(x);
		}
	}

	/*Funcion para añadir valores al arbol y biselarlos hasta la raiz 
	* entrada: un dato
	* salida: ninguna
	* complejidad: O(log n)
	*/
	void insert(T data) {
		if (find(data))
			return;
		Node<T>* node = new Node<T>(data);
		Node<T>* y = NULL;
		Node<T>* x = this->root;
		while (x) {
			y = x;
			if (node->data.ipvalue < x->data.ipvalue)
				x = x->left;
			else
				x = x->right;
		}
		node->parent = y;
		if (!y)
			root = node;
		else if (node->data.ipvalue < y->data.ipvalue)
			y->left = node;
		else
			y->right = node;
		splay(node);
		size++;
	}

	/*Funcion que regrsa un pointer hacia el nodo minimo del arbol o sub arbol
	* entrada: raiz de un arbol
	* salida: puntero a un nodo con el valor minimo del arbol
	* complejidad: O(log n)
	*/
	Node<T>* Min(Node<T>* node) {
		while (node->right)
			node = node->right;
		return node;
	}

	/*Funcion que regrsa un pointer hacia el nodo máximo del arbol o sub arbol
	* entrada: raiz de un arbol
	* salida: puntero a un nodo con el valor máximo del arbol
	* complejidad: O(log n)
	*/
	Node<T>* Max(Node<T>* node) {
		while (node->right)
			node = node->right;
		return node;
	}

	/*Función que retorna el tamaño del arbol
	* entrada: ninguna
	* salida: entero igual al tamaño del arbol
	* complejidad: O(1)
	*/
	int Size() {
		return size;
	}

	//Sobrecarga de funciones declaradas previamente para que utilicen la raiz de el arbol como parametro, ambas tienen la misma complejidad que su declaración original
	
	void del(T data) {
		del(this->root, data);
		size--;
	}
	void print() {
		print(this->root);
		cout << "\n";
	}

	//Función para comprobar el funcionamiento de splay en el arbol
	T top() {
		return 	this->root->data;
	}
};


