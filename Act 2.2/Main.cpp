#include "Stack.h"
#include "PriorityQueue.h"
/*Act 2.2
* Programa para demostrar el funcionamiento de la cola de prioridad y la pila
* 04/10/2022
* Autor: Francisco Nicolás Jervis Hidalgo A00835131
*/


/*Funciónes para llenar las estructoras con una cantidad de datos especifica
* Entrada: una estructura de datos y una cantidad de valores
* Salida: ninguna
* Complejidad: O(n)
*/
void FillQueueInt(PriorityQueue<int>* list, int size) {
	srand((unsigned)time(NULL));
	int r,r2;
	for (int i = 0; i < size; i++) {
		r = rand() % 100;
		r2 = rand() % 5;
		list->add(r,r2);
	}
}
void FillStackInt(Stack<int>* list, int size) {
	srand((unsigned)time(NULL));
	int r;
	for (int i = 0; i < size; i++) {
		r = rand() % 100;
		list->Push(r);
	}
}
int main() {
	//Declaracion de estructuras
	Stack<int>* stack = new Stack<int>;
	PriorityQueue<int>* pQueue = new PriorityQueue<int>;

	//llenado de estructuras con valores aleatorios
	FillStackInt(stack, 10);
	FillQueueInt(pQueue, 10);


	cout << "Listas originales:\n";
	pQueue->PrintAll();
	stack->PrintAll();

	//Uso de funciones para añadir datos
	cout << "Create: \n";
	pQueue->add(7, 0);
	pQueue->add(91, 4);
	pQueue->add(53, 2);

	stack->Push(62);
	stack->Push(19);
	stack->Push(31);

	pQueue->PrintAll();
	stack->PrintAll();

	//Uso de funciones para leer datos
	cout << "Read:\n";

	cout << "Tail:" << pQueue->Peek()<<"\n\n";

	cout << "Top:" << stack->Peek() << "\n\n";

	cout << "Delete:\n";

	//Uso de funciones para eliminar datos
	pQueue->remove();
	stack->Pop();

	pQueue->PrintAll();
	stack->PrintAll();

	//liberar memoria
	delete pQueue;
	delete stack;









}