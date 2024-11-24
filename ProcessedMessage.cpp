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
	processedWordsList.push_back(v.encryptWord(w));
}

void ProcessedMessage::decryptToken(char* token)
{
	string w(token);
	processedWordsList.push_back(v.decryptWord(w));
}

void ProcessedMessage::createFile(string fileName)
{
	ofstream file(fileName);

	for (int i = 0; i < processedWordsList.size(); i++)
	{
		file << processedWordsList[i];

		if (processedWordsList[i] != "\n" && processedWordsList[i + 1] != "\n")
			file << ' ';
	}

	file.close();
}

void ProcessedMessage::outputText()
{
	for (int i = 0; i < processedWordsList.size(); i++)
	{
		cout << processedWordsList[i];

		if (processedWordsList[i] != "\n" && processedWordsList[i + 1] != "\n")
			cout << ' ';
	}

	cout << "Words in the message: " << numberWordsInMessage()
		<< endl << endl;
}

int ProcessedMessage::numberWordsInMessage()
{
	int num = 0;

	for (int i = 0; i < processedWordsList.size(); i++)
		if (processedWordsList[i] != "\n")
			num++;

	return num;
}

ProcessedMessage::ProcessedMessage(string k) { v.setKey(k); }