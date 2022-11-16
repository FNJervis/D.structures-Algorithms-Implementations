#include <bits.h>
#include <iostream>
using namespace std;

class Node {
    //clase node que continene los datos del node (data) y el pointer hacia el sigienrte node (next)
public:
    int data;
    Node* next;

    //Constructor default
    Node() {
        data = 0;
        next = NULL;
    }
    //Constructor con dato del node
    Node(int _data) {
        data = _data;
        next = NULL;
    }
    //Función para imprimir la lista desde head
    void printlist() {
        cout << data;
        Node* n = next;
        while (n) {
            cout << " " << n->data;
            n = n->next;
        }
    }
    //Funcion que devuelve el tamaño de la lista
    int size() {
        int count = 1;
        Node* n = next;
        while (n){
            count++;
            n = n->next;
        }
        return count;
    }
    //Funcion que añade un node al principio de la lista
    void push(Node* n) {

    }
};




int main() {
    //crear tres pointers tipo node con su dato
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);

    //linkear un node a otro
    head->next = second;

    second->next = third;

    //Imprimir lista    
    head->printlist();

    cout << endl<< head->size();

    


};
/*
//asignar cada pointer a un node

 head = new Node();
 third = new Node();
 second = new Node();

 //asignar datos y pointer al siguientre node
 head->data = 1;
 head->next = second;

 second->data = 2;
 second->next = third;

 third->data = 3;
 third->next = NULL;
 */