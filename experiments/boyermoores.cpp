
//boyer moores string searching algorithm

#include <string>
#include <iostream>

using namespace std;


int searchstr(string &word, string &target, int pos) {
	//not found
	if (pos + target.length() > word.length()) {
		return -1;
	}
	
	//mismatch
	char badchar = -1; int badcharpos;
	for (int k = target.length() - 1; k >= 0; k--) {
		if (badchar == -1) {
			//find the first incorrect char in word
			if (target.at(k) != word.at(k + pos)) {
				badchar = word.at(k + pos);
				badcharpos = k;
			}
		}
		else {
			if (target.at(k) == badchar) {
				return searchstr(word, target, pos + badcharpos - k);
			}
		}
	}
	//match
	if (badchar == -1) {
		return pos;
	}
	//bad char
	return searchstr(word, target, pos + target.length());
}

int main() {
	string word, target; cin >> word >> target;
	cout << searchstr(word, target, 0);
}