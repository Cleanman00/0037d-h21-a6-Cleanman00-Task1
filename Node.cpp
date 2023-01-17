#include "Header.h"
#include <iostream>
using namespace std;

Node::Node(int inData)
{
	data = inData;
	next = 0;
	previous = 0; 
}

int Node::getData() {
	return data;
}
void Node::setData(int inData) {
	data = inData;
}
Node* Node::getNext() {
	return next;
}
void Node::setNext(Node* inNext) {
	next = inNext;
}
Node* Node::getPrev() {
	return previous;
}
void Node::setPrev(Node* inPrev) {
	previous = inPrev;
}

bool DoublyLinkedList::add(Node* node, int pos) {

	//First node
	if (sizeList == 0) {

		head = node;
		tail = node;
		sizeList++;

		node->setNext(nullptr);
		node->setPrev(nullptr);

		cout << "new node has been added" << endl;
		return true;
	}
	
	/*
	if (pos == 0) {
		head->setPrev(node);
		head = head->getPrev();
		node->setPrev(nullptr);

	}
	*/

	if (pos > sizeList || node == nullptr){
		cout << "false" << endl;
		return false;
	}

	Node* s = head;
	for (int i = 0; i < pos-1; i++)
	{
		s = s->getNext();
	}

	if (s->getNext() == nullptr) {
		s->setNext(node);
		node->setNext(nullptr);
		tail = node;
		node->setPrev(s);
		sizeList++;
		cout << "new node has been added" << endl;
		return true;
	}
	else {
		node->setNext(s->getNext());
		node->getNext()->setPrev(node);
		s->setNext(node);
		node->setPrev(s);
		sizeList++;
		cout << "new node has been added" << endl;
		return true;
	}


}
		

bool DoublyLinkedList::remove(int pos) {

	if (nodeAt(pos) == nullptr || pos >= sizeList) {
		cout << "false" << endl;
		return false;
	}
	if (nodeAt(pos) == head) {
		head->getNext()->setPrev(nullptr);
		head = head->getNext();
		--sizeList;
		cout << "a node has been deleted" << endl;
		return true;
	}
	if (pos == sizeList - 1 ) {
		tail->getPrev()->setNext(nullptr);
		tail = tail->getPrev();
		--sizeList;
		cout << "a node has been deleted" << endl;
		return true;
	}
	Node* remove = nodeAt(pos);
	remove->getNext()->setPrev(remove->getPrev());
	remove->getPrev()->setNext(remove->getNext());
	--sizeList;
	cout << "a node has been deleted" << endl;
	return true;
	
}

bool DoublyLinkedList::replace(Node* old, Node* naw) {
	if (naw == NULL || old == NULL) {
		cout << "false" << endl;
		return false;
	}
	else {
		Node* saveNext = old->getNext();
		Node* savePrev = old->getPrev();

		naw->setNext(saveNext);
		naw->setPrev(savePrev);

		old->setNext(nullptr);
		old->setPrev(nullptr);
		cout << "new node has replace the old" << endl;
		return true;
	}
}
int DoublyLinkedList::search(Node* node) {

	if (node == head) {
		cout << "0" << endl;
		return 0;
	}
	for (int i = 0; i < sizeList; i++)
	{

		if (nodeAt(i)->getData() == (node->getData()) - 1) {
			cout << "position " << i << endl;;
			return i;
		}
	}
	cout << "dose not exsists" << endl;
	return -1;
}
Node* DoublyLinkedList::nodeAt(int pos) {
	int current = 0;
	Node* at = head;
	if (current == pos) {
		return at;
	}
	else {
		while (current <= pos) {
			if (current == pos) {
				return at;
			}
			else {
				current++;
				if (at == nullptr) {
					break;
				}
				at = at->getNext();
			}
		}
		cout << "there is no node at " << pos << endl;
		return nullptr;
	}

}
void DoublyLinkedList::display_backward() {
	Node* display = tail;
	for (int i = sizeList -1; i >= 0; i--)
	{
		display->getData();
		cout << display->getData() << endl;
		display = display->getPrev();

	}
	cout << endl;

}
void DoublyLinkedList::display_forward() {
	Node* display = head;
	for (int j = 0; j < sizeList; j++)
	{
		display->getData();
		//cout << display << endl;
		cout << display->getData() << endl;
		display = display->getNext();

	}
	cout << endl;
}
int DoublyLinkedList::size() {
	cout << "List size " << sizeList << endl;
	return sizeList;
}