// 0037d-h21-a6-Cleanman00-Task1.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "Header.h"
#include <iostream>

int main()
{
    Node* n0 = new Node();
    Node* n1 = new Node();
    Node* n2 = new Node();
    Node* n3 = new Node();
    Node* n4 = new Node();

    DoublyLinkedList list;

    list.add(n0, 0);
    //list.Add(&n1, 10); //should be a false or -1 (error/invalid) 
    //list.Add(nullptr, 1); //should be a false or -1 (error/invalid) 
    list.add(n1, 1);
    //list.Remove(3); //should be a false or -1 (error/invalid) 
    list.add(n2, 2);
    list.display_forward();
    list.add(n3, 1);
    list.display_forward();
    list.remove(2);
    list.display_forward();
    list.display_backward();
    //list.Search(&n4); //should be a false or -1 (error/invalid) 
    list.search(n3);
    //list.Replace(&n3, nullptr); //should be a false or -1 (error/invalid) 
    //list.Replace(&n5, &n4); //should be a false or -1 (error/invalid) 
    list.replace(n3, n4);
    list.display_forward();
    list.size();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
