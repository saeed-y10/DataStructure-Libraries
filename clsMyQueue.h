#pragma once

#include <iostream>
#include <string>
#include "clsDblLinkedList.h"

using namespace std;

template <class T> class clsMyQueue
{

protected:

	clsDblLinkedList<T> _List;

public:
	
	void push(T Item)
	{
		_List.InsertAtEnd(Item);
	}

	void pop()
	{
		_List.DeleteFirstNode();
	}

	void Print()
	{
		_List.PrintList();
	}

	int Size()
	{
		return _List.Size();
	}

	bool IsEmpty()
	{
		return _List.IsEmpty();
	}

	T front()
	{
		return _List.GetItem(0);
	}

	T back()
	{
		return _List.GetItem(_List.Size() - 1);
	}

	T GetItem(int Index)
	{
		return _List.GetItem(Index);
	}

	void Reverse()
	{
		_List.Reverse();
	}

	void UpdateItem(int Index, T NewValue)
	{
		_List.UpdateItem(Index, NewValue);
	}

	void InsertAfter(int Index, T value)
	{
		_List.InsertAfter(Index, value);
	}

	void InsertAtFront(T value)
	{
		_List.InsertAtBeginning(value);
	}

	void InsertAtBack(T value)
	{
		_List.InsertAtEnd(value);
	}

	void Clear()
	{
		_List.Clear();
	}

};

