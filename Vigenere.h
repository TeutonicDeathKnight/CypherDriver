#pragma once

//Puprose of class:
//	Store the encryption key
//	Contains logic for encrypting and decrypting individual words
class Vigenere
{
public:
	void setKey(std::string k);
	//Set private string data member key
	//	uses toUpperCase() to convert string to all uppercase letters
	//  Verify string is not blank before passing to function

	std::string getKey() const;
	//Return value of private data member key

	std::string toUpperCase(std::string k);
	//Convert string to all upper case letters and return string

	std::string encryptWord(std::string w);
	//Encrypt received string and return string

	std::string decryptWord(std::string w);
	//Decrypt received string and return string

	Vigenere();
	//Default/zero argument constructor

	Vigenere(std::string k);
	//Single argument constructor
	//	receives key and calls setKey() to update private string data member key

private:
	std::string key;
	//Private string data member to store cypher key
};
