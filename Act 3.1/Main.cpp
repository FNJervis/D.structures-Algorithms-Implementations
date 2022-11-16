#include "BST.h"
/*Act 3.1
* Programa para demostrar varias funcionalidades y operaciones de un arbol binario de busqueda o BST
* Autor: Francisco Jervis A00835131
* 10/16/22
*/



/*Funciones para imprimir y recorrer el BST de diferentes maneras
* La entrada de todas las fucniones es un puntero hacia la raiz del arbol
* Ninunga tiene salida
* La comlejidad de todas es O(n) y a que tienen que visitar cada nodo una vez
*/
//Recorido postorden: reccore primero el subarbol izquierdo despues el derecho y finalmente la raiz
void visitPost(Node <int>* r) {
	if (r) {
		visitPost(r->left);
		visitPost(r->right);
		cout << r->data<<" ";
	}
}
//Recorrido inorden: recorre el arbol en orden creciente
void visitIno(Node <int>* r) {
	if (r) {
		visitIno(r->left);
		cout << r->data<<" ";
		visitIno(r->right);
	}
}
//Recorido preorden: recorre la raiz, el subarbol izquierdo y despues el derecho, ambos desde la raiz
void visitPreo(Node <int>* r) {
	if (r) {
		cout << r->data<<" ";
		visitPreo(r->left);
		visitPreo(r->right);
	}
}
//Recorido por nivel: recorre el arbol de forma horizontal
void visitLevel(Node<int>* root) {
	std::queue<Node<int>*> tempq;
	Node<int>* v;
	tempq.push(root);
	while (!tempq.empty()) {
		v = tempq.front();
		tempq.pop();
		cout << v->data << " ";
		if (v->left)
			tempq.push(v->left);
		if (v->right)
			tempq.push(v->right);
	}
}
int main() {
	BST<int> tree;
	//Añadir diferentes nodos al arbol
	tree.add(17);
	tree.add(25);
	tree.add(11);
	tree.add(7);
	tree.add(13);
	tree.add(18);
	tree.add(28);

	/*Representación grafica del arbol
	*l1			17
	*l2		11		25
	*l3	  7   13  18   28
	*/
	
	//Probar diferentes funcionalidades:
	//Altura
	cout << "Altura del arbol\n";
	cout<<tree.height(tree.root)<<"\n";

	//Recoridos
	cout << "Recorrido Preorden:\n";
	visitPreo(tree.root);

	cout << "\nRecorrido Inorden:\n";
	visitIno(tree.root);

	cout << "\nRecorrido Postorden:\n";
	visitPost(tree.root);

	cout << "\nRecorrido por nivel:\n";
	visitLevel(tree.root);

	//Ancestros
	cout << "\nAncestros de 28:\n";
	tree.ancestors(18);
	cout << "\nAncestros de 7:\n";
	tree.ancestors(7);
	cout << "\nAncestros de 11:\n";
	tree.ancestors(11);


	//Buscar nivel
	cout << "\nNivel de 7:\n"<<tree.whatlevelamI(13);
	cout << "\nNivel de 25:\n" << tree.whatlevelamI(25);
	cout << "\nNivel de 17:\n" << tree.whatlevelamI(17);
}