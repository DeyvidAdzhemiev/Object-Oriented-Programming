#include <iostream>
#include <cstring>
using namespace std;

class CesarCipher
{
private:
	int ceaserShift(int shiftedValue, int key)
	{
		if (shiftedValue < 0)
			shiftedValue = key - abs(shiftedValue) % key;

		return shiftedValue % key;
	}

public:
	char* encrypt(const char* plaintext, int key)
	{
		size_t plaintextLength = strlen(plaintext);
		char* ciphertext = new char[plaintextLength + 1];
		for (size_t i = 0; i != plaintextLength; ++i)
		{
			const char ALPHABET_START_CHAR = isupper(plaintext[i]) ? 'A' : 'a';
			ciphertext[i] = ceaserShift(plaintext[i] + key - ALPHABET_START_CHAR, 26) + ALPHABET_START_CHAR;
		}
		ciphertext[plaintextLength] = '\0';

		return ciphertext;
	}

	char* decrypt(const char* ciphertext, int key) 
	{
		return encrypt(ciphertext, -1 * key);
	}

};

char* readPlaintext() 
{
	cout << "How many symbols to encrypt? ";
	size_t plaintextLength;
	cin >> plaintextLength;
	cout << "Plaintext of length " << plaintextLength << ":" << endl;
	cin.ignore();
	char* plaintext = new char[plaintextLength + 1];
	cin.getline(plaintext, plaintextLength + 1);

	return plaintext;
}


int main() 
{
	const char* initialPlaintext = readPlaintext();
	cout << "Key:";
	int key;
	cin >> key;
	CesarCipher cesarCipher;

	const char* ciphertext = cesarCipher.encrypt(initialPlaintext, key);
	delete[] initialPlaintext;
	cout << "Message encrypted: " << ciphertext << endl;

	cout << "To decrypt provide the key: ";
	cin >> key;
	const char* plaintext = cesarCipher.decrypt(ciphertext, key);
	delete[] ciphertext;
	cout << "Message decrypted: " << plaintext << endl;
	delete[] plaintext;


	return 0;
}
