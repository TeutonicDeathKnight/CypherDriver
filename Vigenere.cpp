#include <string>
#include "Vigenere.h"

using namespace std;

void Vigenere::setKey(string k)
{

}

string Vigenere::getKey() const { return key; }

string Vigenere::toUpperCase(string k)
{
	return k;
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