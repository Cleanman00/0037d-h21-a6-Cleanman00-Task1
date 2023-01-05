#pragma once

class Node {
public:
	int value;
	Node* next;
	Node* previous;

	int getData();
	void setData(int data);
	Node* getNext();
	void setNext(Node* next);
	Node* getPrev();
	void setPrev(Node* prev);
};

class DoublyLinkedList {
public:
	Node* head;
	Node* tail;

	bool add(Node* data, int pos);
	bool remove(int pos);
	bool replace(Node *old, Node *naw);
	int search(Node* data);
	Node* nodeAt(int pos);
	void display_forward();
	void display_backward();
	int size();
};


