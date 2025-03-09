#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//CCC '06 S2 - Attack of the CipherTexts
//https://dmoj.ca/problem/ccc06s2
//3-8-2025

int main() {
	unordered_set<char> letters = {{ ' '}};
	for (char k = 'A'; k <= 'Z'; k++) {
		letters.insert(k);
	}
	string plaintext, encrypted, input;
	
	getline(cin, plaintext);
	getline(cin, encrypted);
	getline(cin, input);
	unordered_map<char, char> cypher;
	string orig = input;
	for (int k = 0; k < plaintext.length(); k++) {
		cypher[encrypted.at(k)] = plaintext.at(k);
		letters.erase(plaintext.at(k));
	}

	char lastletter = '.';
	if (letters.size() == 1) lastletter = *letters.begin();

	for (int k = 0; k < input.length(); k++) {
		if (cypher.count(input.at(k)) > 0)
			input.at(k) = cypher[input.at(k)];
		else {
			input.at(k) = '.';
			if (letters.size() == 1) input.at(k) = lastletter;
		}
		
		
	}

	cout << input << endl;
}