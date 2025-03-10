#include <iostream>
#include <unordered_map>
using namespace std;

//CCC '24 S2 - Heavy-Light Composition
//https://dmoj.ca/problem/ccc24s2
//3-10-2025

int main() {
	int t, n;
	cin >> t >> n;
	for (int k = 0; k < t; k++) {
		unordered_map<char,int> occurences;
		string input; cin >> input;
		for (char c : input) {
			occurences[c]++;
		}
		bool checkheavy = occurences[input.at(0)] > 1;
		bool ans = true;
		for (char c : input) {
			if (checkheavy) {
				if (occurences[c] == 1) ans = false;
			}
			else {
				if (occurences[c] > 1) ans = false;
			}
			checkheavy = !checkheavy;
		}

		cout << (ans ? "T\n" : "F\n");
	}
}