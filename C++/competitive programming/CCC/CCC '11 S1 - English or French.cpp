#include <iostream>
#include <string>
using namespace std;

//CCC '11 S1 - English or French?
//https://dmoj.ca/problem/ccc11s1
//2-24-2025

int main() {
	int n; cin >> n;
	int s = 0, t = 0;
	for (int k = 0; k < n+1; k++) {
		string input;
		getline(cin, input);
		for (int k = 0; k < input.size(); k++) {
			if (tolower(input.at(k)) == 's') s++;
			if (tolower(input.at(k)) == 't') t++;
		}
	}
	cout << (s >= t ? "French" : "English");
}