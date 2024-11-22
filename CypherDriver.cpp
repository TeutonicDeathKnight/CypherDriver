// CypherDriver.cpp -- Encrypt and decrypt text using the Vigenere cypher
//CSIS 212-<D02_202440>

//Sources

//include and using statements
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//function prototypes
void displayMenu();

int main()
{
	cout << "Zachary Seeley -- Lab 5 - Pointers" << endl << endl;

	displayMenu();

	cout << endl << endl;

	//Closing program statements
	system("pause");
	return 0;
}

//function definitions

//displayMenu()
void displayMenu()
{
	//output the menu to the screen
	cout << " Vigenere Cypher" << endl
		<< "    Main Menu" << endl
		<< " 1 - Encrypt File" << endl
		<< " 2 - Decrypt File" << endl
		<< " 3 - Quit" << endl << endl
		<< " Selection:  ";
}