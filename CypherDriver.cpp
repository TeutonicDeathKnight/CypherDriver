//CypherDriver.cpp -- Encrypt and decrypt text using the Vigenere cypher
//CSIS 212-<D02_202440>

//Sources
//Encrypt and decrypt logic in Vignere.cpp taken from lab instructions
//validateNotEmptyString() taken from my lab 4 submission

//include and using statements
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Vigenere.h"
#include "ProcessedMessage.h"

using namespace std;

//function prototypes
int displayMenu();
string getEncryptionKeyFromUser();

bool validateNotEmptyString(string strToTest);
void clearInputStream();

int main()
{
	cout << "Zachary Seeley -- Lab 5 - Pointers" << endl << endl;

	int selection;
	string encryptionKey;

	do
	{
		selection = displayMenu();

		cout << endl << endl;

		if (selection != 3)
			encryptionKey = getEncryptionKeyFromUser();



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

	clearInputStream();

	return inputSelection;
}

//getEncryptionKeyFromUser()
string getEncryptionKeyFromUser()
{
	bool validInput = false;
	string output;

	do
	{
		cout << "Enter an encryption/decryption key:" << endl;

		getline(cin, output);

		if (cin.fail() || validateNotEmptyString(output) == false)
			cout << endl << endl
			<< "Input was invalid or blank." << endl
			<< "Enter an encryption/decryption key as a string of letters.\n"
			<< "Any numbers or special characters will be removed from input."
			<< endl << endl;
		else
			validInput = true;

	} while (validInput == false);

	return output;
}

//validateNotEmptyString()
bool validateNotEmptyString(string strToTest)
{
	bool containsNonWhitespaceChars = false;
	string str = strToTest;

	//loop through strToTest
	for (int position = 0; position < str.length(); position++)
	{
		char evalChar = str[position];

		//if current character is one of the 6 whitespace characters
		// replace with the null character
		if (evalChar == 9
			|| evalChar == 10
			|| evalChar == 11
			|| evalChar == 12
			|| evalChar == 13
			|| evalChar == 32)
		{
			str[position] = '\0';
		}
	}

	//loop through string and if a non whitespace character is found
	// set containsNonWhitespaceChars to true and break out of loop
	for (int position = 0; position < str.length(); position++)
		if (str[position] != '\0')
		{
			containsNonWhitespaceChars = true;
			break;
		}

	//if input is only whitespace characters, output error message
	if (containsNonWhitespaceChars == false)
	{
		cout << endl << "Input cannot be blank or only whitespace characters." << endl
			<< "Press enter to continue." << endl;
	}

	return containsNonWhitespaceChars;
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