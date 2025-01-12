#include <iostream>
using namespace std;

//CCC '10 J2 - Up and Down
//1-11-2025

int main() {
	int a, b, c, d, steps; cin >> a >> b >> c >> d >> steps;
	int intervalN = a + b, stepsPerIntervalN = a - b;
	int intervalB = c + d, stepsPerInvervalB = c - d;

	int remainingN = steps % intervalN;
	int posN = steps / intervalN * stepsPerIntervalN;
	if (remainingN > a) {
		posN += a - (remainingN-a);
	}
	else {
		posN += remainingN;
	}

	int remainingB = steps % intervalB;
	int posB = steps / intervalB * stepsPerInvervalB;
	if (remainingB > c) {
		posB += c - (remainingB - c);
	}
	else {
		posB += remainingB;
	}

	if (posN == posB) {
		cout << "Tied";
	}
	else {
		cout << (posN > posB ? "Nikky" : "Byron");
	}
}