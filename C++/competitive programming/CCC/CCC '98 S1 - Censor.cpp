#include <iostream>
#include <string>
using namespace std;

//CCC '98 S1 - Censor
//https://dmoj.ca/problem/ccc98s1
//2-24-2025

int main() {
	string input;
	getline(cin, input); int n = stoi(input);
	for (int k = 0; k < n; k++) {
		getline(cin, input); input += ' ';
		int lastspace, currspace = -1;
		for (int c = 0; c < input.length(); c++) {
			if (input.at(c) == ' ') {
				lastspace = currspace;
				currspace = c;
				if (currspace - lastspace == 5) {
					input.at(c-1) = '*';
					input.at(c-2) = '*';
					input.at(c-3) = '*';
					input.at(c-4) = '*';
				}
			}
		}
		cout << input << endl;
	}
}