#pragma once


//Purpose of class:
//	Contains list of strings (words) that were either encrypted or decrypted
//	Contains functions to encrypt or decrypt a word
//  Contains a function to output encrypted or decrypted words to a file
//	Contains a function to print the list of strings (words) to the screen
class ProcessedMessage
{
public:
	void encryptToken(char* token);
	//Receives one word, encrypts it, adds word to data member processedWordsList

	void decryptToken(char* token);
	//Receives one word, decrypts it, adds word to the data member processedWordsList

	void createFile(std::string fileName);
	//Creates a file outputs the data member processedWordsList to it

	void outputText();
	//Prints the data member processedWordsList to screen

	void numberWordsInMessage();
	//Returns the number of words stored in data member processedWordsList

	ProcessedMessage(std::string k);
	//Single argument constructor
	//	takes a string (key) and uses it to initialize member variable v

private:
	std::vector<std::string> processedWordsList;
	//Private vector of strings to store list of encrypted OR decrypted words
	Vigenere v;
	//Private Vigenere data member to store encryption key & to access its functions
};