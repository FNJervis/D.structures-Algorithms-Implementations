#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <malloc.h>
#include <string>
using std::cout;
using std::string;
using std::cin;
//Igual funcionoamiento que la lista singular pero implementado con un pointer extra en cada node el cual apunta al node anterior

template<class T>
class DoubleNode
{
public:
	T data;
	DoubleNode<T>* next;
	DoubleNode<T>* prev;

	DoubleNode(T _data) {
		data = _data;
		prev = NULL;
		next = NULL;
	}
};
template<class T>
class DoublyLinkedList
{
public:
	DoubleNode<T>* head;
	DoubleNode<T>* tail;
	int size;
	DoublyLinkedList() {
		head = NULL;
		size = 0;
	}
	DoublyLinkedList(DoubleNode<T> _head) {
		PushNode(_head);
	}
	void PrintAll() {
		if (!head) {
			cout << "Empty List";
			return;
		}
		DoubleNode<T>* n = head;
		while (n) {
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
		DoubleNode<T>* n = head;
		while (count != index) {
			count++;
			n = n->next;
		}
		cout << "Data at index" << index << ": " << n->data << std::endl;
	}
	void PushNode(DoubleNode<T> NewNode) {
		DoubleNode<T>* ptrND = &NewNode;
		if (!head) {
			head = ptrND;
			tail = ptrND;
			size++;
		}
		else {
			tail->next = ptrND;
			tail = ptrND;
		}
	}
	void NewNode(T data) {
		DoubleNode<T>* ptrND = new DoubleNode<T>(data);
		if (!head) {
			head = ptrND;
			tail = ptrND;
			size++;
		}
		else {
			tail->next = ptrND;
			ptrND->prev = tail;
			tail = ptrND;
		}
	}
	void NewNodeAt(T data, int index) {
		DoubleNode<T>* ptrND = new DoubleNode<T>(data);
		if (index >= size && index != 0) {
			cout << "Index out of range";
			return;
		}
		if (!head) {
			head = ptrND;
			tail = ptrND;
			size++;
			return;
		}
		if (index == 0) {
			ptrND->next = head;
			head->prev = ptrND;
			head = ptrND;
			size++;
			return;
		}
		if (index = size - 1) {
			tail->next = ptrND;
			ptrND->prev = tail;
			tail = ptrND;
			return;
		}
		int count = 1;
		DoubleNode<T>* nxt = head->next;
		for (count; count < index; count++) {
			nxt = nxt->next;
		}
		DoubleNode<T>* prev = nxt->prev;
		prev->next = ptrND;
		ptrND->next = nxt;
		ptrND->prev = prev;
		nxt->prev = ptrND;
		size++;
	}
	void SetNodeAt(DoubleNode<T> NewNode, int index) {
		DoubleNode<T>* ptrND = &NewNode;
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
			head->prev = ptrND;
			head = ptrND;
			size++;
			return;
		}
		if (index = size - 1) {
			tail->next = ptrND;
			tail = ptrND;
			return;
		}
		int count = 1;
		DoubleNode<T>* nxt = head->next;
		for (count; count < index; count++) {
			nxt = nxt->next;
		}
		DoubleNode<T>* prev = nxt->prev;
		prev->next = ptrND;
		ptrND->next = nxt;
		ptrND->prev = prev;
		nxt->prev = ptrND;
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
			DoubleNode<T>* n = head;
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
		DoubleNode<T>* n = head;
		int count = 0, check = 0;
		while (n) {
			if (n->data == data) {
				cout << "Data: " << data << "\n Was found at index: " << count << std::endl;
				check++;
			}
			count++;
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
		DoubleNode<T>* prev = tail->prev;
		delete(tail);
		prev->next = NULL;
		tail = prev;
	}
	void DeleteHead() {
		if (!head) {
			cout << "Empty list";
			return;
		}
		DoubleNode<T>* n = head->next;
		delete(head);
		head = n;
		n->prev = NULL;
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
			DoubleNode<T>* n = head->next;
			delete(head);
			head = n;
			size--;
		}
		if (index == size - 1) {
			DoubleNode<T>* prev = tail->prev;
			delete(tail);
			prev->next = NULL;
		}
		else {
			DoubleNode<T>* nxt = head->next;
			for (int i = 0; i < index - 1; i++) 
				nxt = nxt->next;
			DoubleNode<T>* prev = nxt->prev;
			prev->next = nxt->next;
			nxt->next->prev = prev;
			delete(nxt);
			size--;
		}
	}
};

