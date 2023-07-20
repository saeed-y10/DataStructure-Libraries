#pragma once

#include <iostream>
#include <string>
#include "clsDynamicArray.h"

using namespace std;

template <class T> class clsMyQueueArr
{

private:

	clsDynamicArray<T> _Array;

public:

	void push(T Item)
	{
		_Array.InsertAtEnd(Item);
	}

	void pop()
	{
		_Array.DeleteFirstItem();
	}

	void Print()
	{
		_Array.PrintList();
	}

	int Size()
	{
		return _Array.Size();
	}

	bool IsEmpty()
	{
		return _Array.IsEmpty();
	}

	T front()
	{
		return _Array.GetItem(0);
	}

	T back()
	{
		return _Array.GetItem(_Array.Size() - 1);
	}

	T GetItem(int Index)
	{
		return _Array.GetItem(Index);
	}

	void Reverse()
	{
		_Array.Reverse();
	}

	void UpdateItem(int Index, T NewValue)
	{
		_Array.SetItem(Index, NewValue);
	}

	void InsertAfter(int Index, T value)
	{
		_Array.InsertAfter(Index, value);
	}

	void InsertAtFront(T value)
	{
		_Array.InsertAtBeginning(value);
	}

	void InsertAtBack(T value)
	{		
		_Array.InsertAtEnd(value);
	}

	void Clear()
	{
		_Array.Clear();
	}

	void DeleteFirstItem()
	{
		_Array.DeleteFirstItem();
	}
	
	void DeleteLastItem()
	{
		_Array.DeleteLastItem();
	}

	void DeleteItem(int Index)
	{
		_Array.DeleteItem(Index);
	}

};

