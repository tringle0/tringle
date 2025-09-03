#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	vector<string> wordList;
	string lettersToInclude;
	cin >> lettersToInclude;
	string input;
	while (true) {
		cin >> input;
		for (char c : lettersToInclude) {
			if (input.find(c) != string::npos) {
				cout << input << endl;
				break;
			}
		}
		if (input == "///") break;
	}
}