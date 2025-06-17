#include <iostream>
using namespace std;

//CCC '02 S2 - Fraction Action
//https://dmoj.ca/problem/ccc02s2
//5-13-2025

int main() {
	int numerator, denominator;
	cin >> numerator >> denominator;
	int remainder = numerator % denominator;
	int result = numerator / denominator;

	//print whole number when it is not zero
	if (result != 0) {
		cout << result;

		//print the space if it is a mixed number
		if (remainder != 0) {
			cout << " ";
		}
	}
	
	//fraction part of mixed number
	if (remainder != 0) {

		//simplify fraction
		for (int k = 1; k <= denominator; k++) {
			if (remainder % k == 0 && denominator % k == 0) {
				remainder /= k;
				denominator /= k;
			}
		}
		cout << remainder << "/" << denominator;
	}
	cout << endl;
}