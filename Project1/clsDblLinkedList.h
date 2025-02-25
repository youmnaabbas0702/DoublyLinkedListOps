#pragma once
#include <iostream>
using namespace std;

template<class T> class clsDblLinkedList
{
public:
	class Node
	{
	public:
		T Value;
		Node* Next;
		Node* Prev;
	};

public:
	Node* head = NULL;

	void PrintList()
	{
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->Value << endl;
			temp = temp->Next;
		}
	}

	void InsertAtBeginning(T value)
	{
		Node* newNode = new Node();
		newNode->Prev = NULL;
		newNode->Value = value;

		if (head == NULL)
		{
			newNode->Next = NULL;
			head = newNode;
			return;
		}

		head->Prev = newNode;
		newNode->Next = head;
		head = newNode;
	}

	Node* Find(T value)
	{
		Node* temp = head;
		while (temp != NULL)
		{
			if (temp->Value == value)
				return temp;
			temp = temp->Next;
		}
		return NULL;
	}

	void InsertAfter(Node* NodeAfter, T value)
	{
		if (NodeAfter == NULL)
		{
			cout << "The previous node cant be null\n";
			return;
		}
		Node* newNode = new Node();

		newNode->Value = value;

		newNode->Next = NodeAfter->Next;
		newNode->Prev = NodeAfter;

		if (NodeAfter->Next != NULL)
			NodeAfter->Next->Prev = newNode;

		NodeAfter->Next = newNode;
	}

	void InsertAtEnd(T value)
	{
		Node* newNode = new Node();
		newNode->Value = value;
		newNode->Next = NULL;

		if (head == NULL)
		{
			newNode->Prev = NULL;
			head = newNode;
		}

		else
		{
			Node* searchNode = head;

			while (searchNode->Next != NULL)
			{
				searchNode = searchNode->Next;
			}

			newNode->Prev = searchNode;
			searchNode->Next = newNode;
		}
	}

	void DeleteNode(Node*& NodeToDelete) 
	{
		if (head == NULL || NodeToDelete == NULL) {
			return;
		}
		if (head == NodeToDelete) {
			head = NodeToDelete->Next;
		}
		if (NodeToDelete->Next != NULL) {
			NodeToDelete->Next->Prev = NodeToDelete->Prev;
		}
		if (NodeToDelete->Prev != NULL) {
			NodeToDelete->Prev->Next = NodeToDelete->Next;
		}
		delete NodeToDelete;
	}

	void DeleteFirstNode()
	{
		//if list is empty return
		if (head == NULL)
			return;

		Node* Current = head;

		if (Current->Next != NULL)
			Current->Next->Prev = NULL;
		head = Current->Next;

		delete Current;
	}

	void DeleteLastNode()
	{
		//if list is empty return
		if (head == NULL)
			return;

		Node* Current = head;
		Node* Prev = head;

		//if it is only one node
		if (Current->Next == NULL)
		{
			head = NULL;
			delete Current;
			return;
		}

		//till we find the last node
		while (Current != NULL && Current->Next != NULL)
		{
			Prev = Current;
			Current = Current->Next;
		}

		Prev->Next = NULL;
		delete Current;
	}

};

