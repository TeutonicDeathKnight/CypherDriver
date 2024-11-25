#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Vigenere.h"
#include "ProcessedMessage.h"

using namespace std;

void ProcessedMessage::encryptToken(char* token)
{
	string w(token);

	//if token is not the newline character
	//	encrypt word and append to processedWordsList
	//else append token to processedWordsList
	if (*token != '\n')
	{
		processedWordsList.push_back(v.encryptWord(w));
	}
	else
	{
		processedWordsList.push_back(w);
	}
	
}

void ProcessedMessage::decryptToken(char* token)
{
	string w(token);

	//if token is not the newline character
	//	decrypt word and append to processedWordsList
	//else append token to processedWordsList
	if (*token != '\n')
	{
		processedWordsList.push_back(v.decryptWord(w));
	}
	else
	{
		processedWordsList.push_back(w);
	}
}

void ProcessedMessage::createFile(string fileName)
{
	ofstream file(fileName);

	//loop through processedWordsList adding each value to the file
	for (int i = 0; i < processedWordsList.size(); i++)
	{
		file << processedWordsList[i];

		//output space between words if the current character is not the newline character
		//	and next character is the newline character
		if (processedWordsList[i] != "\n" && processedWordsList[i + 1] != "\n")
			file << ' ';
	}

	file.close();
}

void ProcessedMessage::outputText()
{
	//loop through processedWordsList printing each value to the screen
	for (int i = 0; i < processedWordsList.size(); i++)
	{
		cout << processedWordsList[i];

		//output space between words if the current character is not the newline character
		//	and next character is the newline character
		if (processedWordsList[i] != "\n" && processedWordsList[i + 1] != "\n")
			cout << ' ';
	}

	cout << endl;
}

int ProcessedMessage::numberWordsInMessage()
{
	int num = 0;
	
	//loop through each word in processedWordsList
	for (int i = 0; i < processedWordsList.size(); i++)
		//if the current word is not the newline character
		//	increment num by 1
		if (processedWordsList[i] != "\n")
			num++;

	return num;
}

ProcessedMessage::ProcessedMessage(string k) { v.setKey(k); }