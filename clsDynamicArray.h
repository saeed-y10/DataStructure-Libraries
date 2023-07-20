#pragma once

#include <iostream>
#include <string>

using namespace std;

template <class T> class clsDynamicArray
{

private:

	int _Size;
	T* _TempArray{};

	void _MoveItemToEnd(int Index)
	{
		for (int i = Index; i < _Size - 1; i++)
		{
			swap(Array[i], Array[i + 1]);
		}
	}

	void _MoveItemToFront(int Index)
	{
		for (int i = Index; i > 0; i--)
		{
			swap(Array[i], Array[i - 1]);
		}
	}

public:

	T* Array;

	clsDynamicArray(int Size = 0)
	{
		if (Size < 0)
			Size = 0;

		_Size = Size;
		Array = new T[_Size];
	}

	~clsDynamicArray()
	{
		delete[] Array;
	}

	bool SetItem(int index, T value)
	{
		if (index >= _Size || index < 0)
			return false;

		Array[index] = value;

		return true;
	}

	int Size()
	{
		return _Size;
	}

	bool IsEmpty()
	{
		return _Size == 0;
	}

	void PrintList()
	{
		for (int i = 0; i < _Size; i++)
		{
			cout << Array[i] << " ";
		}

		cout << "\n";
	}

	void Resize(int NewSize)
	{
		if (NewSize < 0)
			NewSize = 0;

		_TempArray = new T[NewSize];

		if (NewSize < _Size)
			_Size = NewSize;

		for (int i = 0; i < _Size; i++)
		{
			_TempArray[i] = Array[i];
		}

		_Size = NewSize;

		delete[] Array;

		Array = _TempArray;
		_TempArray = NULL;
	}

	T GetItem(int index)
	{
		return Array[index];
	}

	void Reverse()
	{
		for (int i = 0; i < _Size / 2; i++)
		{
			swap(Array[i], Array[_Size - 1 - i]);
		}
	}

	void Clear()
	{
		_Size = 0;
		_TempArray = new T[_Size];

		delete Array;

		Array = _TempArray;
		_TempArray = NULL;
	}

	void InsertAtEnd(T Item)
	{
		Resize(_Size + 1);
		SetItem(_Size - 1, Item);
	}

	void InsertAfter(int Index, T value)
	{
		if (_Size == 0)
			return;

		if (Index < 0 || Index >= _Size)
			return;

		Resize(_Size + 1);

		for (int i = Index + 1; i < _Size - 1; i++)
		{
			swap(Array[i], Array[i + 1]);
		}

		SetItem(Index + 1, value);
	}

	void InsertAtBeginning(T Item)
	{
		Resize(_Size + 1);
		_MoveItemToFront(_Size - 1);
		SetItem(0, Item);
	}

	void DeleteItem(int Index)
	{
		if (_Size == 0)
			return;

		if (Index < 0 || Index > _Size - 1)
			return;

		_MoveItemToEnd(Index);
		Resize(_Size - 1);
	}

	void DeleteFirstItem()
	{
		if (_Size < 2)
		{
			Resize(0);
		}

		else
		{
			_MoveItemToEnd(0);
			Resize(_Size - 1);
		}
	}

	void DeleteLastItem()
	{
		Resize(_Size - 1);
	}

};

