#pragma once

#include <iostream>
#include <string>
#include "clsDynamicArray.h"
#include "clsMyQueueArr.h"

using namespace std;

template <class T> class clsMyStackArr : public clsMyQueueArr<T>
{
private:

public:

	void push(T Item)
	{
		clsMyQueueArr<T>::InsertAtFront(Item);
	}

	void pop()
	{
		clsMyQueueArr<T>::DeleteFirstItem();
	}

	void Print()
	{
		clsMyQueueArr<T>::Print();
	}

	int Size()
	{
		return clsMyQueueArr<T>::Size();
	}

	bool IsEmpty()
	{
		clsMyQueueArr<T>::IsEmpty();
	}

	T Top()
	{
		return clsMyQueueArr<T>::front();
	}

	T Bottom()
	{
		return clsMyQueueArr<T>::back();
	}

	T GetItem(int Index)
	{
		return clsMyQueueArr<T>::GetItem(Index);
	}

	void Reverse()
	{
		clsMyQueueArr<T>::Reverse();
	}

	void UpdateItem(int Index, T NewValue)
	{
		clsMyQueueArr<T>::UpdateItem(Index, NewValue);
	}

	void InsertAfter(int Index, T value)
	{
		clsMyQueueArr<T>::InsertAfter(Index, value);
	}

	void InsertAtTop(T value)
	{
		clsMyQueueArr<T>::InsertAtFront(value);
	}

	void InsertAtBottom(T value)
	{
		clsMyQueueArr<T>::InsertAtBack(value);
	}

	void Clear()
	{
		clsMyQueueArr<T>::Clear();
	}

	void DeleteFirstItem()
	{
		clsMyQueueArr<T>::DeleteFirstItem();
	}

	void DeleteLastItem()
	{
		clsMyQueueArr<T>::DeleteLastItem();
	}

	void DeleteItem(int Index)
	{
		clsMyQueueArr<T>::DeleteItem(Index);
	}

};

