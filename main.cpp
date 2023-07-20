// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Programmer : Saeed Lahmdi

#include <iostream>
#include "clsMyString.h"

using namespace std;

int main()
{
	cout << "\n\nUndo & Redo";
	cout << "\n____________________\n";

	clsMyString S1;

	S1.Value = "";
	cout << "\nS1 = " << S1.Value;

	S1.Value = "Saeed1";
	cout << "\nS1 = " << S1.Value;

	S1.Value = "Saeed2";
	cout << "\nS1 = " << S1.Value;
	
	S1.Value = "Saeed3";
	cout << "\nS1 = " << S1.Value;


	cout << "\n\nUndo:";
	cout << "\n____________________\n";

	S1.Undo();
	cout << "\nS1 = " << S1.Value;
	
	S1.Undo(); 
	cout << "\nS1 = " << S1.Value;

	S1.Undo(); 
	cout << "\nS1 = " << S1.Value;

	cout << "\n\nRedo:";
	cout << "\n____________________\n";

	S1.Redo();
	cout << "\nS1 = " << S1.Value;

	S1.Redo();
	cout << "\nS1 = " << S1.Value;

	S1.Redo();
	cout << "\nS1 = " << S1.Value << "\n";

	system("pause > 0");
	return 0;
}
