#pragma once

#include <iostream>
#include <string>
#include "clsMyQueue.h"

using namespace std;

template <class T> class clsMyStack : public clsMyQueue <T>
{

protected:

public:

	void push(T Item)
	{
		clsMyQueue<T>::_List.InsertAtBeginning(Item);
	}

	T Top()
	{
		return clsMyQueue<T>::front();
	}

	T Bottom()
	{
		return clsMyQueue<T>::back();
	}

};

