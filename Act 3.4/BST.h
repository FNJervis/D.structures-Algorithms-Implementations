#include <iostream>
#include <string>
#include <queue>

using std::cout;
using std::string;
using std::cin;
//Clase nodo doble con hijo derecho e izquierdo
template <class T>
class BST_Node {
public:
	T data;
	BST_Node<T>* left, * right;

	BST_Node() {
		left = right = NULL;
	}
	BST_Node(T d) {
		data = d;
		left = right = NULL;
	}
};
//Clase Binary Search Tree
template <class T>
class BST
{
public:
	BST_Node<T>* root;
	BST() {
		root = NULL;
	}
	/*Funcion para verificar si existe un nodo en el arbol
	* entrada: un dato a buscar
	* salida: verdadero si se encontro el dato en el arbol o falso de lo contrario
	* Complejidad de O(logn) cuando el arbol esta balanceado
	*/
	bool search(T d) {
		BST_Node <T>* current = root;
		while (current) {
			if (current->data.ipvalue == d.ipvalue)
				return true;
			else
				current = (current->data.ipvalue > d.ipvalue ? current->left : current->right);
		}
		return false;
	}
	/*Funcion para añadir un nodo al BST
	* entrada: un dato
	* salida: ninguna
	* complejidad de O(logn) cuando el arbol esta balanceado
	*/
	void add(T d) {
		BST_Node <T>* newn = new BST_Node<T>(d);
		if (!root)
			root = newn;
		else {
			BST_Node <T>* current = root;
			BST_Node <T>* parent = NULL;
			while (current) {
				if (current->data.ipvalue == d.ipvalue) {
					cout << "\nData already in tree\n";
					return;
				}
				parent = current;
				current = (current->data.ipvalue > d.ipvalue ? current->left : current->right);
			}
			parent->data.ipvalue > d.ipvalue ? parent->left = newn : parent->right = newn;
		}
	}
	/*Funcion para encontar la altura del arbol
	* entrada: puntero al nodo raiz
	* salida: numero igual a la altura del arbol
	* complejidad de O(n) ya que busca a traves de todos los sub arboles pero
	*/

	int height(BST_Node <T>* r) {
		if (!r)
			return 0;
		else {
			int leftl = height(r->left);
			int rightl = height(r->right);

			if (leftl > rightl)
				return (leftl + 1);
			else
				return (rightl + 1);
		}
	}
	/*Funcion para imprimir los ancestros de un nodo
	* entrada: un dato para buscar en el arbol
	* salida: ninguna
	* complejidad de O(log n)
	*/
	void ancestors(T d) {
		BST_Node <T>* current = root;
		if (search(d)) {
			while (current) {
				if (current->data.ipvalue == d.ipvalue)
					return;
				else
					cout << current->data.ipvalue << " ";
				current = (current->data.ipvalue > d.ipvalue ? current->left : current->right);
			}
		}
		else
			cout << "\nNode not in tree\n";
	}
	/*Funcion para encontrar en que nivel del arbol se envuentra un nodo
	* entrada: un dato para buscar
	* salida: el nivel en el que el dato se encuentra o -1 en el caso de que este no exista
	* Complejidad O(logn)
	*/
	int whatlevelamI(T d) {
		if (!search(d))
			return -1;
		BST_Node <T>* current = root;
		int count = 0;
		while (current) {
			count++;
			if (current->data.ipvalue == d.ipvalue)
				return count;
			else
				current = (current->data.ipvalue > d.ipvalue ? current->left : current->right);
		}
	}
};