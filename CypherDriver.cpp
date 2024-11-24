//CypherDriver.cpp -- Encrypt and decrypt text using the Vigenere cypher
//CSIS 212-<D02_202440>

//Sources
//Encrypt and decrypt logic in Vignere.cpp taken from lab instructions

//include and using statements
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//function prototypes
int displayMenu();

void clearInputStream();

int main()
{
	cout << "Zachary Seeley -- Lab 5 - Pointers" << endl << endl;

	int selection;

	do
	{
		selection = displayMenu();

		

	} while (selection != 3);

	cout << endl << endl;

	//Closing program statements
	system("pause");
	return 0;
}

//function definitions

//displayMenu()
int displayMenu()
{
	bool validSelection = false;
	int inputSelection;

	do
	{
		//output the menu to the screen
		cout << " Vigenere Cypher" << endl
		 	 << "    Main Menu" << endl
			 << " 1 - Encrypt File" << endl
			 << " 2 - Decrypt File" << endl
			 << " 3 - Quit" << endl << endl
			 << " Selection:  ";

		//grab input from user
		cin >> inputSelection;

		//validate input
		//	output error message if cin enters fail state or not valid entry
		//  clear input stream if fail state or not valid entry
		//  else set validSelection flag to true to exit loop
		if (cin.fail() ||
			(inputSelection != 1 && inputSelection != 2 && inputSelection != 3))
		{
			cout << "\n\nYou did not enter a 1, 2, or 3." << endl
				<< "Input must be a numeric value between 1 and 3 inclusive."
				<< endl << endl;

			clearInputStream();
		}
		else
			validSelection = true;

	} while (validSelection == false);

	return inputSelection;
}

//clearInputStream()
void clearInputStream()
{
	//clear 
	cin.clear();
	//ignore rest of line determining max length of line
	//	until the newline character appears
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}