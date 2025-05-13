#include <iostream>
using namespace std;

//CCC '19 S1 - Flipper
//https://dmoj.ca/problem/ccc19s1
//3-24-2025

int main() {
	string input; cin >> input;
	int Hcount = 0, Vcount = 0;
	for (char c : input) {
		if (c == 'H') Hcount++;
		if (c == 'V') Vcount++;
	}
	Hcount %= 2; Vcount %= 2;
	switch (10 * Hcount + Vcount) {
	case 0:
		cout << "1 2\n3 4"; break;
	case 1:
		cout << "2 1\n4 3"; break;
	case 10:
		cout << "3 4\n1 2"; break;
	case 11:
		cout << "4 3\n2 1"; break;
	}
}