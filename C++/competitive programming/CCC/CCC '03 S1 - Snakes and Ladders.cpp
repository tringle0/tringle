#include <iostream>
#include <unordered_map>
using namespace std;

//CCC '03 S1 - Snakes and Ladders
//https://dmoj.ca/problem/ccc03s1
//2-24-2025

int main() {
	unordered_map<int, int> transfers = { {54,19},{90,48},{99,77},{9,34},{40,64},{67,86} };
	int currentsquare = 1;
	while (true) {
		int step; cin >> step;
		if (step == 0 || step > 12) {
			cout << "You Quit!";
			return 0;
		}
		if(currentsquare + step <= 100) currentsquare += step;
		if (transfers.count(currentsquare) > 0) currentsquare = transfers[currentsquare];
		cout << "You are now on square " << currentsquare << endl;
		if (currentsquare == 100) break;
	}
	cout << "You Win!";
}