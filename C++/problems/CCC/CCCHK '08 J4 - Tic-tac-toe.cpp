#include <iostream>
#include <string>
using namespace std;

//CCCHK '08 J4 - Tic-tac-toe
//https://dmoj.ca/problem/hkccc08j4
//1-13-2025

bool isvalid(string input) {
	int xs = 0, os = 0;
	for (int k = 0; k < input.length(); k++) {
		if (input.at(k) == 'X') {
			xs++;
		}
		if (input.at(k) == 'O') {
			os++;
		}
	}
	if (!(xs - os == 0 || xs - os == 1) ) return false;
	if (os > xs) return false;
	bool oWins = false;
	bool xWins = false;
	//vertical win
	for (int k = 0; k < 3; k++) {
		if (input.at(k) == input.at(k + 3) && input.at(k + 3) == input.at(k + 6) && input.at(k) == 'O') oWins = true;
		if (input.at(k) == input.at(k + 3) && input.at(k + 3) == input.at(k + 6) && input.at(k) == 'X') xWins = true;
	}
	//horizontal win
	for (int k = 0; k <= 6; k+=3) {
		if (input.at(k) == input.at(k + 1) && input.at(k + 1) == input.at(k + 2) && input.at(k) == 'O') oWins = true;
		if (input.at(k) == input.at(k + 1) && input.at(k + 1) == input.at(k + 2) && input.at(k) == 'X') xWins = true;
	}
	//diagonals
	if (input.at(0) == input.at(4) && input.at(4) == input.at(8) && input.at(8) == 'O') oWins = true;
	if (input.at(2) == input.at(4) && input.at(4) == input.at(6) && input.at(6) == 'O') oWins = true;
	if (input.at(0) == input.at(4) && input.at(4) == input.at(8) && input.at(8) == 'X') xWins = true;
	if (input.at(2) == input.at(4) && input.at(4) == input.at(6) && input.at(6) == 'X') xWins = true;

	if (oWins && xs != os) return false;
	if (xWins && xs != os + 1) return false;
	if (oWins && xWins) {
		return false;
	}
	return true;
}

int main() {
	int n; cin >> n;
	for (int k = 0; k < n; k++) {
		string input; cin >> input;
		cout << (isvalid(input) ? "yes" : "no") << endl;
	}
}