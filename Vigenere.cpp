#include <string>
#include "Vigenere.h"

using namespace std;

void Vigenere::setKey(string k)
{

}

string Vigenere::getKey() const { return key; }

string Vigenere::toUpperCase(string k)
{
	string output;
	//loop through string
	
	for (int i = 0; i < k.length(); i++)
	{
		char c = k[i];

		//if character is between 'a' and 'z' inclusive,
		//	subtract 32 from character to make upper case and add to output
		//		in ASCII the values for 'A' and 'a' are 32 apart
		//	if character is between 'A' and 'Z' or '0' and '9' add to output
		if (c >= 'a' && c <= 'z')
			output += c - 32;
		//for generalized toUpperCase() use, remove next else if block
		else if ((c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
			output += c;
		//for generalized toUpperCase() use, uncomment following else block
		/*else
			output += c;*/
	}

	return output;
}

string Vigenere::encryptWord(string w)
{
	string output;

	for (int i = 0, j = 0; i < w.length(); ++i)
	{
		char c = w[i];

		if (c >= 'a' && c <= 'z')
			c += 'A' - 'a';
		else if (c < 'A' || c > 'Z')
			continue;

		output += (c + key[j] - 2 * 'A') % 26 + 'A';
		//added 'A' to bring it in range of ASCII alphabet [ 65-90 | A-Z ]

		j = (j + 1) % key.length();
	}

	return output;
}

string Vigenere::decryptWord(string w)
{
	string output;

	for (int i = 0, j = 0; i < w.length(); ++i) {
		char c = w[i];

		if (c >= 'a' && c <= 'z')
			c += 'A' - 'a';
		else if (c < 'A' || c > 'Z')
			continue;

		output += (c - key[j] + 26) % 26 + 'A';
		//added 'A' to bring it in range of ASCII alphabet [ 65-90 | A-Z ]

		j = (j + 1) % key.length();
	}

	return output;
}

Vigenere::Vigenere() { key = ""; }

Vigenere::Vigenere(string k) { setKey(k); }