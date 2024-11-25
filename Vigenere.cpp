#include <string>
#include "Vigenere.h"

using namespace std;

void Vigenere::setKey(string k) { key = toUpperCase(k); }

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
		if (c >= 'a' && c <= 'z')
			output += c - 32;
		else
			output += c;
	}

	return output;
}

string Vigenere::encryptWord(string w)
{
	string output;

	//loop through w
	for (int i = 0, j = 0; i < w.length(); ++i)
	{
		char c = w[i];

		//if character is lower case alphabet
		// add the difference of upper case minus lower case a
		//else continue if upper case letter
		if (c >= 'a' && c <= 'z')
			c += 'A' - 'a';
		else if (c < 'A' || c > 'Z')
			continue;

		//subtract 2 from c and multiply by 'A'
		// then find the remainder of dividing that value by 26
		// add 'A' to bring into range of 'A'-'Z'
		output += (c + key[j] - 2 * 'A') % 26 + 'A';
		//added 'A' to bring it in range of ASCII alphabet [ 65-90 | A-Z ]

		j = (j + 1) % key.length();
	}

	return output;
}

string Vigenere::decryptWord(string w)
{
	string output;

	//loop through w
	for (int i = 0, j = 0; i < w.length(); ++i) {
		char c = w[i];

		//if character is lower case alphabet
		// add the difference of upper case minus lower case a
		//else continue if upper case letter
		if (c >= 'a' && c <= 'z')
			c += 'A' - 'a';
		else if (c < 'A' || c > 'Z')
			continue;

		//subract the key value from the character and add 26
		// find the remainder of the above value when divided by 26
		// then add 'A' to bring into range of 'A'-'Z'
		output += (c - key[j] + 26) % 26 + 'A';
		//added 'A' to bring it in range of ASCII alphabet [ 65-90 | A-Z ]

		j = (j + 1) % key.length();
	}

	return output;
}

Vigenere::Vigenere() { key = ""; }

Vigenere::Vigenere(string k) { setKey(k); }