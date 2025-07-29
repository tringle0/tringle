#include <iostream>
#include <string>
#include <vector>

using namespace std;

//CCC '03 S2 - Poetry
//https://dmoj.ca/problem/ccc03s2
//7-20-2025

bool isVowel(char c) {
	string vowels = "aeiouAEIOU ";
	return vowels.find(c) != string::npos;
}

string GetLastSyllable(string verse) {
	string result = "";
	for (int k = verse.length() - 1; k >= 0; k--) {
		result += tolower(verse.at(k));
		if (isVowel(verse.at(k))) {
			break;
		}
	}
	return result;
}

int main() {
	string n; 
	getline(cin, n);
	for (int k = 0; k < stoi(n); k++) {
		vector<string> S;
		for (int i = 0; i < 4; i++) {
			string input; 
			getline(cin, input);
			S.push_back(GetLastSyllable(input));
		}
		if (S[0] == S[1] && S[1] == S[2] && S[2] == S[3]) cout << "perfect\n";
		else if (S[0] == S[1] && S[2] == S[3]) cout << "even\n";
		else if (S[0] == S[2] && S[1] == S[3]) cout << "cross\n";
		else if (S[0] == S[3] && S[1] == S[2]) cout << "shell\n";
		else cout << "free\n";
	}
}