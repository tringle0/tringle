#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

//CCC '24 J4 - Troublesome Keys
//https://dmoj.ca/problem/ccc24j4
//1-12-2025

int main() {
	string str1, str2; cin >> str1 >> str2;
	int lengthdif = str1.length() - str2.length();
	char sillyto = '-';
	unordered_set<char> chars;
	unordered_map<char, int> charcount;
	for (int k = 0; k < str1.length(); k++) {
		chars.insert(str1.at(k));
		charcount[str1.at(k)]++;
	}
	vector<char> uniques;
	uniques.insert(uniques.end(), chars.begin(), chars.end());
	//remove chars and check if same length
	for (int k = 0; k < uniques.size(); k++) {
		if (charcount[uniques.at(k)] == lengthdif) {
			cout << uniques.at(k) << endl;
			string teststr = str1;
			//remove quiet key
			for (int i = 0; i < teststr.size(); i++) {
				if (teststr.at(i) == uniques.at(k)) {
					teststr.erase(i, 1);
				}
				
			}
			cout << "str: " << teststr << endl;
			//find silly key
			char sillyfrom = '-', sillyto = '-';
			for (int k = 0; k < teststr.size(); k++) {
				if (teststr.at(k) != str2.at(k)) {
					if (sillyfrom == '-') {
						sillyfrom = teststr.at(k);
						sillyto = str2.at(k);
						break;
					}
				}
			}
			cout << sillyfrom << " " << sillyto << endl;

			if (sillyfrom != '-') {
				//apply silly key
				for (int k = 0; k < teststr.size(); k++) {
					if (teststr.at(k) == sillyfrom) {
						teststr.at(k) = sillyto;
					}
				}
				//check strings
				if (teststr == str2) {
					cout << "found\n";
					cout << sillyfrom << " " << sillyto << endl;
					cout << uniques.at(k);
					break;
				}
			}
		}
	}
}