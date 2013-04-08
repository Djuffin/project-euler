/*
Problem 59
XOR decryption

Each character on a computer is assigned a unique code and the preferred standard is ASCII (American Standard Code for Information Interchange). For example, uppercase A = 65, asterisk (*) = 42, and lowercase k = 107.

A modern encryption method is to take a text file, convert the bytes to ASCII, then XOR each byte with a given value, taken from a secret key. The advantage with the XOR function is that using the same encryption key on the cipher text, restores the plain text; for example, 65 XOR 42 = 107, then 107 XOR 42 = 65.

For unbreakable encryption, the key is the same length as the plain text message, and the key is made up of random bytes. The user would keep the encrypted message and the encryption key in different locations, and without both "halves", it is impossible to decrypt the message.

Unfortunately, this method is impractical for most users, so the modified method is to use a password as a key. If the password is shorter than the message, which is likely, the key is repeated cyclically throughout the message. The balance for this method is using a sufficiently long password key for security, but short enough to be memorable.

Your task has been made easy, as the encryption key consists of three lower case characters. Using cipher1.txt (right click and 'Save Link/Target As...'), a file containing the encrypted ASCII codes, and the knowledge that the plain text must contain common English words, decrypt the message and find the sum of the ASCII values in the original text.

*/

#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

vector<int> read_file(const string &fileName)
{
	ifstream file(fileName.c_str());
	vector<int> result;
	string str_value;

	while (file.good())
	{
		getline(file, str_value, ',');
		stringstream stream(str_value);
		int value;
		stream >> value;
		result.push_back(value);
	}
	return result;
}

void apply_xor(vector<int> &text, const vector<int> &key)
{
	int key_len = key.size();
	int key_position = 0;

	for (auto i = text.begin(); i != text.end(); i++)
	{
		*i = (*i) ^ key[key_position];
		key_position++;
		if (key_position >= key_len)
			key_position = 0;
	}
}

bool next_key(vector<int> &key)
{
	for(auto i = key.begin(); i != key.end(); i++)
	{
		if (*i < 'z')
		{
			(*i)++;
			return true;
		}
		else
		{
			*i = 'a';
		}
	}
	return false;
}

int count_spaces(const vector<int> &text)
{
	int result = 0;
	for (auto i = text.begin(); i != text.end(); i++)
	{
		if (*i == ' ')
			result++;
	}
	return result;
}
	

int main()
{
	auto text  = read_file("cipher1.txt");
	vector<int> key = {(int)'a', (int)'a', (int)'a'};
        vector<int> best_key = key;
	int max_spaces = 0;

	do
	{
		apply_xor(text, key);
		int spaces = count_spaces(text);
		if (spaces > max_spaces)
		{
			max_spaces = spaces;
			best_key = key;
		}
		apply_xor(text, key);
	} 
	while (next_key(key));

	int sum = 0;
	apply_xor (text, best_key);
	for (auto i = text.begin(); i != text.end(); i++)
	{
		cout << (char)*i;
		sum += *i;
	}
	cout << endl << "Result: " << sum << endl;

	return 0;
}
