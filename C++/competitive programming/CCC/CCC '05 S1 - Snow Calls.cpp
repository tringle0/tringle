#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

//CCC '05 S1 - Snow Calls
//https://dmoj.ca/problem/ccc05s1
//2-20-2025

int main() {
	unordered_map<char, char> phone = {
		{'A', '2'}, {'B', '2'}, {'C', '2'},
		{'D', '3'}, {'E', '3'}, {'F', '3'},
		{'G', '4'}, {'H', '4'}, {'I', '4'},
		{'J', '5'}, {'K', '5'}, {'L', '5'},
		{'M', '6'}, {'N', '6'}, {'O', '6'},
		{'P', '7'}, {'Q', '7'}, {'R', '7'}, {'S', '7'},
		{'T', '8'}, {'U', '8'}, {'V', '8'},
		{'W', '9'}, {'X', '9'}, {'Y', '9'}, {'Z', '9'}
	};
	int n; cin >> n;
	for (int k = 0; k < n; k++) {
		string input; cin >> input;
		string out = "";
		int curcharat = 0;
		for (int c = 0; c < input.length() && curcharat <10; c++) {
			if (input.at(c) != '-') {
				if (input.at(c) >= 'A' && input.at(c) <= 'Z')  input.at(c) = phone[input.at(c)];
				out += input.at(c);
				if (curcharat == 2 || curcharat == 5) out += '-';
				curcharat++;
			}
			
		}
		cout << out << endl;
	}
}