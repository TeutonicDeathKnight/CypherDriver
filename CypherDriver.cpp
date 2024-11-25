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
void encryptDecrypt(int selection, ProcessedMessage& message);
int displayMenu();
string getInputFromUser(string prompt, string eMessage, bool key);
void tokenizeFile(ProcessedMessage& message, ifstream& file, const int& sel);
bool validateNotEmptyString(string strToTest);
void clearInputStream();

int main()
{
	cout << "Zachary Seeley -- Lab 5 - Pointers" << endl << endl;

	int selection;
	string encryptionKey = "";

	//display menu, ask for encryption key, and encrypt/decrypt messages until 3 is input
	do
	{
		selection = displayMenu();

		if (selection != 3)
		{
			if (selection == 1 || encryptionKey == "")
				encryptionKey =
					getInputFromUser("Enter an encryption/decryption key: ",
						"Enter an encryption/decryption key as a string of letters.\n"
						"The same key must be used for encryption and decryption "
						"for correct results.\n",
						true);

			ProcessedMessage message(encryptionKey);
			
			encryptDecrypt(selection, message);
		}
	} while (selection != 3);

	//Closing program statements
	system("pause");
	return 0;
}

//function definitions

//encryptDecrypt()
void encryptDecrypt(int selection, ProcessedMessage& message)
{
	ifstream inFile;
	ofstream outFile;
	bool validInput = false;
	string fileName;

	string eMessage =
		"Enter the correct and valid file name with "
		"full path and file extension.\n\n";

	//prompt and reprompt user for input until valid input is given
	do
	{
		string prompt;
		if (selection == 1)
			prompt = "Enter the name of the file to encrypt: ";
		else if (selection == 2)
			prompt = "Enter the name of the file to decrypt: ";

		fileName = getInputFromUser(prompt, eMessage, false);

		inFile.open(fileName);

		//if file is not open, output error
		if (!inFile.is_open())
		{
			cout << "Input was invalid or file does not exist." << endl
				<< eMessage << endl << endl;
		}
		else
		{
			tokenizeFile(message, inFile, selection);

			validInput = true;
		}

		inFile.close();

	} while (validInput == false);

	message.outputText();

	cout << "Words in the message: " << message.numberWordsInMessage()
		<< endl << endl;

	if (selection == 1)
	{
		fileName = getInputFromUser("Enter the name of the new file to create: ",
			eMessage, false);

		message.createFile(fileName);
	}

	//pause program to allow viewing of file input
	system("pause");
	cout << endl;
}

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
		{
			cout << endl << endl;
			validSelection = true;
		}

	} while (validSelection == false);

	clearInputStream();

	return inputSelection;
}

//getInputFromUser()
string getInputFromUser(string prompt, string eMessage, bool key)
{
	bool validInput = false;
	string fileName = "", input = "";

	//prompt and reprompt user for input until valid input is given
	do
	{
		cout << prompt;

		getline(cin, input);

		//if encryption key input is requested
		//	verify input contains at least one alphabetic character
		//else verify fileName input is not blank
		if (key == true)
		{
			//loop through input adding all alphabetic characters to fileName
			for (int i = 0; i < input.length(); i++)
				if ((input[i] >= 'A' && input[i] <= 'Z')
					|| (input[i] >= 'a' && input[i] <= 'z'))
					fileName += input[i];

			//if no alphabetic characters are in input, output error
			//	else set validInput to true
			if (fileName.length() == 0)
			{
				cout << endl
					<< "Encryption/Decryption key must be alphabetic letters.\n"
					<< "Input must contain at least one alphabetic character."
					<< endl << endl;
			}
			else
			{
				cout << endl;
				validInput = true;
			}
		}
		else
		{
			fileName = input;

			//if fileName is blank, output error, else set validInput to true
			if (validateNotEmptyString(fileName) == false)
				cout << endl << endl
				<< "Input is blank and cannot be blank." << endl << eMessage;
			else
			{
				cout << endl;
				validInput = true;
			}
		}
	} while (validInput == false);

	return fileName;
}

//tokenizeFile()
void tokenizeFile(ProcessedMessage& message, ifstream& file, const int& sel)
{
	int length = 0;
	int j = 0;
	string line;
	char* c;

	//loop through file, counting the number of characters in each line, adding to total
	while (getline(file, line))
		length += line.length() + 3;

	//clear eof flag
	file.clear();
	//return to beginning of file
	file.seekg(0);

	//set c to new char array with length of file plus line termination characters
	c = new char[length];

	//loop through file
	while (getline(file, line))
	{
		//loop through line
		for (int i = 0; i < line.length() && j < length - 2; i++)
		{
			//if current character is alphabetic or a space, add to next item in c-string c
			if ((line[i] >= 'A' && line[i] <= 'Z')
				|| (line[i] >= 'a' && line[i] <= 'z')
				|| line[i] == ' ')
			{
				c[j] = line[i];
				j++;
			}
		}

		//if is still less than length of c-string
		//	append " \n " to c-string to signify end of line
		if (j < length - 1)
		{
			c[j] = ' ';
			j++;

			c[j] = '\n';
			j++;

			c[j] = ' ';
			j++;
		}
	}

	//set next character after end of string to null character
	c[j] = '\0';

	//output file contents to screen looping through c-string c
	for (int i = 0; i < j; i++)
		//do not output current character if
		//  previous character is newline and current character is space
		if (!(c[i - 1] == '\n' && c[i] == ' '))
			cout << c[i];

	cout << endl << endl;

	//set state variable to null, use strtok_s to parse through c-string c
	char* state = NULL;
	char* token = strtok_s(c, " ", &state);

	//loop over c-string c while token does not equal NULL
	//	once token = null, there is nothing else in c-string c
	while (token != NULL)
	{
		//use encryptToken() or decryptToken() based on selection
		if (sel == 1)
			message.encryptToken(token);
		else if (sel == 2)
			message.decryptToken(token);

		//set token to next word in c-string c
		token = strtok_s(NULL, " ", &state);
	}
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