#include "Heap.h"


int main() {
	Heap* heap = new Heap;

    //A�adir valores al arbol
    heap->push(35);
    heap->push(20);
    heap->push(14);
    heap->push(29);
    heap->push(8);
    heap->push(49);
    heap->push(5);
    heap->push(45);
    heap->push(37);
    heap->push(21);

    //Imprimir el heap original
    heap->print();

    //Probar el funcionamiento de top y size
    cout << "El primer valor es: " << heap->top() << " y el tama�o de la estructura es: " << heap->Size() << "\n\n";

    //Eliminar los primeros 3 elementos
    heap->pop();
    heap->pop();
    heap->pop();

    //Imprimir nueva heap con los valores eliminados
    heap->print();
    cout << "El primer valor es: " << heap->top() << " y el tama�o de la estructura es: "<<heap->Size() << endl;

}