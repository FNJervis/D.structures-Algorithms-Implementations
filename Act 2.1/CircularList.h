#pragma once
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <malloc.h>
#include <string>
#include <vector>
using std::cout;
using std::string;
using std::cin;
using std::vector;
//Igual funcionamiento a la lista simple pero el ultimo pointer apunta al inicio de la lista otra vez

template<class T>
class SingleCNode
{
public:
	T data;
	SingleCNode<T>* next;

	SingleCNode(T _data) {
		data = _data;
		next = NULL;
	}

};
template<class T>
class CircularList
{
public:
	SingleCNode<T>* head;
	SingleCNode<T>* tail;
	int size;
	CircularList() {
		head = NULL;
		size = 0;
	}
	CircularList(SingleCNode<T> _head) {
		PushNode(_head);
	}
	void PrintAll() {
		if (!head) {
			cout << "Empty List";
			return;
		}
		SingleCNode<T>* n = head;
		for (int i = 0; i < size;i++) {
			cout << " " << n->data;
			n = n->next;
		}
		cout << std::endl;
	}
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
		SingleCNode<T>* n = head;
		while (count != index) {
			count++;
			n = n->next;
		}
		cout << "Data at index" << index << ": " << n->data << std::endl;
	}
	void PushNode(SingleCNode<T> NewNode) {
		SingleCNode<T>* ptrND = &NewNode;
		if (!head) {
			head = ptrND;
			ptrND->next = head;
			tail = ptrND;
			size++;
		}
		else {
			tail->next = ptrND;
			tail = ptrND;
			tail->next = head;
			size++;
		}
	}
	void NewNode(T data) {
		SingleCNode<T>* ptrND = new SingleCNode<T>(data);
		if (!head) {
			head = ptrND;
			ptrND->next = head;
			tail = head;
			size++;
		}
		else {
			tail->next = ptrND;
			tail = ptrND;
			tail->next = head;
			size++;
		}
	}
	void NewNodeAt(T data, int index) {
		SingleCNode<T>* ptrND = new SingleCNode<T>(data);
		if (index >= size && index != 0) {
			cout << "Index out of range";
			return;
		}
		if (!head) {
			head = ptrND;
			ptrND->next = head;
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
			tail->next = head;
			size++;
			return;
		}
		int count = 1;
		SingleCNode<T>* prev = head->next;
		for (count; count < index - 1; count++) {
			prev = prev->next;
		}
		SingleCNode<T>* nxt = prev->next;
		prev->next = ptrND;
		ptrND->next = nxt;
		size++;
	}
	void SetNodeAt(SingleCNode<T> NewNode, int index) {
		SingleCNode<T>* ptrND = &NewNode;
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
			tail->next = head;
			size++;
			return;
		}
		int count = 1;
		SingleCNode<T>* prev = head->next;
		for (count; count < index - 1; count++) {
			prev = prev->next;
		}
		SingleCNode<T>* nxt = prev->next;
		prev->next = ptrND;
		ptrND->next = nxt;
		size++;
	}
	void UpadateNode(T data, int index) {
		if (!head) {
			cout << "Empty list";
			return;
		}
		if (index >= size && index != 0)
			cout << "Index out of range";
		else {
			int count = 0;
			SingleCNode<T>* n = head;
			for (count; count < index; count++) {
				n = n->next;
			}
			n->data = data;
		}
	}
	void SearchData(T data) {
		if (!head) {
			cout << "Empty list";
			return;
		}
		SingleCNode<T>* n = head;
		int check = 0;
		for (int i = 0; i < size ; i++) {
			if (n->data == data) {
				cout << "Data: " << data << "\n Was found at index: " << i << std::endl;
				check++;
			}
			n = n->next;

		}
		if (check == 0)
			cout << "Data not found in list" << std::endl;
	}
	void DeleteLast() {
		if (!head) {
			cout << "Empty list";
			return;
		}
		SingleCNode<T>* prev = head;
		for (int i = 0; i < size - 2; i++) {
			prev = prev->next;
		}
		delete(tail);
		prev->next = head;
		tail = prev;
		size--;

	}
	void DeleteHead() {
		if (!head) {
			cout << "Empty list";
			return;
		}
		SingleCNode<T>* n = head->next;
		SingleCNode<T>* n2 = head;
		delete(head);
		head = n;
		tail->next = head;
		size--;
		
	}
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
			SingleCNode<T>* n = head->next;
			SingleCNode<T>* n2 = head;
			delete(head);
			head = n;
			tail->next = head;
			size--;
			return;
		}
		if (index == size - 1) {
			SingleCNode<T>* prev = head;
			for (int i = 0; i < size - 2; i++) {
				prev = prev->next;
			}
			delete(tail);
			prev->next = head;
			tail = prev;
			size--;
		}
		else {
			SingleCNode<T>* prev = head;
			SingleCNode<T>* nxt = head->next;
			for (int i = 0; i < index - 1; i++) {
				prev = nxt;
				nxt = nxt->next;
			}
			prev->next = nxt->next;
			delete(nxt);
			size--;
		}
	}
	void GetSpin(int value) {
		SingleCNode<T>* n = head;
		for (int i=0; i < value; i++) {
			cout << n->data << " ";
			n = n->next;
		}
			
	}
};

