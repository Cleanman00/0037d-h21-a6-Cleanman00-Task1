#include "Header.h"
#include <iostream>
using namespace std;

Node::Node(int inData)
{
	data = inData;
	next = NULL; 
	previous = NULL;
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
	if (sizeList == pos) {
		
		head = node;
		tail = node;
		sizeList++;

		return true;
	}
	// Add infront of head
	if (nodeAt(pos)->getPrev() == NULL) {
		head = node;
		node->setData(pos);
		nodeAt(pos)->setPrev(node);
		sizeList++;
		return true;
	}
	// Add to the back of the list
	if (pos == sizeList) {

		node->setData(pos);
		tail->setNext(node);
		node->setNext(NULL);
		node->setPrev(tail);
		tail = node;
		sizeList++;
		return true;
	
	}
	//insert in list
	if (search(nodeAt(pos)) == pos) {
		node->setData(pos);
		node->setPrev(nodeAt(pos));
		node->setNext(nodeAt(pos)->getNext());
		node->getNext()->setPrev(node);
		node->getPrev()->setNext(node);
	}
	else {
		return false;
	} 
}
bool DoublyLinkedList::remove(int pos) {

	Node* toRemove = nodeAt(pos);
	if (toRemove == nullptr) {
		return false;
	}
	else {
		toRemove->getNext()->setPrev(toRemove->getPrev());
		toRemove->getPrev()->setNext(toRemove->getNext());
		sizeList--;
		cout << toRemove << "has been deleted" << endl;
		delete toRemove;
		return true;
	}
}
bool DoublyLinkedList::replace(Node* old, Node* naw) {
	if (naw == NULL || old == NULL) {
		return false;
	}
	else {
		Node* saveNext = old->getNext();
		Node* savePrev = old->getPrev();
		delete old;
		naw->setNext(saveNext);
		naw->setPrev(savePrev);
		return true;
	}
}
int DoublyLinkedList::search(Node* node) {

	int index = 0;
	Node* searchNode = head;
	while (index != size()) {
		if (searchNode == node) {
			cout << index << endl;
			return index;
		}
		else {
			index++;
			searchNode = searchNode->getNext();
		}
	}
	return -1;
}
Node* DoublyLinkedList::nodeAt(int pos) {
	int current = 0;
	Node* at = head;
	while (current != pos) {
		if (current == pos) {
			cout << at << endl;
			return at;
		}
		else {
			current++;
			at = at->getNext();
		}
	}
	return nullptr;


}
void DoublyLinkedList::display_forward() {
	Node* display = tail;
	for (int i = sizeList; i > 0; i--)
	{
		display->getData();
		cout << display->getData() << endl;
		display = display->getPrev();

	}
}
void DoublyLinkedList::display_backward() {
	Node* display = head;
	for (int i = 0; i < sizeList; i++)
	{
		display->getData();
		cout << display->getData() << endl;
		display = display->getNext();

	}
}
int DoublyLinkedList::size() {
	return sizeList;
}