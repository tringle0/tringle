#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

//CCC '20 J4 - Cyclic Shifts
//https://dmoj.ca/problem/ccc20j4
//1-15-2025

int boyermoore(string &word, string &target, int pos) {
	if (pos + target.length() > word.length()) {
		return -1;
	}
	char badchar = -1; int badcharpos;
	for (int k = target.length() - 1; k >= 0; k--) {
		if (badchar == -1) {
			if (target.at(k) != word.at(k + pos)) {
				badchar = word.at(k + pos);
				badcharpos = k;
			}
		}
		else {
			//mismatch
			if (target.at(k) == badchar) {
				return boyermoore(word,target,pos + badcharpos-k);
			}
		}
	}
	if (badchar == -1) {
		return pos;
	}
	return boyermoore(word, target, pos + target.length());
}

string shift(string str) {
	return str.substr(1, str.length() - 1) + str.at(0);
}

int main() {
	string word; cin >> word;
	string target; cin >> target;
	bool found = false;
	for (int k = 0; k < target.size(); k++) {
		if (boyermoore(word, target, 0) != -1) {
			found = true;
			break;
		}
		target = shift(target);
	}
	cout << (found ? "yes" : "no");
}