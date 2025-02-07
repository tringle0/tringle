	#include <iostream>
	#include <string>
	using namespace std;

	//CCC '05 J5 - Bananas
	//https://dmoj.ca/problem/ccc05j5
	//2-7-2025

	bool check(string& input) {
		int Bs = 0; char last = 0;
		for (char k : input) {
			if (k == 'B') Bs++;
			if (k > 0) {
				if (k == 'N' && (last == 'B' || last == 'N')) return false;
				if (k == 'S' && (last == 'B' || Bs == 0)) return false;
			}
			last = k;
		}
		return true;
	}

	int main() {
		string input;
		while (true) {
			cin >> input;
			if (input == "X") break;
			cout << (check(input) ? "YES\n" : "NO\n");
			
			
		}
	}