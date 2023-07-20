#pragma once

#include <iostream>
#include <string>

using namespace std;

template <class T> class clsDblLinkedList
{

private:

	int _Size;

public:

	clsDblLinkedList()
	{
		_Size = 0;
		head = NULL;
	}

	class Node
	{

	public:

		T value;
		Node* next;
		Node* prev;

		Node()
		{
			next = NULL;
			prev = NULL;
		}

	};

	Node* head = NULL;
	
	Node* Find(T value)
	{
		Node* Current = head;

		while (Current != NULL)
		{
			if (Current->value == value)
				return Current;

			Current = Current->next;
		}

		return NULL;
	}

	void InsertAtBeginning(T value)
	{
		Node* new_node = new Node();

		new_node->value = value;
		new_node->next = head;
		new_node->prev = NULL;

		if (head != NULL)
			head->prev = new_node;

		head = new_node;

		_Size++;
	}

	void InsertAfter(Node* curr_node, T value)
	{
		if (curr_node == NULL)
			return;

		Node* new_node = new Node();

		new_node->value = value;
		new_node->next = curr_node->next;
		new_node->prev = curr_node;

		if (curr_node->next != NULL)
			curr_node->next->prev = new_node;

		curr_node->next = new_node;

		_Size++;
	}

	void InsertAtEnd(T value)
	{
		Node* new_node = new Node();

		new_node->value = value;
		new_node->next = NULL;
		new_node->prev = NULL;

		if (head == NULL)
		{
			head = new_node;
		}

		else
		{
			Node* last_node = head;

			while (last_node->next != NULL)
			{
				last_node = last_node->next;
			}

			last_node->next = new_node;
			new_node->prev = last_node;
			}

		_Size++;
	}

	void DeleteNode(Node*& NodeToDelete)
	{
		if (NodeToDelete == NULL || head == NULL)
			return;

		if (head == NodeToDelete)
			head = NodeToDelete->next;

		if (NodeToDelete->next != NULL)
			NodeToDelete->next->prev = NodeToDelete->prev;

		if (NodeToDelete->prev != NULL)
			NodeToDelete->prev->next = NodeToDelete->next;

		delete NodeToDelete;

		_Size--;
	}

	void DeleteFirstNode()
	{
		if (head == NULL)
			return;

		Node* first_node = head;

		head = head->next;

		if (head != NULL)
			head->prev = NULL;

		delete first_node;

		_Size--;
	}

	void DeleteLastNode()
	{
		if (head == NULL)
			return;

		if (head->next == NULL)
		{
			delete head;
			head = NULL;
		}

		else
		{
			Node* curr_node = head;
			Node* prev_node = head;

			while (curr_node->next != NULL)
			{
				prev_node = curr_node;
				curr_node = curr_node->next;
			}

			prev_node->next = NULL;

			delete curr_node;
		}

		_Size--;
	}

	void PrintList()
	{
		Node* Current = head;

		while (Current != NULL)
		{
			cout << Current->value << " ";
			Current = Current->next;
		}

		cout << "\n";
	}

	bool IsEmpty()
	{
		return _Size == 0;
	}

	int Size()
	{
		return _Size;
	}

	void Clear()
	{
		while (_Size > 0)
		{
			DeleteFirstNode();
		}
	}

	void Reverse()
	{
		Node* current = head;
		Node* temp = nullptr;

		while (current != nullptr)
		{
			temp = current->prev;
			current->prev = current->next;
			current->next = temp;

			current = current->prev;
		}

		if (temp != nullptr)
			head = temp->prev;
	}

	Node* GetNode(int Index)
	{
		if (Index < 0 || Index > _Size - 1)
			return NULL;

		int Counter = 0;
		Node* Current = head;

		while (Current != NULL && (Current->next != NULL))
		{

			if (Counter == Index)
				break;

			Current = Current->next;
			Counter++;
		}

		return Current;
	}

	T GetItem(int Index)
	{
		Node* ItemNode = GetNode(Index);

		return (ItemNode == NULL ? NULL : ItemNode->value);
	}

	bool UpdateItem(int Index, T NewValue)
	{
		Node* ItemNode = GetNode(Index);

		if (ItemNode != NULL)
		{
			ItemNode->value = NewValue;
			return true;
		}

		return false;
	}

	bool InsertAfter(int Index, T value)
	{
		Node* ItemNode = GetNode(Index);

		if (ItemNode != NULL)
		{
			InsertAfter(ItemNode, value);
			return true;
		}

		return false;
	}

	bool DeleteNode(int Index)
	{
		Node* NodeToDelete = GetNode(Index);

		if (NodeToDelete != NULL)
		{
			DeleteNode(NodeToDelete);
		}

		return false;
	}

	Node* GetFirstNode()
	{
		return GetNode(0);
	}

	Node* GetLastNode()
	{
		return GetNode(_Size - 1);
	}

};

