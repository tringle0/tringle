#include <iostream>
#include <unordered_map>
using namespace std;

//CCC '16 S1 - Ragaman
//https://dmoj.ca/problem/ccc16s1
//7-29-2025

int main() {
	string a, b; cin >> a >> b;
	unordered_map<char, int> letterCountA;
	unordered_map<char, int> letterCountB;
	for (char c : a) letterCountA[c]++;
	for (char c : b) {
		if (letterCountA[c] < ++letterCountB[c] && c!= '*') {
			cout << "N"; return 0;
		}
	}
	
	int missing = 0;
	for (auto k : letterCountA) {
		char current = k.first;
		missing += letterCountA[current] - letterCountB[current];
	}

	cout << (missing <= letterCountB['*']?"A":"N");
}