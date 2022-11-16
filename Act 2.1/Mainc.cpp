#include "LinkedList.h"
#include "DoublyLinkedList.h"
#include "CircularList.h"
#include "bitacora.h"
/*Act 2.1
* Programa para demostrar el funcionamiento de las listas ligadas simples dobles y circulares
* 09/28/2022
* Autor: Francisco Nicolás Jervis Hidalgo A00835131
*/


/*Función para llenar una lista circular de valores tipo int aletorios
* Entrada: una lista tipo circular cantidad de valores
* Salida: ninguna
* Complejidad: O(n)
*/
void FillCListInt(CircularList<int>& list, int size) {
	srand((unsigned)time(NULL));
	int r;
	for (int i=0; i < size; i++) {
		r = rand() % 100;
		list.NewNode(r);
	}	
}
//Misma logica y complejidad de la primera función pero aplicada a una lista simple
void FillLListInt(LinkedList<int>& list, int size) {
	srand((unsigned)time(NULL));
	int r;
	for (int i = 0; i < size; i++) {
		r = rand() % 100;
		list.NewNode(r);
	}
}//Misma logica y complejidad de la primera función pero aplicada a una lista doble
void FillDListInt(DoublyLinkedList<int>& list, int size) {
	srand((unsigned)time(NULL));
	int r;
	for (int i = 0; i < size; i++) {
		r = rand() % 100;
		list.NewNode(r);
	}
}
int main() {
	//Declaración de nodes para las listas
	SingleNode<int> node1(1), node2(28);
	DoubleNode<int> node3(38), node4(12);
	SingleCNode<int> node5(57), node6(9);

	//Declaración de listas
	LinkedList<int> list1;
	DoublyLinkedList<int> list2;
	CircularList<int> list3;
	
	//Llenado de listas con 10 valores cada una
	FillLListInt(list1, 10);
	FillDListInt(list2, 10);
	FillCListInt(list3, 10);

	//Casos de prueba
	cout << "Listas originales\n";
	cout << "Lista 1:\n";
	list1.PrintAll();
	cout << "\nLista 2:\n";
	list2.PrintAll();
	cout << "\nLista 3:\n";
	list3.PrintAll();
	

	//añadir nodos creados previamente
	list1.PushNode(node1);
	list1.SetNodeAt(node2, 7);
	list1.NewNodeAt(65, 5);


	list2.PushNode(node3);
	list2.SetNodeAt(node4, 5);
	list2.NewNodeAt(10, 0);

	list3.PushNode(node5);
	list3.SetNodeAt(node6, 4);
	list3.NewNodeAt(91, 3);
	cout << "\n listas Nuevas\n";

	list1.PrintAll();
	list2.PrintAll();
	list3.PrintAll();

	//cambio de valores y borrado de nodos
	list1.UpadateNode(111, 2);
	list1.DeleteHead();

	list1.DeleteNodeAt(3);

	list2.UpadateNode(111, 5);
	list2.DeleteHead();
	list2.DeleteNodeAt(1);

	list3.UpadateNode(111, 4);
	list3.DeleteHead();
	list3.DeleteNodeAt(3);

	cout << "\n listas Nuevas\n";

	list1.PrintAll();
	list2.PrintAll();
	list3.PrintAll();

	cout << std::endl;

	
	
	

	




}