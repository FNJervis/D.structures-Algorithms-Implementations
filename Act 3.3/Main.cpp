#include "SplayTree.h"

/*Act 3.3
* Programa para demostrar la implementación y funcionalidad de un arbol biselado
* Autor: Francisco Jervis A00835131
* 11/2/22
*/

int main() {
	SplayTree<int> tree;

	//Insertar datos al arbol
	tree.insert(17);
	tree.insert(69);
	tree.insert(37);
	tree.insert(43);
	tree.insert(2);
	tree.insert(99);
	tree.insert(86);
	tree.insert(12);
	tree.insert(55);
	tree.insert(42);

	//utilizamos top para comprobar que el ultimo valor añadido esta en la raiz
	cout << "El valor en la raiz del arbol es: " << tree.top() << "\n";
	
	cout << "\n\n";
	tree.print();
	cout << "El tamaño del arbol es de: " << tree.Size()<<"\n";

	cout << "\n\n";
	//Borrar datos
	tree.del(42);//borramos la raiz por lo que top cambia
	tree.del(2);
	tree.del(99);
	tree.del(55);
	tree.del(12);

	cout << "Despues de eliminar 5 datos el valor en la raiz del arbol es: " << tree.top() << "\n";	
	cout << "El tamaño del arbol es de: " << tree.Size() << "\n";
	tree.print();

	cout << "\n\n";
	//Buscar datos
	//Buscar datos con la fucnion find 
	if (tree.find(37))//si se enuentra
		cout << 37 << " Se encuetra en el arbol\n";
	else
		cout << 37 << " No se encuetra en el arbol\n";
	if (tree.find(12))//no se encuentra ya que fue eliminado
		cout << 12 << " Se encuetra en el arbol\n";
	else
		cout << 12 << " No se encuetra en el arbol\n";

	cout << "\n\n";
	//Busqueda con función search la cual biseala el nodo a la raiz por lo que al usar la función top se deberia ver el valor de la busqueda
	tree.search(69);
	cout << "Despues de la busqueda el valor en la raiz del arbol es: " << tree.top() << "\n";

	
}