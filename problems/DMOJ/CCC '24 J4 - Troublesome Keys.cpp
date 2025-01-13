#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

//CCC '24 J4 - Troublesome Keys
//https://dmoj.ca/problem/ccc24j4
//1-12-2025

int main() {
	string str1, str2; cin >> str1 >> str2;
	char sillyto = '-';
	unordered_set<char> chars1;
	for (int k = 0; k < str1.length(); k++) {
		chars1.insert(str1.at(k));
	}
	unordered_set<char> chars2 = chars1;
	for (int k = 0; k < str2.length(); k++) {
		if (chars1.count(str2.at(k)) > 0) {
			chars2.erase(str2.at(k)); //remove similar
		}
		else {
			//if str2 has a character str1 doesnt have then that character is the sillykey
			sillyto = str2.at(k);
		}
	}

	//remaining characters are possible silly characters
	//one of them is quiet and one of them is silly
	vector<char> replacetest;
	replacetest.insert(replacetest.end(), chars2.begin(), chars2.end());

	if (replacetest.size() == 1) {
		cout << replacetest.at(0) << " " << sillyto << endl << "-";
	}
	else {
		for (int k = 0; k < str1.length(); k++) {
			if (str1.at(k) == replacetest.at(0)) {
				str1.at(k) = sillyto;
			}
			if (str1.at(k) == replacetest.at(1)) {
				str1.erase(k);
				k--;
			}
		}
		if (str1 == str2) {
			cout << replacetest.at(0) << " " << sillyto << endl << replacetest.at(1);
		}
		else {
			cout << replacetest.at(1) << " " << sillyto << endl << replacetest.at(0);
		}
	}
}