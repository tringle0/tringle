#include <iostream>
using namespace std;

//CCC '00 S1 - Slot Machines
//https://dmoj.ca/problem/ccc00s1
//2-24-2025

int main() {
	int n; cin >> n;
	int a, b, c; cin >> a >> b >> c;
	int counter = 0;
	while (true) {
		if (a++ == 35) {
			n += 30; a = 1;
		}
		if (n-- <= 0) break;
		counter++;
		if (b++ == 100) {
			n += 60; b = 1;
		}
		if (n--<= 0) break;
		counter++;
		if (c++ == 10) {
			n += 9; c = 1;
		}
		if (n-- <= 0) break;
		counter++;
	}
	cout << "Martha plays " << counter << " times before going broke.";	
}